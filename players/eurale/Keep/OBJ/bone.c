/* Values changed due to upgrade in level of the monster
completed by Pestilence per Dragnar 8-9-2014 */
#define TP this_player()
#define ETP environment(this_player())
#include "/players/eurale/closed/ansi.h"
inherit "obj/weapon.c";
int num;

reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("bone sliver");
set_alias("bone");
set_alt_name("sliver");
set_short(GRN+"Slimey bone sliver"+NORM);
set_long(
  "This long, slender bone sliver is coated with some sort of green thick\n"+
  "liquid that smells putrid.  It is rumored that strong potions are\n"+
  "made from this item and it could be 'bartered' for a large sum.\n");

set_type("knife");  /*  sword/knife/club/axe/bow/polearm  */
set_class(2);
  set_weight(1);
  set_value(3);
}

init() {
  ::init();
  add_action("Barter","barter");
}

Barter(str) {
num = 8500 + random(900);
if(!str || !present("madame rue",ETP)) { write("What?\n"); return 1; }
if(str == "bone" || str == "sliver") {
  write("Madame Rue takes the bone sliver and cackles....\n"+
  "She thanks you and gives you "+num+" coins for your heroic effort.\n");
  say("Madame Rue cackles and hides the bone sliver.\n");
  TP->add_money(num);
  destruct(this_object());
  return 1; }
return 1;
}
