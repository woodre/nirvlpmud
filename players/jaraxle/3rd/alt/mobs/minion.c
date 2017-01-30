#include "/players/jaraxle/ansi.h"

inherit "obj/monster.c";



object enemy;
object gold;
reset(arg)  {
   ::reset(arg);
   
   if(arg) return;
   set_name("Apostle");
   set_alt_name("apostle");
   set_race("human");
   set_long(
      "A short human with dirty skin, the Apostles are\n"+
      "forever devoted to their leader Armageddon.\n");
   set_level(15);
   set_hp(50);
   set_al(0);
   set_wc(30);
   set_ac(5);
   set_heart_beat(1);
   set_aggressive(1);
}

short(){
   if(attacker_ob){
      return HIB+"Apostle of Nirvana"+NORM;
   }
   else{
      return;
   }
}


heart_beat(){
   ::heart_beat();
   
   if(attacker_ob) enemy = attacker_ob;
   
   if(enemy && !attacker_ob){
      if(environment(enemy) == environment()){ 
         tell_room(environment(),
            "Armageddon's Apostle blindly attacks!\n");
         attack_object(enemy);
      }
   }
}
