inherit "/obj/weapon.c";
#include "/players/catacomb/saiyan/def.h"

reset (arg) {
  ::reset(arg);
  if(arg) return;

  set_name("spear");
  set_short("A sturdy spear");
  set_long(
 " The shaft of the spear is as long as you are tall.  At the\n"+
 "end of the spear shaft is a large curved blade with strange\n"+
 "inscriptions embedded in it.\n" );
  set_type("spear");
  set_class(16);
  set_weight(4);
  set_value(1000);
  set_hit_func(this_object()); }
  mixed
  weapon_hit(object attacker) {
  string name;
    if(environment() && environment()->is_player()) {
    name=(string)environment()->query_name(); }
    if(!name) return 0;
    if(random(25) <= 5) 
    {
     write(HIY+" You hit your enemy in the head with the shaft then\n");
     write("   slice through them, spraying blood everywhere.\n"+NORM);
     say(HIY+TPN+" smacks their enemy in the head then slices through\n"+
                    "them, spraying blood everywhere.\n");
     return 2; 
    } 
  }

  
