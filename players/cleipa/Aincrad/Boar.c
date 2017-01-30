#include <ansi.h>"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;
   
set_name("Boar");
set_race("boar");
set_short("Boar");
set_long(
  " Is an animal sitting waiting for the next person to attack it\n");
 
set_level(20);
set_hp(500);
set_al(-1000);
set_ac(20);
set_wc(25);
set_aggressive(0);
}