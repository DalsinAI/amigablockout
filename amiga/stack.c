/* A Shell gives 4 KB of stack; libnix's startup sets this much up instead.
 * The AmiCradle Team. GPL 2 or later, like BlockOut II. */
unsigned long __stack = 512 * 1024;
static const char version[] __attribute__((used)) = "$VER: BlockOut II 2.5 Amiga (06.11.2026)";
