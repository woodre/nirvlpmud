#include "defs.h"

void reset(status arg) { return; }
status id(string arg) { return (arg == "seal" || arg == "masonic seal"); }
string short() { return "Masonic Seal"; }
void long() { write("This give all the mason mini-guild commands.\n"); }
status get() { return 1; }
status drop() { return 1; }

void init() {
  int i;
  string *files;

  files = get_dir(BIN+"*.c");
  i = sizeof(files);
  while (i--)
    add_action("command_hook", files[i]);
}

status command_hook(string arg) {
  string verb;

  verb = query_verb();
  return (int)call_other(BIN+verb, "main", arg);