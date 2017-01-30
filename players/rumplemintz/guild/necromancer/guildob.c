/*
 * Rumplemintz Necromancer guild object
 */

#define BIN "/players/rumplemintz/guild/necromancer/bin/"

void reset(int arg) {
  if (arg)
    return;
}

int id(string str) {
  return str == "guildob" ||
         str == "necromancer_ob";
}

string short() {
  return "";
}

int get() {
  return 1;
}

int drop() {
  return 1;
}

int command_hook(string str) {
  return BIN+query_verb()->query_verb(str);
}

void init() {
  int i;
  string *t;

  if (!environment() ||
      environment(this_object()) != this_player() )
    return;
  i = sizeof(t = get_dir(BIN + "*.c"));
  while(i--)
#ifndef __LDMUD__
	add_action("command_hook", t[i][0..-3]);
#else
        add_action("command_hook", t[i][0..<3]);
#endif
}
