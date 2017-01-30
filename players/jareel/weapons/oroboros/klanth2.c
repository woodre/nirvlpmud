#include "/players/jareel/define.h"
#include "/players/jareel/ansi.h"
inherit "/obj/weapon.c";

object ob;
int limit = 5;

  reset(arg) {
    ::reset(arg);
    if(arg) return;

    set_id("klanth");
    set_alt_name("klanth2");
    set_alias("ivory klanth");
    set_short("Ivory Klanth");
    set_long(
       "This elegant blade is composed of a very lite white bone.  The blade\n"+
       "is very sharp and holds a perfect edge.  The hilt of the blade holds\n"+
       "two separate spell matrix.  The blade has the perfect balence for\n"+
       "fast attacks.\n");
    set_weight(1);
    set_class(19);
    set_value(8500);
    set_type("sword");
    message_hit = ({
      HIK+"slashes"+NORM," accross the chest",
      HIK+"stabs"+NORM," in the chest",
      HIK+"chops"+NORM," over the head",           
      HIK+"impales"+NORM," the sword deep into his victum",
      HIK+"stabs"+NORM," the skull",
      HIK+"slashes"+NORM," accross the knee of its foe",
      HIK+"sweeps"+NORM," accross its foe"
      });
    set_hit_func(this_object());
}

     init() {
       ::init();
}

     weapon_hit(attacker) {
       status heh;
         if(TPRN != "slineth") {
           if(!heh)
           if(random(100) < 40  && limit > 0) {
             heh = 1;
           TP->attack();
             heh = 0;
           limit --;
         return 1;}
         else { 
           limit = 5;
         return 3; }}}
        
  query_wear() { return 0; }

