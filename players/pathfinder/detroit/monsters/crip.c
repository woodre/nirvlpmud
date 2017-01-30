inherit "obj/monster";
 
reset(arg){
   object gold,armor,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("crip");
   set_race("human");
   set_alias("gang");
   set_alias("elder");
   set_short("An elder of the Crips");
   set_long("\n"+
"  A member of the Crips gang.  He grew up round these parts and will take\n"+
"ya on if ya steps on his turf.  Oops... look at whatcha done...  now yer\n"+
"gonna die.\n");
   set_level(18);
   set_hp(300+random(350));
   set_al(-500);
   set_wc(30);
   set_ac(17+random(12));
   set_chance(20);
   set_aggressive(1);
   set_spell_dam(9+random(12));
   set_spell_mess1("Crip impales you with the impact of the machete!\n");
   set_spell_mess2("Crip spits on you.\n");
   set_chat_chance(2);
   load_chat("Crip tells you: You stepped on my turf, now yer gonna die!");
   gold=clone_object("obj/money");
   gold->set_money(random(300)+500);
   move_object(gold,this_object());
   move_object(clone_object("players/pathfinder/detroit/weapons/machete"), this_object());
}

#include "/players/mythos/amon/hb_ag.h"
