#define WC 80
#define AC 30
inherit "obj/monster";
#include "/players/beck/MortalKombat/MKWarrior.h"


reset(arg){
   ::reset(arg);
   if(arg) return;
   set_name("Liu Kang");
   set_race("warrior");
   set_alias("liu");
   set_short("Liu Kang");
   set_long("Liu Kang is a master at martial arts.  He stands just over\n"+
      "five feet tall and at first you want to laugh, but taking a second\n"+
      "look into his eyes you decide you had better keep your guard up.\n");
   Reset();
set_hp(1250);
}

Special(att, attname){
   int i;
   i = random(8);
   if(i==3){
      say(name+" clenches his fists and shoots a fireball into "+attname+"\n");
      att->hit_player(70+random(50));
   }
   else if(i == 5){
      say(name+" does a spinning cartwheel and rolls right into "+attname+".\n");
      att->hit_player(150+random(50));
   }
   if(time){
      time -= 1;
      if(!time){
         set_wc(WC);
         set_ac(AC);
      }
   }
}
