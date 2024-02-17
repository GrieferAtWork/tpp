
#include "mywrapper-for-tpp.h"
/**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define ERROR_HANDLING fatal(__LINE__)
static void fatal(int line) {
	/* Should probably do "TPP_FINALIZE()", unless error was caused by "TPP_INITIALIZE()" */
	fprintf(stderr, "%d: something went horribly wrong\n", line);
	exit(1);
}


int main() {
	/* Initialization */
	if (!TPP_INITIALIZE())
		ERROR_HANDLING;

	/* Configure `TPPLexer_Current' to your liking */
	// TPPLexer_Current->l_flags    = ...;
	// TPPLexer_Current->l_extokens = ...;

	/* -DMY_MACRO=42 */
	char const *name = "MY_MACRO";
	char const *val  = "42";
	if (!TPPLexer_Define(name, strlen(name), val, strlen(val),
	                     TPPLEXER_DEFINE_FLAG_NONE))
		ERROR_HANDLING;

	/* -I/usr/include */
	char incpath[] = "/usr/include"; // Must be writable; use strdup() when in doubt
	if (!TPPLexer_AddIncludePath(incpath, strlen(incpath)))
		ERROR_HANDLING;

	/* Push an initial file onto the #include-stack */
	char const *filename = "input.c";
	struct TPPFile *file = TPPLexer_OpenFile(TPPLEXER_OPENFILE_MODE_NORMAL |
	                                         TPPLEXER_OPENFILE_FLAG_CONSTNAME,
	                                         (char *)filename, strlen(filename),
	                                         NULL);
	if (!file)
		ERROR_HANDLING;
	TPPLexer_PushFile(file);

	/* Process input one token at a time.
	 * Hint: emission of certain tokens depends on `TPPLEXER_FLAG_WANT*' and `TPPLEXER_TOKEN_*' */
	while (TPPLexer_Yield() > 0) {
		int id = TPPLexer_Current->l_token.t_id;
		char *tokstr = TPPLexer_Current->l_token.t_begin;
		size_t toklen = (size_t)(TPPLexer_Current->l_token.t_end - tokstr);
		struct TPPLCInfo lc;
		struct TPPFile *f = TPPLexer_Textfile();
		struct TPPFile *current = TPPLexer_GetFile();
		char *f_ptr = current == f ? tokstr : f->f_pos;
		TPPFile_LCAt(f, &lc, f_ptr);
		printf("%s:%d:%d: %d: '%.*s'", TPPFile_Filename(f, NULL),
		       (int)lc.lc_line + 1, (int)lc.lc_col + 1,
		       id, (int)toklen, tokstr);
		if (current != f) {
			struct TPPFile *mac = current;
			while (mac != f && mac->f_kind != TPPFILE_KIND_MACRO)
				mac = mac->f_prev;
			if (mac != f) {
				struct TPPLCInfo mac_lc;
				TPPFile_LCAt(mac, &mac_lc, current == mac ? tokstr : mac->f_pos);
				printf(" [in macro '%.*s' at %s:%d:%d]",
				       (int)mac->f_namesize, mac->f_name, TPPFile_Filename(mac, NULL),
				       (int)mac_lc.lc_line + 1, (int)mac_lc.lc_col + 1);
			}
		}
		putchar('\n');
	}

	/* Check if something went wrong (stuff like `#error' directives, or syntax errors) */
	if ((TPPLexer_Current->l_flags & TPPLEXER_FLAG_ERROR) ||
	    (TPPLexer_Current->l_errorcount != 0))
		ERROR_HANDLING;

	/* Cleanup the lexer (must be called after successful a `TPPLexer_Init()') */
	TPP_FINALIZE();
	return 0;
}
