#include "/players/catacomb/misc/ansi.h"
inherit "/obj/weapon.c";
#define TPN this_player()->query_name()

reset (arg) {
  ::reset(arg);
  if(arg) return;

  set_name("bow");
  set_short("A fine long bow");
  set_long(
 HIY+"  A finely crafted long bow.  The bowstring is made of some\n"+
 "strange material.  As the arrows are loosed, the string makes \n"+
 "no noise, making it the perfect bow for the hunting of animals.\n"+NORM);
  set_type("bow");
  set_class(15);
  set_weight(2);
  set_value(750);
  set_hit_func(this_object()); }
  mixed
  weapon_hit(object attacker) {
  string name;
    if(environment() && environment()->is_player()) {
    name=(string)environment()->query_name(); }
    if(!name) return 0;
    if(random (10) >= 8)
    {
     write("\n           You quickly knock a poison tipped arrow.\n");
     write(HIG+"A cloud of noxious mist errupts from the arrow as it hits the foe.\n"+NORM);
     write("          Your foe collapses in a coughing fit.\n");
     say("\n"+TPN+"'s foe collapses in a coughing fit as the arrow hits them.\n");
     return 2;
    } 
}

  
