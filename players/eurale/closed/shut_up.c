#define TP this_player()
#define ETO environment(this_object())
#define TO this_object()
#include "/players/eurale/closed/ansi.h"

id(str) { return str == "dryice"; }

init() {
#ifndef __LDMUD__ /* Rumplemintz */
  add_action("trap_command"); add_xverb("");
#else
  add_action("trap_command", "", 3);
#endif
}

query_auto_load() { return "/players/eurale/closed/shut_up.c:"; }

trap_command(str) {
if(!TP) return;
if(!this_player()) return;
if(TP != ETO) return;
if(str == "quit") { TP->quit(); return 1; }
write(HIC+
  "You have been frozen because of your inappropriate behavior..\n"+
  "Your only option is to 'quit' and pray for forgiveness...\n"+NORM);
return 1; }

get() { return 1; }
drop() { return 1; }
