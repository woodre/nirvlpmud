#include "/players/maledicta/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object anhk;
  ::reset(arg);
  if(arg) return;

set_name("guard");
set_alias("student_guard");
switch(random(3) + 1){
case 3: 
set_race("human"); 
set_short(HIW+"Tower "+HIR+"Guard ["+HIW+"Human"+HIR+"]"+NORM);
break;
case 2: 
set_race("elf");   
set_short(HIW+"Tower "+HIG+"Guard ["+HIW+"Elf"+HIG+"]"+NORM);
break;
case 1: 
set_race("dwarf"); 
set_short(HIW+"Tower "+HIM+"Guard ["+HIW+"Dwarf"+HIM+"]"+NORM);
break;
}

set_long(
  "This is a proud guard of the Warrior Tower. He is dressed in\n"+
  "a beautiful set of white polished armor with several types\n"+
  "of weapons strapped across his back and waist.  A long polearm\n"+
  "is held in his left hand with a small round shield strapped on\n"+
  "to his right. This guard has been stationed here to prevent\n"+
  "unauthorized entry into parts of the tower that are offlimits.\n");
set_level(10);
set_hp(650);
set_al(0);
set_wc(32);
set_ac(10);
set_aggressive(0);
set_chat_chance(5);
  load_chat("Guard watches you closely.\n");
  load_chat("Guard stands by and watches for trouble.\n");
}  

