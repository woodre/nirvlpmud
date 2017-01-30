/*  Changed to barterable item 8/17/02 - Eurale  */

inherit "obj/armor";
#include "/open/ansi.h"
#define ETP environment(this_player())
reset(arg) {

set_name("skin");
set_alias("antrodemus skin");
set_short(GRN+"antrodemus skin"+NORM);
set_long(
  "This skin off the fearsome Antrodemus is both light and\n"+
  "protective.  It works well as both armor and treasure\n"+
  "if one were to 'barter' it.\n");

set_ac(1);
set_type("chest");
set_weight(1);
set_value(1111);
set_save_flag();
}

init() {
  ::init();
  add_action("Barter","barter");
}

Barter(str) {
int num;
if(!str) { write("Barter what?\n"); return 1; }
num = 4500 + random(400);
if(!present("sedjak",ETP)) {
  write("Barter with?\n");
  return 1; }
if(str == "skin" || str == "antro skin") { write(
  "Sedjak takes the shiney skin and grins...\n"+
  "He gives you "+num+" coins and packs it away.\n");
  this_player()->add_money(num);
  destruct(this_object());
  return 1; }
}
