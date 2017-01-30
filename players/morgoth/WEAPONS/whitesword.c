#include "/players/feldegast/closed/ansi.h"
inherit "obj/weapon";

reset(arg)
{
  if (arg) return;
  ::reset(arg);
  set_name("white sword");
  set_alias("sword");
  set_short("The "+HIW+"White"+NORM+" Sword");
  set_long("The Sword of Wind is very light.  It makes a distinctive\n"+
           "swoosh as it cuts through the air.  The power of a thousand\n"+
           "tornados eminates from it's handle into your arm.\n");
  set_type("sword");
  set_value(1200);
  set_weight(4);
  set_class(18); /* Raised from 15. -Feldegast 10-6-2000 */
  set_hit_func(this_object());
}

weapon_hit(attacker)
{
  if(this_player()->query_attrib("luc") > random(70)) {
    tell_room(environment(attacker),HIC+"The Wind Sword slices through the air with the strength of a thousand tornados!\n"+NORM);
    return 6;
  }
}
