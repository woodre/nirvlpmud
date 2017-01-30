#include "/players/catacomb/misc/ansi.h"
inherit "/obj/weapon.c";
#define TPN this_player()->query_name()

reset (arg) {
  ::reset(arg);
  if(arg) return;

  set_name("staff");
  set_alias("battlestaff");
  set_short("A wooden battlestaff");
  set_long(
 "  The staff is approximately five feet long offering the wielder\n"+
 "supreme reach when fending of monsters.  It has been beautifully\n"+
 "crafted to allow the user maximum efficiency.\n" );
  set_type("staff");
  set_class(17);
  set_weight(2);
  set_value(1000);
  set_hit_func(this_object()); }
  mixed
  weapon_hit(object attacker)
  {
   string name;
    if(environment() && environment()->is_player()) {
    name=(string)environment()->query_name(); }
    if(!name) return 0;
    if(random (20) >= 17)
    {
     write("\nYou quickly jab the opponent over..\n");
     write(YEL+"  and over..\n"+NORM);
     write(GRN+"    and over..\n"+NORM);
     write(RED+"      and over again\n"+NORM);
     write("  with the battlestaff.\n");
     say(name+" attacks "+attacker->query_name()+" with a barrage of jabs.\n");
     return 3;
    } 
  }

  
