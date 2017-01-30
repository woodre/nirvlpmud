#include "/players/catacomb/misc/ansi.h"
inherit "/obj/weapon.c";
#define TPN this_player()->query_name()

reset (arg) {
  ::reset(arg);
  if(arg) return;

  set_name("scepter");
  set_alias("mace");
  set_short("A "+HIY+"deco"+HIC+"rated"+NORM+" scepter");
  set_long(
 "  The scepter is made of some sort of metal, possibly mithril.\n"+
 "On the head of the shaft is a crown of some kind.  The crown\n"+
 YEL+"glows"+NORM+" with an inner light.\n" );

  set_type("mace");
  set_class(17);
  set_weight(3);
  set_value(1500);

  set_hit_func(this_object()); 
}
mixed
weapon_hit(object attacker) 
{
   string name;
    if(environment() && environment()->is_player()) {
    name=(string)environment()->query_name(); }
    if(!name) return 0;

    if(random (15) <= 3)
    {
     write("\n      The scepter glows bright as \n");
     write(HIW+"       HOLY LIGHT\n"+NORM);
     write(  "      shreds through your enemy.\n");
     say(TPN+" sends a volley of holy light into "+attacker->query_name()+".\n");
     return 3;
    } 
}

  
