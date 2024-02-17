/* Custom keywords (but be careful not to re-define ones already defined by TPP)
 * When parsed, you can check for these keywords like:
 * >> switch (TPPLexer_Current->l_token.t_id) {
 * >> case KWD_async:
 * >>     ...;
 * >>     break;
 * >> case KWD_function:
 * >>     ...;
 * >>     break;
 * >> }
 *  */
DEF_K(async)
DEF_K(function)
DEF_K(def)
DEF_K(awesome_keyword)

/* These you would probably replace with something else... */
#define should_be_defined  1
#define enabled_by_default 1

/* A pre-defined macro (as in `#ifdef __MY_PREDEFINED_MACRO__')
 * This should be used for stuff like `__GNUC__' or `__cplusplus', etc... */
PREDEFINED_MACRO_IF(__MY_PREDEFINED_MACRO__, "42", should_be_defined ? 1 : 0)

/* Custom warnings groups. (see "tpp-defs.inl" for the default groups)
 * Warnings can be enabled/disabled on a per-group basis by parsed text:
 * >> #pragma warning("-Wmygroup")    // Enable
 * >> #pragma warning("-Wno-mygroup") // Disable
 * >> #pragma GCC diagnostic error "-Wmygroup"
 * >> #pragma GCC diagnostic warning "-Wmygroup"
 * >> #pragma GCC diagnostic ignored "-Wmygroup"
 */
WGROUP(WG_MYGROUP, "mygroup", WSTATE_FATAL) // Warnings controlled by "-Wmygroup" / "-Wno-mygroup" / ...

/* Custom warnings.
 * Your compiler would trigger this like (note: it's a varargs function):
 * >> if (!TPPLexer_Warn(W_MYWARNING, "first variable argument"))
 * >>     HANDLE_AS_CRITICAL_ERROR;
 * >> TRY_TO_CONTINUE_COMPILING;
 */
DEF_WARNING(W_MYWARNING, (WG_MYGROUP, WG_SYNTAX), WSTATE_ERROR, {
	char *mesg = ARG(char *);
	WARNF("My warning handler: %s", mesg);
})

/* Custom extension. Input code can enable/disable this by:
 * >> #pragma extension("-fawesome")    // Turn on
 * >> #pragma extension("-fno-awesome") // Turn off
 * Your compiler can check if it's enabled with `TPPLexer_HasExtension(EXT_AWESOME)' */
EXTENSION(EXT_AWESOME, "awesome", enabled_by_default ? 1 : 0)
