inherit "obj/monster";
#include "/players/beck/rangers/defs.h"

reset(arg)
{
   object gold, helmet, watch;
   ::reset(arg);
   if(arg) return;
   set_name("Billy");
   set_alt_name("billy");
   set_long("Billy is one of the Mighty Morphin' Power Rangers.\n"+
      "Billy is the genius of the power rangers.\n"+
      "He is also the most creative, always building devices to\n"+
      "in defeating Lord Zed and other evil creatures.\n"+
      "Billy not only has brains, but also is a very strong opponent\n"+
      "if you choose to make him such.\n"+
      "\n");
   set_alias("ranger");
   set_level(20);
   set_hp(500 + random(50));
   set_wc(29 + random(5));
   set_ac(16 + random(4));
   set_al(1000);
   set_aggressive(0);
   set_chat_chance(3);
   set_dead_ob(this_object());
   gold=clone_object("obj/money");
   gold->set_money(random(2000) + 1000);
   move_object(gold, this_object());
   if(!present("watch", this_object())){
      watch=clone_object("/players/beck/rangers/ranger_communicator.c");
      watch->init_arg();
      move_object(watch, this_object());
      watch->init();
   }
   MASTER->add_active_ranger("Billy");
}

init(){
   ::init();
   if(present("RangerCommunicator",this_player())){
      present("RangerCommunicator",this_player())->TrainRanger("Billy","random");
   }
}
short(){
   if(present("ranger_communicator", this_object())->query_morphed()){
      return "Billy the "+BOLD+BLUE+"Blue"+OFF+" Ranger";
   }
   return "A teenage boy named Billy";
}
heart_beat(){
   ::heart_beat();
   if(hit_point < 350){
      if(!present("ranger_communicator",this_object())->query_morphed()){   
         MASTER->add_power_points(100);
         command("morph", this_object());
      }
   }
}

monster_died(){
   object corpse;
   MASTER->remove_active_ranger("Billy");
   corpse = present("corpse", environment(this_object()));
   move_object(clone_object("/players/beck/armor/blue_helmet.c"), corpse);
   return 0;
}
