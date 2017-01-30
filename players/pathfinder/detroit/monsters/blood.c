inherit "obj/monster";
 
reset(arg){
   object gold,armor,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("blood");
   set_race("human");
   set_alias("gang");
   set_alias("enforcer");
   set_short("An enforcer for the Bloods");
   set_long("\n"+
"  A member of the Blood's gang.  He knows these streets more than you know\n"+
"and doesn't like you messing 'round his hood.  But since yer already here\n"+
"why don't I introduce you to the barrel of my gun.\n");
   set_level(19);
   set_hp(300+random(300));
   set_al(-500);
   set_wc(25);
   set_ac(22);
   set_aggressive(1);
   set_chance(12);
   set_spell_dam(12+random(8));
   set_spell_mess1("Blood pops you in the eye with a bullet from his 9mm!\n");
   set_spell_mess2("Blood shows you the gang sign.\n");
   set_chat_chance(2);
   load_chat("Blood tells you: I dare ya to step up.\n");
   load_chat("Blood laughs in your face!\n");
   gold=clone_object("obj/money");
   gold->set_money(random(300)+500);
   move_object(gold,this_object());
   move_object(clone_object("players/pathfinder/detroit/weapons/9mm"), this_object());
   move_object(clone_object("players/pathfinder/detroit/weapons/clipb"), this_object());
   move_object(clone_object("players/pathfinder/detroit/weapons/clipb"), this_object());
}


#include "/players/mythos/amon/hb_ag.h"
