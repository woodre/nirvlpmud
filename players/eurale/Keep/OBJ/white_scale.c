/* Values changed due to upgrade in level of the monster
completed by Pestilence per Dragnar 8-9-2014 */
#define TP this_player()
#define ETP environment(this_player())
#include "/players/eurale/closed/ansi.h"
inherit "obj/armor";

reset(arg) {
set_name("dragon scale");
set_alias("scale");
set_short(HIW+"White dragon scale"+NORM);
set_long(
  "This irridescent white scale comes from the illusive and powerful\n"+
  "white dragon which is believed to be extinct.  It has been told\n"+
  "that the white scale makes an almost perfect shield and because\n"+
  "of its rarity, it is worth a great deal if 'bartered'.\n");

set_ac(2);
set_type("shield");  /* armor,helmet,boots,ring,amulet,shield,misc  */
set_weight(3);
set_value(4700);
}

init() {
  ::init();
  add_action("Barter","barter");
}

Barter(str) {
int num;
if(!str || !present("sedjak",ETP)) { write("What?\n"); return 1; }
if(str == "scale" || str == "dragon scale") {
  num = (8000 + random(1500));
  say("Sedjak quickly hides something in his trunk.\n");
  write("You hand the dragon scale to Sedjak and pocket the "+num+" coins he "+
        "gives you.\n");
  TP->add_money(num);
  destruct(this_object());
  return 1; }
}
