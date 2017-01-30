#include "/sys/ansi.h"
inherit "/obj/weapon.c";

void reset(status arg) {
  ::reset(arg);
  if(arg) return;
  
  set_name("congela");
  set_alias("kukri");
  set_short("Kukri "+HIK+"["+HIC+"Congela"+HIK+"]"+NORM);
  set_long("Congela is one of the twin kukris that is wielded by muse. Its short\n"+
	   "curved blade is coated with a thin layer of frost. A constant cloud\n"+
           "of water vapor surrounds the weapon constantly freezing and evaporating.\n");
/* physical damage */
  set_class(19);
  set_params("other|cold",17,"freezing_blast");
  set_weight(1);
  set_value(12000);
}

int freezing_blast(object attacker) {
  if(!attacker || !wielded_by)
    return 0;
  tell_object(wielded_by,HIC+"Congela releases an icy blast as it hits!\n"+NORM);
  tell_object(attacker,HIC+wielded_by->query_name()+"'s kukri blasts you with icy torrent!\n"+NORM);
  if(environment())
    tell_room(environment(),
    HIC+wielded_by->query_name()+"'s kukri releases an icy blast into "+attacker->query_name()+"!\n"+NORM,
    ({wielded_by,attacker}));
  return 15; 
}