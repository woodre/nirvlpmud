#define WC 70
#define AC 28
inherit "obj/monster";
#include "/players/beck/MortalKombat/MKWarrior.h"

reset(arg){
   ::reset(arg);
   if(arg) return;
   set_name("Sonya");
   set_race("warrior");
   set_alias("sonya");
   set_short("Sonya");
   set_long("Sonya is one bitch you don't want to mess with.  You\n"+
      "realize when you look at her that all of the warriors here\n"+
      "want to be champion of Mortal Kombat and will kill you go get there.\n");
   Reset();
}

Special(att, attname){
   int i;
   i = random(9);
   if(i==3){
      say(name+" does a handstand and catches "+attname+" between her legs.\n"+name+" then throws "+attname+" to the ground by their neck.\n");
      att->hit_player(55+random(60));
   }
   else if(i == 7){
      say(name+" teleports behind you.\n");
      set_ac(50);
      set_wc(150);
      time = 1;
   }
else if(i == 5){
say(name+" blows a kiss (made of fire)\n");
att->hit_player(100+random(50));
}
   if(time){
      time -= 1;
      if(!time){
         set_wc(WC);
         set_ac(AC);
      }
   }
}
