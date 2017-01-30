inherit "obj/monster";
#include "/players/beck/rangers/defs.h"

reset(arg)
{
   object gold, watch;
   ::reset(arg);
   if(arg) return;
   set_name("Rocky");
   set_alt_name("rocky");
   set_long("Jason is one of the Mighty Morphin' Power Rangers.\n"+
      "Jason is the leader of the Power Rangers.\n"+
      "He is dressed from head to toe in a red nylon suit.\n"+
      "His face is obscurred by a red helmet.\n"+
      "Jason is a fearless leader prepared to take on anyone or anything.\n"+
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
   gold->set_money(random(1500) + 1000);
   move_object(gold, this_object());
   if(!present("watch", this_object())){
      watch=clone_object("/players/beck/rangers/ranger_communicator.c");
      watch->init_arg();
      move_object(watch, this_object());
      watch->init();
   }
   MASTER->add_active_ranger("Rocky");
}
short(){
   if(present("ranger_communicator", this_object())->query_morphed()){
      return "Rocky the "+BOLD+RED+"Red"+OFF+" Ranger";
   }
   return "A teenage boy named Rocky";
}

long(){
   ::long();
   if(present("ranger_communicator",this_player())){
      write("Jason says to you:\n");
      if(!COMM->check_skills("battlezord")){
         write("Hello Power Ranger.  I am Jason, the leader of the Power Rangers.\n"+
            "We, as Power Rangers, have many things that others don't.  This gives us\n"+
            "the advantage in battle.  Zordon has provided us with special weapons, and\n"+
            "high tech. machines called Zords.  Zordon has given us the power to combine\n"+
            "our weapons into one Power Blaster.  Also he has given us 3 different types\n"+
            "of Zords to choose.  There is the Battlezord, which follows us, and helps\n"+
            "us in battle.  There is also the Thunderzord, which forms the foundation\n"+
            "of the Thunder Megazord, our most powerful.  I can show you how to use \n"+
            "all of these, but I have to make sure your ready, and a proven leader\n"+
            "for these are very powerful tools, and require much responsability.\n"+
            "Do you want to learn to use these?  (yes)\n"+
            "");
         input_to("train_ranger");
         return 1;
      }   
      write("I see you are becoming a powerful leader, among your comrades.\n"+
         "Would you like to learn more about our special power equipment?  (yes)\n"+
         "");
      input_to("train_ranger");
      return 1;
   }
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
   MASTER->remove_active_ranger("Jason");
   corpse = present("corpse", environment(this_object()));
   move_object(clone_object("/players/beck/armor/red_helmet.c"), corpse);
   move_object(clone_object("/players/beck/weapon/power_sword.c"), corpse);
   return 0;
}
train_ranger(str){
   if(str == "yes"){
      if(!COMM->check_skills("battlezord")){
         COMM->train_ranger("battlezord","skill",5000,300,0);
         return 1;
      }
      if(!COMM->check_skills("blaster")){
         COMM->train_ranger("blaster","skill",20000,5000,0);
         return 1;
      }
      if(!COMM->check_skills("thunderzord")){
         COMM->train_ranger("thunderzord","skill",20000,10000,0);
         return 1;
      }
      if(!COMM->check_skills("megazord")){
         COMM->train_ranger("megazord","skill",20000,10000,0);
         return 1;
      }
      write("I have taught you all I know.\n");
      return 1;
   }
   write("Well maybe I can teach you at another time.\n");
   return 1;
}
