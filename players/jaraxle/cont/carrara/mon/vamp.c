#include "/players/jaraxle/define.h"
inherit "/players/vertebraker/closed/std/monster.c";
int x;
string my_name;
reset(arg)  {
   object gold;
   switch(random(4)){
      case 0: my_name = "dallas";
      break;
      case 1: my_name = "dainja";
      break;
      case 2: my_name = "heloise";
      break;
      case 3: my_name = "cable";
      break;
   }
   ::reset(arg);
   if(arg) return;
   
   set_name(my_name);
   set_alias(my_name);
   set_race("cyberninja");
   set_short("Grand Master "+capitalize(my_name)+" "+HIY+"the CyberNinja"+NORM);
   
   set_level(20);
   set_hp(550+random(50));
   set_al(-1500);
   set_ac(17);
   set_aggressive(0);
   set_wc(35+random(6));
   set_wc_bonus(20);
   set_ac_bonus(6);
   set_dead_ob(this_object());
   gold = clone_object("obj/money");
   gold->set_money(100+random(501));                              
   move_object(gold,this_object());
   set_wander(30, 0, ({ "out" }));
    set_a_chat_chance(15);
load_a_chat(capitalize(my_name)+" cringes.\n");
load_a_chat(capitalize(my_name)+" dive rolls left!\n");
} 
long(){
   write("A tall figure, with a dark cloak wrapped around their body.\n"+
      ""+capitalize(my_name)+"'s arms stick out slightly from the sleeves of the\n"+
      "cloak showing metallic arms.  Eyes of ruby glow eerily\n"+
      "behind the hood of "+capitalize(my_name)+"'s hood.\n");
   write(capitalize(my_name)+" is a human, 6 feet 1 inches tall, 296 lbs.\n"+
      ""+capitalize(my_name)+" can fight other players.\n"+
      ""+capitalize(my_name)+" is in good shape.\n"+
      ""+capitalize(my_name)+" has Cybernetic Implants.\n"+
      ""+capitalize(my_name)+" has eyes of ruby.\n"+
      ""+capitalize(my_name)+" has muscle enhancements.\n"+
      ""+capitalize(my_name)+" has FluX jacks.\n"+
      ""+capitalize(my_name)+" has a smartweapon link.\n"+
      "\t"+capitalize(my_name)+" is carrying:\n"+
      "Krypt <vortex-forged> (wielded).\n"+
      "CyberNinja Implants.\n");
}

monster_died() {
   tell_room(environment(this_object()),
      ""+capitalize(my_name)+" falls to the ground, dead.\n");
   return 0;
}



p3(){
   
   string ATT_NAME,msg;
   if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
   
   tell_room(environment(), "Double laser disruption funnels thunder from "+capitalize(my_name)+"'s eyes and slam into "+ATT_NAME+".\n", ({ attacker_ob }));
  tell_object(attacker_ob, "Double laser disruption funnels thunder from "+capitalize(my_name)+"'s eyes and slam into you.\n");
   attacker_ob->hit_player(15+random(11));
}

flux(){
   
   string ATT_NAME,msg;
   if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
tell_object(attacker_ob, capitalize(my_name)+" releases a burst of electric flux into you.\n");
tell_room(environment(), capitalize(my_name)+" releases a burst of electric flux into "+ATT_NAME+".\n", ({ attacker_ob }));
   switch(random(2)){
      case 0:
      say(BLU+"             |\n"+        
         "             |\n"+        
         "       -- ---*--- --\n"+  
         "             |\n"+        
         "             |\n"+NORM);
      break;
      
      case 1:
      say(BLU+"                -|-\n"+        
         "               --|--\n"+        
         "      -- --- ----*---- --- --\n"+
         "               --|--\n"+        
         "                -|-\n"+NORM);        
      break;
   }
   attacker_ob->hit_player(20+random(6));
}

atk_mode(){
   
   string ATT_NAME,msg;
   if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
   say(RED+"Fire"+NORM+" races along the blade of "+capitalize(my_name)+"'s kusari_gama!\n");
tell_object(attacker_ob, "You are impaled on "+capitalize(my_name)+"'s blades!\n");
tell_room(environment(), ""+ATT_NAME+RED+" is impaled on "+capitalize(my_name)+"'s blades!"+NORM+"\n", ({ attacker_ob }));
   
   attacker_ob->hit_player(20+random(6));
}


heart_beat(){
   int i;
   ::heart_beat();
   if(attacker_ob){
      i = random(20);
      switch(i){
         
         case 0..4: p3();
         break;
         
         case 5..9: flux();
         break;
         
         case 10..14: return 0;
         break;
         case 15..19: atk_mode();
         break;
      }
   }
}
