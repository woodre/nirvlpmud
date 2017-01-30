#include "/players/fred/ansi.h"
inherit "/obj/weapon.c";

reset (arg) {
  ::reset(arg);
  if(arg) return;

  set_name("vengence_bow");
  set_alias("crossbow");
  set_short("Crossbow of"+RED+" Vengence"+NORM);
  set_long(
 "  It is an older crossbow that is carved out of\n"+
 "a dark black wood. As you hold it in your hands you\n"+
 "can somehow feel it's power flowing through you.\n" );
  set_type("bow");
  set_class(18);
  set_weight(2);
  set_value(1300);
  set_hit_func(this_object()); }
  mixed
  weapon_hit(object attacker) {
  string name;
    if(environment() && environment()->is_player()) {
    name=(string)environment()->query_name(); }
    if(!name) return 0;
    if(random (100) < 20) {
     write("\nYou fire an arrow into "+HIC+attacker->query_name()+NORM+"'s chest.\n\n");
     write(BOLD+RED+"           BLOOD\n\n"+NORM);
     write(BOLD+"    Gushes"+NORM+" from his wounds.\n\n");
     say(name+" hits "+HIC+attacker->query_name()+NORM+" in the chest with an arrow.\n");
 return 5; } }

  
