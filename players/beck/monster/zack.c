inherit "obj/monster";
#include "/players/beck/rangers/defs.h"

reset(arg)
{
   object gold, watch;
   ::reset(arg);
   if(arg) return;
   set_name("Zack");
   set_alt_name("zack");
   set_alias("ranger");
   set_long("Zack is one of the Mighty Morphin' Power Rangers.\n"+
      "\n");
   set_level(20);
   set_wc(29 + random(5));
   set_ac(16 + random(4));
   set_hp(500 + random(50));
   set_dead_ob(this_object());
   set_al(1000);
   set_aggressive(0);
   set_chat_chance(3);
   gold=clone_object("obj/money");
   gold->set_money(random(1000) + 1000);
   move_object(gold, this_object());
   if(!present("watch", this_object())){
      watch=clone_object("/players/beck/rangers/ranger_communicator.c");
      watch->init_arg();
      move_object(watch, this_object());
      watch->init();
   }
   MASTER->add_active_ranger("Zack");
}

long(){
   ::long();
   if(present("ranger_communicator",this_player())){
      write("Zack says to you:\n");
      if(!COMM->check_skills("lead")){
         write("What's going on?  So your the newer addition to the Power\n"+
         "Ranger team.  Well if your going to be out in the world fighting\n"+
         "evil forces, you'll need some help.  I think I know a few powers\n"+
         "that will be very useful to you.  They are to help you succeed in\n"+
         "battle, and to help others in their time of need.\n"+
         "Would you like to learn these powers? (yes)  \n"+
         "");
         input_to("train_ranger");
         return 1;
      }
      write("I see you are back to learn some more special moves.\n"+
      "Do you want to learn right now?  (yes) \n"+
      "");
      input_to("train_ranger");
      return 1;
   }
}
short(){
   if(present("ranger_communicator", this_object())->query_morphed()){
      return "Zack the Black Ranger";
   }
   return "A teenage boy named Zack";
}
monster_died(){
   object corpse;
   MASTER->remove_active_ranger("Zack");
   corpse = present("corpse", environment(this_object()));
   move_object(clone_object("/players/beck/armor/black_helmet.c"), corpse);
   move_object(clone_object("/players/beck/weapon/power_axe.c"), corpse);
   return 0;
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
train_ranger(str){
   if(str == "yes"){
      if(!COMM->check_skills("lead")){
         COMM->train_ranger("lead","skill",1000,0,0);
         return 1;
      }
      if(!COMM->check_skills("armor")){
         COMM->train_ranger("armor","skill",5000,1000,0);
         return 1;
      }
      if(!COMM->check_skills("weapon")){
         COMM->train_ranger("weapon","skill",5000,1000,0);
         return 1;
      }
      write("You have learned everything I have to teach you.\n");
      return 1;
   }
   write("Well maybe I can teach you some other time.\n");
   return 1;
}
