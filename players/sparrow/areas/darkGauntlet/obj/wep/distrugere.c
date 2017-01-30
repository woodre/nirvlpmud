#include "/sys/ansi.h"
inherit "/obj/weapon.c";

void reset(status arg) {
  ::reset(arg);
  if(arg) return;
  
  set_name("distrugere");
  set_alias("kukri");
  set_short("Kukri "+HIK+"["+HIR+"Distrugere"+HIK+"]"+NORM);
  set_long("Distrugere is one of the twin kukris that is wielded by Muse. The jet black\n"+
           "blade seems to radiate with pure evil, a sick hunger that hangs thick in the\n"+
           "air. Distrugere needs to feed...\n");
/* physical damage */
  set_class(19);
  set_params("other|evil",17,"death_stroke");
  set_type("dagger");
  set_weight(1);
  set_value(12000);
}

int death_stroke(object attacker) {
  if(!attacker || !wielded_by)
    return 0;
  tell_object(wielded_by,HIR+"You plunge Distrugere into your foe! Distrugere feeds!\n"+NORM);
  tell_object(attacker,HIR+wielded_by->query_name()+"'s kukri feeds from your life force!\n"+NORM);
  if(environment())
    tell_room(environment(),
    HIR+wielded_by->query_name()+"'s kukri feeds from "+attacker->query_name()+"'s life force!\n"+NORM,
    ({wielded_by,attacker}));
  return 15; 
}