inherit "/obj/weapon.c";
#include "/players/catacomb/misc/ansi.h"
#define TPN this_player()->query_name()
#define ATN attacker->query_name()

reset (arg)
{
  ::reset(arg);
  if(arg) return;

  set_name("sword");
  set_short("A "+RED+"blazing fire"+NORM+" sword");
  set_long(
 "  The sword blazes away burning everything in its path.  The\n"+
 "sword has no blade but a roaring fire in the shape of a \n"+
 "broadsword.\n" );
  set_type("sword");
  set_class(16);
  set_weight(2);
  set_value(2500);
  set_hit_func(this_object()); 
}

mixed
weapon_hit(object attacker) 
{
  string name;
    if(environment() && environment()->is_player()) {
    name=(string)environment()->query_name(); }
    if(!name) return 0;
    if((random(20) > 15) && ((this_player()->query_attrib("int") > 18) &&
                             (this_player()->query_attrib("wis") > 18)))
    {
     write("\n\n             "+HIR+"FFFIIIRRREEE"+NORM+"\n");
     write("\n           SCORCHES through "+ATN+" leaving deep scars!\n\n");
     say("\n"+name+" leaves deep burning scars in "+ATN+"\n");
     return 2;
    }
    if(random(50) >= 48)
    {
     write("\n\n    The fire on the sword lashes out at your hands burning them.\n");
     say("\n\n    Fire lashes out at "+name+"'s hands leaving burns.\n");
     switch(random(2))
     {
	case 0:
            this_player()->heal_self(-5);
       	    break;
        case 1:
            this_player()->heal_self(-10);
            break;
        case 2:
            this_player()->heal_self(-15);
            break;
     }
    }
}

  
