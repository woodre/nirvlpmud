inherit "/obj/weapon.c";
#include "/players/catacomb/misc/ansi.h"
#define ATN attacker->query_name()

reset (arg)
{
  ::reset(arg);
  if(arg) return;

  set_name("axe");
  set_short("A "+BLK+"glowing "+NORM+"axe");
  set_long(
 "  The huge axe glows an eerie black that emits a black mist.\n"+
 "The mythril handle provides excellent grip.  The axe seems \n"+
 "to call to you urging you to bring chaos into the world. \n");
  set_type("axe");
  set_class(18);
  set_weight(3);
  set_value(2000);
  set_hit_func(this_object()); 
}

mixed
weapon_hit(object attacker) 
{
  string name;
  int Edamage;
  Edamage = random (3);
    if(environment() && environment()->is_player()) {
    name=(string)environment()->query_name(); }
    if(!name) return 0;
    if((random(20) > 15) && ((this_player()->query_align() < -100) &&
                             (this_player()->query_attrib("str") > 18)))
    {
     write("\n\n        The mist reaches out at "+ATN+".\n");
     write("            The axe cleaves through "+ATN+" .\n");
     write("           "+HIB+"Black mist escapes from the wound.\n\n"+NORM);
     say("\n"+name+" watches as "+ATN+"'s blood is consumed by the mist.\n");
     return 3;
    }
    if(random(50) > 40)
    {
     write(HIM+"\n\n    The axe leaves a trail of black mist in its wake.\n"+NORM);
     say("\n    A trail of mist follows the axe through "+ATN+".\n\n");
     if (Edamage == 0)
     {
       this_player()->hit_player(random (10), "other|evil");
       return 1;
     }
     else
     {
	 return 2;
     }
    }
}

  
