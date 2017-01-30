/*  Vampire Blood Energy Heal  */
#include "/players/eurale/defs.h"
int heal;

reset(arg) {
  if(arg) return;
}

long() { write(
  "This tiny, freeze dried blood crystal contains the blood energy of many a\n"+
  "a fallen foe.  It has been specially frozen after processing to assure\n"+
  "freshness and can be chewed for a quick pick me up.\n");
}

short() { return
  HIR+"dried blood crystal"+NORM; }

query_weight() { return 1; }

query_value() { return 250; }

query_save_flag() { return 1; }

init() {
  add_action("Chew","chew");
}

Chew(str) {
  if(str == "crystal" || str == "blood crystal") {
    if(environment() != this_player()) return;

/*  Non Vampires  */
if(!present("vampire fangs",TP)) {
  write("You chew the salty blood crystal and swallow it.\n");
  TP->heal_self(random(200));
  say(capitalize(TPRN)+" chews up the dried blood crystal and swallows it.\n");
  destruct(this_object());
  return 1; }

/* Vampire Guild Only */
  heal = (521 - TPBPTS);
  write("You chew up the "+HIR+"dried blood crystal"+NORM+" and feel refreshed.\n");
  FANGS->tell_my_room(capitalize(TPRN)+" chews up a "+HIR+
    "dried blood crystal"+NORM+" and looks refreshed.\n");
  PFANGS->add_BLOODPTS(heal);
  destruct(this_object());
  return 1; }
}

get() { return 1; }

id(str) { return str == "blood crystal" || str == "crystal"; }
