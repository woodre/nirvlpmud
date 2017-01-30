#define WC 60
#define AC 29
inherit "obj/monster";
#include "/players/beck/MortalKombat/MKWarrior.h"

reset(arg){
   ::reset(arg);
   if(arg) return;
   set_name("Kano");
   set_race("warrior");
   set_alias("kano");
   set_short("Kano");
   set_long("Kano is dressed in all white.  He looks like he has something\n"+
      "metallic where is face is.  You notice he is carrying a knife that has\n"+
      "a blue glow surrouding it.\n");
   Reset();
}

Special(att, attname){
   int i;
   i = random(8);
   if(i==3){
      say("A glowing blue knife appears in "+name+"'s hand.  He throws it at "+attname+" .\n");
      att->hit_player(60+random(60));
   }
   else if(i == 7){
      say(name+" suddenly contorts into a spinning ball and hurls himself at "+attname+".\n");
      att->hit_player(130+random(40));
   }
   if(time){
      time -= 1;
      if(!time)
         set_ac(AC);
   }
}
