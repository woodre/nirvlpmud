/*  Changed to barterable item 8/17/02 - Eurale  */

#define tpn this_player()->query_name()  /* player name  */
#define ETP environment(this_player())
#include "/players/eurale/closed/ansi.h"
inherit "obj/treasure";

reset(arg) {
  if(arg) return;
set_id("eye");
set_alias("raptor eye");
set_short(BOLD+"bulging raptor eye"+NORM);
set_long(
  "This is the eye from a fearsome raptor.  It is valued by many for medicinal\n"+
  "purposes and is a valuable barter object.\n");

set_value(1100);
set_weight(1);
set_save_flag();
  }


init() {
  ::init();
  add_action("Barter","barter");
}

Barter(str) {
int num;
if(!str) { write("Barter what?\n"); return 1; }
if(str == "eye" || str == "raptor eye") {
if(!present("madame rue",ETP)) { write("What?\n"); return 1; }
  num = 4750 + random(500);
  write("Madame Rue cackles loudly....\n"+
        "She quickly hands you "+num+" coins and hides her treasure.\n");
  this_player()->add_money(num);
  destruct(this_object());
  return 1; }
}
