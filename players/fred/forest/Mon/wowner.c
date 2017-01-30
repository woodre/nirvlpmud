#include "/players/fred/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;
   
set_name("brenner");
set_race("human");
set_short(BLU+"Brenner"+NORM+", the weaponsmith");
set_long(
  " Brenner is running back and forth making weapons. As\n"+
  "you look at him he looks up with a smile.  Several of\n"+
  "his teeth are missing and others are close to falling out.\n");
 
set_level(30);
set_hp(750);
set_al(1000);
set_ac(27);
set_wc(40);
set_aggressive(0);
}




