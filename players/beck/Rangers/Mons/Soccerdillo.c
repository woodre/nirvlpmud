inherit "obj/monster";
#include "/players/beck/Defs.h"
#include "/players/beck/Rangers/RangerDefs.h"

reset(arg)
{
   object gold, weapon, watch;
   ::reset(arg);
   if(arg) return;
   set_name("Soccerdillo");
   set_alias("soccerdillo");
   set_short("The Soccerdillo");
   set_long("The Soccerdillo is one of Rita's evil creatures, created to be\n"+
      "half soccerball half armadillo.\n"+
      "The soccerdillo can roll up into a ball and is heavily armored.\n"+
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
   set_spell_mess2("The Soccerdillo rolls right over you!\n");
   set_chat_chance(3);
   load_chat("The Soccerdillo says: Hey Power Rangers...Wanna PLAY?\n");
   gold=clone_object("obj/money");
   gold->set_money(random(1000) + 4000);
   move_object(gold, this_object());
   set_race("RangerMonster");
   if(!present("DarkRangerCommunicator", this_object())){
      watch=clone_object("/players/beck/Rangers/DarkRangers/DarkRangerCommunicator.c");
      watch->init();
      watch->init_arg();
      move_object(watch, this_object());
   }   
   set_dead_ob(TO);
}

