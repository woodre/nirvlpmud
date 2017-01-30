inherit "obj/monster";
#include "/players/beck/MortalKombat/MKQuestNPC.h"
reset(arg){
   object gold,ob1;
   ::reset(arg);
   if(arg) return;
   set_name("hannibal");
   set_race("human");
   set_short("Hannibal");
 set_long("This is a warrior trying to pass the alps to go to fight Caesar.\n");
   set_level(19);
   set_hp(475);
   set_al(-100);
   set_wc(28);
   set_ac(16);
   gold=clone_object("obj/money");
   gold->set_money(1900 + random(200));
   move_object(gold,this_object());
  move_object(clone_object("/players/dragnar/MKScar/scar"),this_object());
}
