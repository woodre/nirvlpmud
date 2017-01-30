inherit "/obj/monster.c";
#include "/obj/ansi.h"
/* changed to standard ansi.h -mizan */
#define tpn this_player()->query_name()

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("babau");
  set_race("demon");
  set_short(BOLD+GRN+"A Babau"+NORM);
  set_long(
    "    Reeking of decay, this gaunt humanoid is covered in\n"+
    "black, leathery skin.  Behind its pointed ears, a large\n"+
    "curved horn rises out of the back of its skull. A mouth\n"+
    "of jagged teeth takes up half of the foul creatures's\n"+
    "head.\n");
  
  add_money(2100);
  set_level(17);
  set_hp(450);
  set_al(-800);
  set_ac(15);
  set_wc(25);
  set_aggressive(0);
  set_armor_params("other|evil",0,5,0);
  set_armor_params("other|fire",0,5,0);
  set_armor_params("other|electric",0,5,0);
  set_armor_params("other|good",0,-5,0);
}
