#include "/players/fred/ansi.h"
inherit "obj/weapon.c";

reset(arg) {
 ::reset(arg);
 if(arg) return;
   set_name("shotgun");
   set_alias("gun");
  set_short(MAG+"Jimbo's Shotgun"+NORM);
   set_long(
     "This is a double barreled, semi-automatic shotgun, with a\n"+
   "laser sight attached to it.  It once belonged to one of the\n"+
   "last great hunters, 'Jimbo'.\n");
  set_type("gun");
  set_class(16);
  set_weight(3);
  set_value(700);
  set_hit_func(this_object()); }
  mixed 
  weapon_hit(object attacker) {
  string name;
    if(environment() && environment()->is_player()) {
    name=(string)environment()->query_name(); }
    if(!name) return 0;
    if(random (100) < 20) {
     write("You aim the gun at "+attacker->query_name()+" and"+
            " slowly pull the trigger.\n\n");
     write(HIC+"      BOOM!\n\n"+NORM);
     write(HIC+"         BOOM!\n\n"+NORM);
     say(name+" aims the gun at "+attacker->query_name()+" and\n\n");
     say(BOLD+RED+"      FIRES\n\n"+NORM);
     say("             two shots.\n\n");
  return 3; } }
