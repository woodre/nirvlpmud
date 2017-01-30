inherit "obj/monster";
#include "/players/beck/Defs.h"
#include "/players/beck/DarkRangers/RangerDefs.h"

reset(arg)
{
   object gold, helmet, watch;
   ::reset(arg);
   if(arg) return;
   set_name("Goldar");
   set_alt_name("goldar");
   set_long(""+
      "Goldar is the leader of Lord Zed's Army.\n"+
      "He is a large monkey-like beast, covered\n"+
      "from head to toe in Golden Armor.\n"+
      "There is nothing goldar hates more than the Power Rangers.\n"+
      "\n");
   set_alias("ranger");
   set_race("zed_monster");
   set_level(20);
   set_hp(1000 + random(50));
   set_wc(55 + random(5));
   set_ac(24 + random(4));
   set_al(-1000);
   set_aggressive(0);
   set_chat_chance(3);
   gold=clone_object("obj/money");
   gold->set_money(random(2000) + 1000);
   move_object(gold, this_object());
   
}
DarkRangerNPC(){ return 1; }
query_guild_rank(){ return 70; }

custom_clean(){
   return 0;
}
init(){
   ::init();
   if(present("DarkRangerCommunicator",this_player())){
      present("DarkRangerCommunicator",this_player())->TrainRanger("Goldar","random");
   }
}
heart_beat(){
   object attacker;
   ::heart_beat();
   if(!attacker_ob) {
      if(random(100) < 2){ random_move(); }
   }
}

