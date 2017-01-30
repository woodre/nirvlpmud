#include "/players/fred/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;
   
set_name("eddie");
set_race("human");
set_short(BOLD+BLK+"CrAzy"+NORM+BOLD+" Eddie"+NORM);
set_long(
  " Eddie is a short little guy wearing an old suit gray suit, some\n"+
  "very stylish flippers and a rubber boot on his head. He obviously\n"+
  "isn't the brightest guy but he's good at his job.\n");
 
set_level(30);
set_hp(750);
set_al(1000);
set_ac(27);
set_wc(40);
set_aggressive(0);
}




