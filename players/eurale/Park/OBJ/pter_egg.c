/* Changed to barterable item 8/17/02 - Eurale  */

#define tpn this_player()->query_name()  /* player name  */
#define ETP environment(this_player())
#include "/players/eurale/closed/ansi.h"
inherit "obj/treasure";

reset(arg) {
  if(arg) return;

set_id("egg");
set_alias("pteranodon egg");
set_short(HIW+"huge pteranodon egg"+NORM);
set_long(
  "This is the egg of the giant pteranodon.  It is approximately 18 inches\n"+
  "long and 25 inches in circumference.  Barterers everywhere value this\n"+
  "unique item.\n");

set_weight(3);
set_value(1500);
set_save_flag();
}

init() {
  ::init();
  add_action("Barter","barter");
}

Barter(str) {
int num;
if(!str) { write("Barter what?\n"); return 1; }
if(str == "egg" && present("sedjak",ETP) || present("madame rue",ETP)) {
  num = 4800 + random(400);
  write("You barter with the rare and precious egg and receive "+num+
    "\ncoins for your trouble.\n");
  this_player()->add_money(num);
  destruct(this_object());
  return 1; }
}
