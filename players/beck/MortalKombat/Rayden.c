#define WC 50
#define AC 20
inherit "obj/monster";
#include "/players/beck/MortalKombat/MKWarrior.h"


reset(arg){
   ::reset(arg);
   if(arg) return;
   set_name("Rayden");
   set_race("warrior");
   set_alias("rayden");
   set_short("Rayden");
   set_long("Rayden has electricity flowing around him.  It seems to be flowing\n"+
      "from his hat.  He looks like he will use anything to defeat you.\n");
   Reset();
}

Special(att, attname){
   int i;
   i = random(15);
   if(i==3){
      say("Lightning bolts shoot from "+name+" into "+attname+"\n");
      att->hit_player(40+random(40));
   }
   else if(i == 7){
      say(name+" teleports away from "+attname+".\n");
      set_ac(65);
      time = 1;
   }
   else if(i == 13){
      say(name+" yells out: Aui Kaw An Aee!\nSuddenly "+name+" lunges at "+attname+" and pushes them 20 feet backward.\n");
      att->hit_player(random(30));
   }
   if(time){
      time -= 1;
      if(!time){
         set_wc(WC);
         set_ac(AC);
      }
   }
}
