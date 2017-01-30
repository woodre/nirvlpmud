inherit "obj/monster";
#include "/players/beck/rangers/defs.h"

reset(arg)
{
   object gold, weapon;
   ::reset(arg);
   if(arg) return;
   set_name("hanz");
   set_alias("franz");
   set_short("Hanz and Franz");
   set_long("Hanz and Franz were hired by Golds Gym to assist you\n"+
      "in your training with their words of inspiration.\n"+
      "These inseparable brothers are the worlds most renouned\n"+ 
      "training experts.\n"+
"");
   set_level(15);
   set_hp(250);
   set_wc(20);
   set_ac(12);
   set_chat_chance(1);
   load_chat("Hanz says: I'm Hanz.\n"+
   "Franz says: And I'm Franz.\n"+
   "Hanz and Franz say: And we want to pump *clap* you up!\n"+
   "");
   load_chat("Hanz says: Hear me now. Believe me later.\n");
   load_chat("Franz says: Hey little girly man!\n");
   gold=clone_object("obj/money");
   gold->set_money(250);
   move_object(gold, this_object());
}
long(){
   ::long();
   if(COMM){
      if(!COMM->check_skills("train")){
         write("Hanz says to you:\n"+
            "Hey girly Power Ranger Man.  Why you so wimpy?\n"+
            "Maybe if you workout you would be as huge as we are.\n"+
            "Franz says:  Well almost as huge as we are.\n"+
            "If you workout here, you can train yourself to use\n"+
            "your strength, speed, and endurance to fight those\n"+
            "flabby evil people.  Would you like to learn?  (yes/no)\n"+
            "");
         input_to("train_ranger");
         return 1;
      }
   }
}

train_ranger(str){
   if(str == "yes"){
      if(!COMM->check_skills("train")){
         COMM->train_ranger("train","skill",10000,0,0);
         return 1;
      }
   }
   write("Well bring your sorry flabby butts back some other time!\n");
   return 1;
}
