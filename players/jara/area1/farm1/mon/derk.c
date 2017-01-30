/* Derk, the Farmer, Created <6/14/00> by Jara */

#include "/players/jara/misc/ansi.h"
inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

  add_money(300);
  set_name("derk");
  set_short("Derk, the Farmer");
  set_race("human");
  set_long("Derk has dark brown hair, grey at the temples, and a well-trimmed beard.\n"+
    "He wears a pair of worn overalls and his socks have several holes. His\n"+
    "dark brown eyes appear tired.\n");
  set_level(7);
  set_ac(6);
  set_wc(11);
  set_hp(105);
  set_al(0);
  set_aggressive(0);
  set_chat_chance(15);
  load_chat("Derk peers intently at you.\n");
  load_chat("Derk says, 'Is there something you want to"+HIW+" ask"+NORM+"?'\n");
  load_chat("Derk says, 'It's a shame the"+HIW+" castle"+NORM+" gates are closed.'\n");
   }
}

init() {
  ::init();
  add_action("ask","ask");
}

ask(str) {
string what;
  if(!str) { notify_fail("Ask whom about what?\n"); return 0; }
  if(sscanf(str,"derk about %s",what)!=1) { notify_fail("Ask whom about what?\n"); return 0; }
  switch(what) {
      case "castle":
      write(
    "Derk nods at you, then begins, 'The gates to the castle have been closed for\n"+
    "months now. The guards do enjoy a bottle of the local wines, though.'\n"+
    "Derk gives you a wink.\n");
  return 1;
      default:
      write("Derk says, 'Oh, I don't know much about that..'\n");
  return 1;
  }
}
