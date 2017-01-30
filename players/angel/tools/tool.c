#include "defs.h"

void reset(status arg) { return; }
status id(string arg) { return (arg == "tool" || arg == "wiztool"); }
string short() { return "Earwax's Generic WizTool"; }
void long() { write("You can 'tell' 'retell' and 'reply' using this.\n"); }
status get() { return 1; }
status drop() { return 1; }

void init() {
  int i;
  string *files;

  files = get_dir(BIN+"*.c");
  i = sizeof(files);
  while (i--)
#ifndef __LDMUD__ /* Rumplemintz */
    add_action("command_hook", files[i][0..-3]);
#else
    add_action("command_hook", files[i][0..<3]);
#endif
}

status command_hook(string arg) {
  string verb;

  verb = query_verb();
  return (int)call_other(BIN+verb, "main", arg);
}
