inherit "/obj/weapon";
#include "/players/catacomb/misc/ansi.h"
#define ATN attacker->query_name()

reset (arg) {
  ::reset(arg);
  if(arg) return;

  set_name("club");
  set_short("A club");
  set_long(
 "  The club is normal except for some of the runes on the side\n"+
 "of it's face.\n");
  set_type("mace");
  set_class(8);
  set_weight(2);
  set_value(300);
  set_hit_func(this_object()); 
}
  mixed
  weapon_hit(object attacker) 
{
  string name;
    if(environment() && environment()->is_player()) {
    name=(string)environment()->query_name(); }
    if(!name) return 0;
    if(random (40) < 4 ) {
     write("The club begins to "+YEL+"glow"+NORM+" with energy.\n");
     write("A shockwave of energy erupts from the club, sending\n");
     write(ATN+" flying back.\n");
     say(name+" swings and sends "+ATN+" flying\n");
     say(" away from them.\n");
 return 2; 
}
}

  
