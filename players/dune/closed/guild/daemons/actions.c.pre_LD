/*
 * Actions daemon modified from (c) Balowski/Rasmus, Late April 1995.
 * The mapping is used in a "command hook" construct
 */
#include "../DEFS.h"
#define DISGRACE_FREEZE ({"nem", "net", "line", "gwho", "elate"})

static mapping genCmds, advCmds, admCmds, tools, emotes, base;

id(str) { return str == "actions"; }

void reset(int arg) {
    int         i;
    string      *f, cmd;

    if (arg) return;

    /* normal guild commands */
    i = sizeof(f = files(LIB_GENCMDS + "*.c"));
    genCmds = allocate_mapping(i);
    while (i--) {
	sscanf(f[i], "%s.c", cmd);
	genCmds[cmd] = LIB_GENCMDS + cmd; }

    /* advanced guild commands */
    i = sizeof(f = files(LIB_ADVCMDS + "*.c"));
    advCmds = allocate_mapping(i);
    while (i--) {
	sscanf(f[i], "%s.c", cmd);
	advCmds[cmd] = LIB_ADVCMDS + cmd; }

    /* administrative commands */
    i = sizeof(f = files(LIB_ADMCMDS + "*.c"));
    admCmds = allocate_mapping(i);
    while (i--) {
	sscanf(f[i], "%s.c", cmd);
	admCmds[cmd] = LIB_ADMCMDS + cmd; }

    /* enhancement commands */
    i = sizeof(f = files(LIB_TOOLS + "*.c"));
    tools = allocate_mapping(i);
    while (i--) {
	sscanf(f[i], "%s.c", cmd);
	tools[cmd] = LIB_TOOLS + cmd; }

    /* emotes */
    i = sizeof(f = files(LIB_EMOTES + "*.c"));
    emotes = allocate_mapping(i);
    while (i--) {
	sscanf(f[i], "%s.c", cmd);
	emotes[cmd] = LIB_EMOTES + cmd; }


    /* limited commands for low honor */
    i = sizeof(f = DISGRACE_FREEZE);
    base = allocate_mapping(i);
    while (i--)
	base[f[i]] = genCmds[f[i]];
}


mapping query_genCmds() { return genCmds;   }
mapping query_advCmds() { return advCmds;   }
mapping query_admCmds() { return admCmds;   }
mapping query_tools()   { return tools;  }
mapping query_emotes()  { return emotes; }
mapping query_base()    { return base;   }


void rehash() {
    int         i;
    string      *f, cmd;

    /* normal guild commands */
    i = sizeof( f = files(LIB_GENCMDS + "*.c"));
    while (i--) {
	sscanf(f[i], "%s.c", cmd);
	genCmds[cmd] = LIB_GENCMDS + f[i]; }

    /* advanced guild commands */
    i = sizeof( f = files(LIB_ADVCMDS + "*.c"));
    while (i--) {
	sscanf(f[i], "%s.c", cmd);
	advCmds[cmd] = LIB_ADVCMDS + f[i]; }

    /* administrative commands */
    i = sizeof( f = files(LIB_ADMCMDS + "*.c"));
    while (i--) {
	sscanf(f[i], "%s.c", cmd);
	admCmds[cmd] = LIB_ADMCMDS + f[i]; }

    /* enhancement commands */
    i = sizeof( f = files(LIB_TOOLS + "*.c"));
    while (i--) {
	sscanf(f[i], "%s.c", cmd);
	tools[cmd] = LIB_TOOLS + f[i]; }

    /* emotes */
    i = sizeof( f = files(LIB_EMOTES + "*.c"));
    while (i--) {
	sscanf(f[i], "%s.c", cmd);
	emotes[cmd] = LIB_EMOTES + f[i]; }
}
