#define WC 40
#define AC 20
inherit "obj/monster";
#include "/players/beck/MortalKombat/MKWarrior.h"


reset(arg){
   ::reset(arg);
   if(arg) return;
   set_name("Johnnie Cage");
   set_race("warrior");
   set_alias("cage");
   set_short("Johnnie Cage");
   set_long("Cage looks ready to fight.  As he takes off his sunglasses you\n"+
      "You can see in his eyes he wants to kill you.  Something about him makes you\n"+
      "wonder if your going to get out of this place alive.\n");
   Reset();
}

Special(att, attname){
   int i;
   i = random(15);
   if(i==3){
      say(name+" performs a Shadow Kick and slams "+attname+" in the middle of the chest.\n");
      att->hit_player(20+random(20));
   }
   else if(i == 7){
      say(name+" suddenly does a split a proceeds to punch "+attname+" in the crotch with incredible force.\n");
      att->hit_player(20+random(40));
   }
   if(time){
      time -= 1;
      if(!time)
         set_ac(AC);
   }
}