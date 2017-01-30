#include "/players/mythos/closed/esc.h"
#include "/players/mythos/closed/ansi.h"
inherit "obj/weapon.c";
reset(arg){
  ::reset(arg);
  if (arg) return;

  set_name("sunblade");
  set_alias("blade");
  set_short("A Sun Blade");
  set_long("A Blade of Pure Sunlight- hot and blinding.\n");
  set_class(66);
  set_weight(3);
  set_value(10000);
  set_hit_func(this_object());
}
weapon_hit(attacker){
int W;
W = random(100);
if(W>49)  {
  say("The SUN BLADE "+HIR+"BURNS"+NORM+"through its foe!\n");
  write(HIM+"   The BLADE FLARES!"+NORM+"\n");
  attacker->heal_self(-50);
return 3;
}
if(W>25 && W<50) {
  say("You see the SUN BLADE "+HIY+"F L A R E"+NORM+"- blinding you.\n");
  write(DBL+HIY+"        F L A R E S"+NORM+"\n");
return 69;
   }
   return;
}
