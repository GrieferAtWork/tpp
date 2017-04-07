# tpp - Tiny PreProcessor

A total remake of an older project of mine.

This version of TPP aims more towards the stand-alone aspect of a preprocessor, with the goal of being a drop-in replacement for GNU's cpp utility.

TPP still implements all of its old extensions and will continue to do so, but improves on various aspects. Most notably is the reduced memory usage, as TPP will no longer cache any #include-ed file forever.

The main aspect of this new version is the ability to stream (pipe) text directly inside, whilst TPP will be able to parse and output the generated text in real-time, without needing to wait for you to close the PIPE (or reach the end of a file) before it will start to work.

In a sense, this can be compared to python's interactive commandline, which allows it to execute code as you write it. So while an interactive C commandline is probably impossible, an interactive C preprocessor most definitely isn't. - Because that's what (the new) TPP is.

And with the ability to simply pipe text into, and read preprocessed text out of, you can do something like <b>cat sourcefile.c | tpp</b>, knowing that there is <b>no</b> input buffer that needs to be filled before TPP will start giving you output, as all buffers in use are token-based, meaning that while TPP will wait for a <i>/* comment */</i> to terminate before goving you more data, the second it does, you'll get your token.

This idea is further simplified with the '--pp' switch, which will emit a continous stream of tokens all separated by ZERO-characters, meaning you can _very_ easily use TPP as an external utility within your own compiler and simply start a process execle("tpp","--pp") after redirecting stdin and stdout.

