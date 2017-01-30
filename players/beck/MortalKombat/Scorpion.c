#define WC 60
#define AC 30
inherit "obj/monster";
#include "/players/beck/MortalKombat/MKWarrior.h"

reset(arg){
   ::reset(arg);
   if(arg) return;
   set_name("Scorpion");
   set_race("warrior");
   set_alias("scorpion");
   set_short("Scorpion");
   set_long("Scorpion is dressed in a yellow ninja suit.  He has a mask over his\n"+
      "face and for some reason you don't want him to take it off and see\n"+
      "what is behind the mask.  His eyes are enough to make you shrudder.\n");
   Reset();
}

Special(att, attname){
   int i;
   i = random(7);
   if(i==3){
      say(name+" yells: Come Here!.\nA small harpoon shoots from his hand and into your back.\n");
      att->hit_player(130+random(70));
   }
   else if(i == 5){
      say(name+" teleports behind you.\n");
      set_ac(100);
      set_wc(100);
      time = 1;
   }
   if(time){
      time -= 1;
      if(!time){
         set_wc(WC);
         set_ac(AC);
      }
   }
}
