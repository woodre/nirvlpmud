#define WC 90
#define AC 20
inherit "obj/monster";
#include "/players/beck/MortalKombat/MKWarrior.h"


reset(arg){
   ::reset(arg);
   if(arg) return;
   set_name("Reptile");
   set_race("warrior");
   set_alias("reptile");
   set_short("Reptile");
   set_long("Reptile is dressed in an all green suit.  His face is\n"+
      "obscurred by a mask, but even still you can tell he is not\n"+
      "quite human.\n");
   Reset();
}

Special(att, attname){
   int i;
   i = random(9);
   if(i==3){
      say(name+" wraps his toungue around the neck of "+attname+" and chokes them.\n");
      att->hit_player(100+random(50));
   }
   else if(i == 7){
      say(name+" dissapears from sight.\n");
      set_ac(80);
      time = 1 + random(6);
   }
   if(time){
      time -= 1;
      if(!time){
         say(name+" appears suddenly.\n");
         set_ac(AC);
      }
   }
}

short(){
   if(time)
      return 0;
   else
   return ::short();
}
