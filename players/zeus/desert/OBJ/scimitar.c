inherit "/obj/weapon.c";
#include "/players/zeus/closed/all.h"

reset(arg) {
   ::reset(arg);
   if (arg) return;

  set_name("scimitar");
  set_short("A large scimitar");
  set_type("sword");
  set_long(
"This is a somewhat generic looking scimitar.  It has a large hilt\n"+
"and a very broad blade that slopes back into a very sharp point at\n"+
"the tip.  There are a few scratches on it but it is still a very\n"+
"high quality sword.\n");
  set_value(500);
  set_weight(7);
  set_class(16);
  set_hit_func(this_object());
}

int weapon_hit(object target){
  if(environment()->is_npc()) return 0;
  if(4 == random(5))
  {
    tell_room(environment(target), "\n\t"+
      environment()->query_name()+" slashes open "+target->query_name()+
      " with "+environment()->query_possessive()+" scimitar!\n"+
      "\tBlood pours out from "+target->query_name()+"'s wounds!\n\n");
    return 4;
  }
}
