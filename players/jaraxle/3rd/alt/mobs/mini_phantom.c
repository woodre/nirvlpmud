#include "/players/jaraxle/ansi.h"

inherit "obj/monster.c";



object enemy;
object gold;
reset(arg)  {
   ::reset(arg);
   
   if(arg) return;
   set_name("phantom");
   set_alt_name("spirit");
   set_race("phantom");
   set_long(
      "This is a small black skinned creature. It has short\n"+
      "bat-like wings which seem barely able to hold its small\n"+
      "3 foot tall frame. It is wirey in stature and yet very\n"+
      "strong. The Darkling has small claws and tiny razor\n"+
      "sharp teeth, both of which are capable of small amounts\n"+
      "of damage.\n");
   set_level(13);
   set_hp(250);
   set_al(-1000);
   set_wc(20);
   set_ac(1);
   set_heart_beat(1);
   set_aggressive(1);
 gold = clone_object("obj/money");
   gold->set_money(300+random(501));                              
   move_object(gold,this_object());
}

short(){
   if(attacker_ob){
      return HIW+"Phantom"+NORM;
   }
   else{
      return;
   }
}

init(){
   ::init();
   add_action("stop_exit", "up", 1);
   add_action("stop_exit", "out", 1);
   add_action("stop_exit", "get", 1);
   add_action("stop_exit", "take", 1);
}

stop_exit(){
   write("The Phantom blocks your every move!\n");
   return 1;
}

heart_beat(){
   ::heart_beat();
   
   if(attacker_ob) enemy = attacker_ob;
   
   if(enemy && !attacker_ob){
      if(environment(enemy) == environment()){ 
         tell_room(environment(),
            "The Phantom screams out of the dark and attacks!\n");
         attack_object(enemy);
      }
   }
}
