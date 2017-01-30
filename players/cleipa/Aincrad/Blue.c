#include <ansi.h>"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;
   
set_name("Blue Cobald Lord");
set_race("lord");
set_short("Blue Cobald Lord");
set_long(
  " He is the lord of all cobalds in existance. You noticed he has a weapon strapped to his back.\n"+
  "It looks like a regular katana at first, but then you notice that it is a nodachi. You wonder to \n"+
  "yourself what could that be for? Guess you need to fight to find out.\n");
 
set_level(40);
set_hp(50000);
set_al(-1000);
set_ac(45);
set_wc(45);
set_aggressive(0);
}