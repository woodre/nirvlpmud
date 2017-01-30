inherit "obj/monster";
#include "/players/beck/rangers/Defs.h"

reset(arg)
{
   object gold, helmet, watch;
   set_move_at_reset();
   ::reset(arg);
   if(arg) return;
   set_name("Tommy");
   set_alt_name("tommy");
   set_long("Tommy is one of the Mighty Morphin' Power Rangers.\n"+
      "Tommy is the strongest of the power rangers.\n"+
      "He is also the first to step into battle to save his friends.\n"+
      "With his new identity and powers, as the White Ranger (formerly\n"+
      "the green ranger) his only mission is to destroy Lord Zed and\n"+
      "his evil minions.\n"+
      "\n");
   set_hbflag("hbstayon");
   set_alias("ranger");
   set_level(20);
   set_wc(30);
   set_ac(22);
   set_hp(1000);
   set_al(1000);
   set_aggressive(0);
   set_chat_chance(3);
   set_dead_ob(this_object());
   gold=clone_object("obj/money");
   gold->set_money(random(1000) + 3000);
   move_object(gold, this_object());
   if(!present("RangerCommunicator", this_object())){
      watch=clone_object("/players/beck/rangers/RangerCommunicator.c");
      watch->init_arg();
      move_object(watch, this_object());
      watch->init();
   }
}

custom_clean(){
   MASTER->RemoveRanger("all",TO);
   return 0;
}
RangerNPC(){ return 1; }
query_guild_rank(){ return 70; }
init(){
   ::init();
   if(COMM){
      string type;
      if(COMM->QKarateLevel() ==9){ type = "none";}
      if(COMM->QKarateLevel() == 8){ type = "black";}
      if(COMM->QKarateLevel() == 7){ type = "brown";}
      if(COMM->QKarateLevel() == 6){ type = "purple";}
      if(COMM->QKarateLevel() == 5){ type = "blue";}
      if(COMM->QKarateLevel() == 4){ type = "green";}
      if(COMM->QKarateLevel() == 3){ type = "red";}
      if(COMM->QKarateLevel() == 2){ type = "orange";}
      if(COMM->QKarateLevel() == 1){ type = "yellow";}
      if(COMM->QKarateLevel() == 0){ type = "white";}
      COMM->TrainRanger("Tommy",type);
   }
}

short(){
   if(present("RangerCommunicator", this_object())->QMorphed()){
      return "Tommy the "+BOLD+WHITE+"White"+OFF+" Ranger";
   }
   return "A teenage boy named Tommy";
}
heart_beat(){
   object attacker;
   ::heart_beat();
   if(!TO->query_attack()){
      if(random(100) < 2){ random_move(); }
   }
   if(this_object()->query_attack()){
      if(present("honor_ranger_communicator", this_object()->query_attack())){
         attacker = this_object()->query_attack();
         MASTER->RemoveRanger("all",attacker);
         destruct(present("honor_ranger_communicator", attacker));
         tell_object(attacker, "Tommy tells you: How dare you!\n");
         command("rt "+attacker->query_name()+" is no longer an Ally of the Power Rangers.\n",this_object());
         attacker->hit_player(100);
      }
   }
   if(hit_point < 750){
      if(!present("RangerCommunicator",this_object())->QZord()){
         MASTER->APowerPoints(740);
         command("zord", this_object());
      }
   }
   if(hit_point < 850){
      if(!present("RangerCommunicator",this_object())->QMorphed()){   
         MASTER->APowerPoints(100);
         command("morph", this_object());
      }
   }
}

monster_died(){
   object corpse;
   MASTER->RemoveRanger("all",TO);
   corpse = present("corpse", environment(this_object()));
   command("release",this_object());
   move_object(clone_object("/players/beck/armor/white_helmet.c"), corpse);
   return 0;
}

