#include "/players/fakir/color.h"
inherit "obj/monster";
reset(arg)  {
  object armor;
  ::reset(arg);
  if(arg) return;
  set_name("ballindrok");
  set_alias("rok");
  set_race("creature");
  set_short("A"+BROWN+" Ballindorok"+OFF);
  set_long(
"Roughly the size of a small boulder and having the same general appearence,\n"+
"this creature is stuck fast to the ground.  Without any means of protection\n"+
"other than its rocklike shell, it has survived many turnings of the wheel of\n"+
"time...no small feat in the boarderlands.\n");


  set_hp(545);
  set_level(15);
  set_al(-200);
  set_wc(12);
  set_ac(20);
  set_aggressive(0);
armor=clone_object("/players/fakir/inn/ARM/rok.c");
move_object(armor,this_object());
  
 }
