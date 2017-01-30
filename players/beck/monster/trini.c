#include "/players/beck/rangers/defs.h"
inherit "obj/monster";

reset(arg)
{
   object gold, helmet, daggers, watch;
   ::reset(arg);
   if(arg) return;
   set_name("Trini");
   set_alt_name("trini");
   set_long("Trini is one of the Mighty Morphin' Power Rangers.\n"+
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
   MASTER->add_active_ranger("Trini");
}

short(){
   if(present("ranger_communicator", this_object())->query_morphed()){
      return "Trini the "+BOLD+YELLOW+"Yellow"+OFF+" Ranger";
   }
   return "A teenage girl named Trini";
}

long(){
   ::long();
   if(COMM){
      if(!COMM->check_skills("jet")){
         write("Trini says to you:\n"); 
         write("Hello Power Ranger.  You will have many battles in the\n"+
         "future.  It will be important that you can move from place to\n"+
         "place quickly.  Zordon has helped us by giving us the ability\n"+
         "to fly through the air, yet still be in control of our motion.\n"+
         "We call this jetting.  \n"+
         "Would you like me to teach this to you? (yes) \n"+
         "");
         input_to("train_ranger");
         return 1;
      }   
      if(!COMM->check_skills("dkick")){
         if(present("kimberly", environment(this_object()))){
            write("Trini says to you:\n"); 
            write("There is an important skill that will help you when fighting\n"+
            "alongside a fellow Power Ranger.  It takes coordination and timing\n"+
            "but is very effective.  We call this the double kick, where two\n"+
            "rangers kick the opponent at the same time.\n"+
            "Would you like Kimberly and I to teach you?  (yes)\n"+
            "");
            input_to("train_ranger");
            return 1;
         }
      }
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
   MASTER->remove_active_ranger("Trini");
   corpse = present("corpse", environment(this_object()));
   move_object(clone_object("/players/beck/armor/yellow_helmet.c"), corpse);
   move_object(clone_object("/players/beck/weapon/power_daggers.c"), corpse);
   return 0;
}
train_ranger(str){
   if(str == "yes"){
      if(!COMM->check_skills("jet")){ 
         COMM->train_ranger("jet","skill",500,0,0);
         return 1;
      }
      if(!COMM->check_skills("dkick")){
         COMM->train_ranger("dkick","skill",5000,5000,0);
         return 1;
      }
   }   
   write("Maybe you would like to learn some other time then.\n");
   return 1;
}
