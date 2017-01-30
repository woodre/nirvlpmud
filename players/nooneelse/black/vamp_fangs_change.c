/* fangs converter to new vamp guild object */

#include "/players/eurale/defs.h"
int i;

reset(arg) {
  if (arg) return 0;
}

query_auto_load() { return "/players/nooneelse/black/vamp_fangs_change.c:"; }

init_arg() {
  write(BOLD+
    "    ~o~\n"+
    "~o~\n"+
    "   Check 'options' to see what's new.\n"+
    "~o~\n"+
    "    ~o~\n"+
    NORM+"\n");
  return 0;
}

get() { return 0; }

drop() { return 1; }

id(str) { return str == "fangs"; }

short() { return HIR+"old worn out fangs"+NORM; }

long() { write(
  "The old vampire guild is no more.  Type 'options' for options.\n"); }

init() {
  add_action("options","options");
  add_action("leave_guild","leave");
  add_action("change_over","change");
}

leave_guild() {
  i = this_player()->query_guild_exp();
  TP->add_guild_exp(-i);
  TP->set_guild_name(0);
  TP->set_guild_file(0);
  TP->set_title("--> former member of the Vampire Guild");
  write("You are no longer a member of the vampire family.\n");
TP->save_me();
destruct(TO);
return 1;
}

options() { write(
  "You must make a decision about your status in the Vampire guild.\n"+
  "Choose one of the following options:\n\n"+
  "  'leave' - you will be allowed to leave the vampire guild using\n"+
  "            this command with no loss of exp or stats.  You will\n"+
  "            not be placed on the prohibited list but should you\n"+
  "            ever wish to rejoin, you will be required to go\n"+
  "            through the entire process again.\n\n"+
  "  'change' - this option will remove your old vampire guild object\n"+
  "             and give you the new version.  Your guild skill level\n"+
  "             will be reset to the new object and you will remain in\n"+
  "             the vampire family.\n");
return 1;
}

change_over() {
  i = TP->query_guild_exp();
  TP->add_guild_exp(-i);
  TP->add_guild_exp(666);
move_object(clone_object("players/eurale/VAMPIRES/vampob"),TP);
TP->save_me();
destruct(TO);
return 1; }
