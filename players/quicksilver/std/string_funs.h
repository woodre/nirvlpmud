#define STRING_FUN_OBJ "players/quicksilver/lib/string_funs.c"

/* string functions-- ~/lib/string_funs.c */
remove_color(string text) { return STRING_FUN_OBJ->remove_color(text); }
ansi_strlen(string arg) { return strlen(remove_color(arg)); }
lalign(string text, int field) { return STRING_FUN_OBJ->ralign(text, field); }
ralign(string text, int field) { return STRING_FUN_OBJ->ralign(text, field); }
center(string text, int field) { return STRING_FUN_OBJ->center(text, field); }
line_wrap(string text, int hangident, int length) { return STRING_FUN_OBJ->line_wrap(text, hangident, length); }