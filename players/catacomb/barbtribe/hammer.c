inherit "/obj/weapon";
#include "/players/catacomb/misc/ansi.h"
#define TPN this_player()->query_name()
#define ATN attacker->query_name()
reset (arg)
{
  ::reset(arg);
  if(arg) return 0;

  set_name("hammer");
  set_alias("warhammer");
  set_short("A warhammer");
  set_long(
 "  A well crafted hammer, made for throwing or melee combat.\n"+
 "With one side for piercing and the other for smashing armor,\n"+
 "it makes a versatile weapon.\n" );
  set_type("club");
  set_class(15);
  set_weight(2);
  set_value(500);
  set_hit_func(this_object());
}
  mixed
  weapon_hit(object attacker)
 {
  string name;
    if(environment() && environment()->is_player())
    {
    name=(string)environment()->query_name();
    }
    if(!name)
      return 0;
    if(random (50) < 5) 
    {
     write("You throw the hammer with all your strength.\n");
     write(RED+"\n   The hammer PIERCES "+ATN+"'s armor.\n"+NORM);
     write(ATN+" staggers from the shot.\n");
     say(name+" throws the warhammer at "+ATN+"\n");
     return 2; 
    }
}

  
