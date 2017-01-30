inherit "obj/monster";
#include "/players/beck/rangers/Defs.h"

reset(arg)
{
   object gold, weapon;
   ::reset(arg);
   if(arg) return;
   set_name("Soccadillo");
   set_alias("soccadillo");
   set_short("The Soccadillo");
   set_long("The Soccadillo is one of Rita's evil creatures, created to be\n"+
      "half soccerball half armadillo.\n"+
      "The soccadillo can roll up into a ball and is heavily armored.\n"+
      "Beware of playing with this guy.\n"+
      "");
   set_level(20);
   set_hp(500);
   set_wc(25);
   set_ac(25);
   set_al(-500);
   set_aggressive(0);
   set_chance(25);
   set_spell_dam(18);
   set_spell_mess2("The Soccadillo rolls right over you!\n");
   set_chat_chance(3);
   load_chat("The Soccadillo says: Hey Power Rangers...Wanna PLAY?\n");
   gold=clone_object("obj/money");
   gold->set_money(random(1000) + 4000);
   move_object(gold, this_object());
   MASTER->AddRanger("all",TO);
   set_dead_ob(TO);
}
custom_clean(){
   MASTER->RemoveRanger("all",TO);
   return 0;
}
monster_died(){
   MASTER->RemoveRanger("all",TO);
   return 0;
}
