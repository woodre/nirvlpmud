/* fangs converter to new vamp guild object */

#include "/players/eurale/defs.h"
int i;

reset(arg) {
  if (arg) return 0;
}

query_auto_load() { return "/players/eurale/VAMPIRES/changefangs.c:"; }

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
/*  remove them from the vampire list  */
  call_other(MEMBER,"???",0);
  call_other(MEMBER,"delete_player",TPRN);
  i = this_player()->query_guild_exp();
  TP->add_guild_exp(-i);
  TP->set_guild_name(0);
  TP->set_guild_file(0);
  TP->set_title("--> former member of the Vampire Guild");
  TP->set_home("/room/church.c");
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
  "             will be reset to that of a new vampire and you will be\n"+
  "             expected to go through the vampire trials to advance in\n"+
  "             the new guild.\n");
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
