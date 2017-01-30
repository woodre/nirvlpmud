inherit "obj/monster";
#include "/players/beck/rangers/defs.h"

reset(arg)
{
object gold, helmet, bow, watch;
  ::reset(arg);
  if(arg) return;
   set_name("Kimberly");
   set_alt_name("kimberly");
   set_long("Kimberly is one of the Mighty Morphin' Power Rangers.\n"+
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
   MASTER->add_active_ranger("Kimberly");
}
short(){
   if(present("ranger_communicator", this_object())->query_morphed()){
      return "Kimberly the "+BOLD+MAGENTA+"Pink"+OFF+" Ranger";
   }
   return "A teenage girl named Kimberly";
}

long(){
  ::long();
  if(COMM){    
     if(!COMM->check_skills("study")){
        write("Kimberly says to you:\n");  
        write("Hello Power Ranger.  It seems like you need a little\n"+
        "help learning about your enemies.   The Power Rangers duties\n"+
        "are to protect the good, and destroy the evil.  If you attempt\n"+
        "to turn on things that are good, especially when morphed,\n"+
        "Zordon may get upset with you.  The evil enemies sometimes\n"+
        "hard to spot, but much can be learned by just looking at them\n"+
        "I can teach you what to look for, to find out more about\n"+
        "opponents.  Would you like to learn?  (yes)  \n"+
        "");
        input_to("train_ranger");
        return 1;
     }
     if(!COMM->check_skills("dkick")){
         if(present("trini", environment(this_object()))){
            write("Kimberly says to you:\n");  
            write("There is an important skill that will help you when fighting\n"+
            "alongside a fellow Power Ranger.  It takes coordination and timing\n"+
            "but is very effective.  We call this the double kick, where two\n"+
            "rangers kick the opponent at the same time.\n"+
            "Would you like Trini and I to teach you?  (yes)\n"+
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
   MASTER->remove_active_ranger("Kimberly");
   corpse = present("corpse", environment(this_object()));
   move_object(clone_object("/players/beck/armor/pink_helmet.c"), corpse);
   move_object(clone_object("/players/beck/weapon/power_bow.c"), corpse);
   return 0;
}
train_ranger(str){
   if(str == "yes"){
      if(!COMM->check_skills("study")){
         COMM->train_ranger("study","skill",500,0,0);
         return 1;
      }
      if(!COMM->check_skills("dkick")){
         COMM->train_ranger("dkick","skill",5000,5000,0);
         return 1;
      }
   }
   write("Maybe you'd like to learn some other time then.\n");
   return 1;
}
