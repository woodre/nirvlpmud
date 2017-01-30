#include "/players/mythos/closed/ansi.h"
inherit "obj/weapon.c";
reset(arg){
  ::reset(arg);
  if (arg) return;

  set_name("yamato");
  set_short("A Blade of "+BOLD+"DARKNESS"+NORM);
  set_long("A Blade of Darkness- a cold and dark blade.\n" +
     "If looked closely shadowy runes are written in it.\n");
  set_read("Soul Seeker\n");
  set_class(17);
  set_weight(3);
  set_value(800);
  set_hit_func(this_object());
}

weapon_hit(attacker){
int W;
W = random(13);
if(W>9)  {
   say(BOLD+"           <     <   <<  DARKNESS  >>   >     >\n"+NORM);
   attacker->heal_self(-13);
   return 0;
 }
   return;
}
