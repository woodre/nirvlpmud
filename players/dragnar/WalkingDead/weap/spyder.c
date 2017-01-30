inherit "obj/weapon";

#include <ansi.h>
#include "../defs.h"

reset(arg) {
    ::reset(arg);
  if(arg) return;

  set_name("spyder");
  set_class(19);
  set_weight(1);
  set_value(2000);
  set_type("bow");
  set_alias("hoyt");
  set_alt_name("hoyt spyder");
  set_short(BOLD+"Hoyt "+HIBLK+"Spyder"+NORM+" Bow");
  set_long(
"A compact but powerful compound bow with attached quiver. A model\n\
made by Hoyt, it is extremely lightweight but still powerful and\n\
durable. It has a viper grip and uses "+GRY+"AirShox Technology"+NORM+" to be\n\
almost silent. The compact design allows it to be used in tight\n\
spaces. In all, a perfect weapon for silently killing Walkers.\n");
  SetMultipleIds( ({ "hoyt spyder bow", "walkerobj" }) );

  set_params("physical",4);
}

wield(string str)
{
  if(id(str) && present(this_object(), this_player()) &&
    this_player()->query_weapon() == this_object()){
    ::wield(str);
    return 1;
  }
  ::wield(str);
  if(id(str))
  {
    if(!present(this_object(), this_player())) return 0;
    if(this_player()->is_npc()) return 0;
    set_class(19);
    if(this_player()->query_total_stats() < 210){
      set_class(14);
      write("You fumble around and finally flip the safety off.\n");
    }
    else {
      write("You draw back the string on the bow effortlessly.\n");
      say(capitalize(this_player()->query_name())+" looks deadly as "+this_player()->query_pronoun()+" tests the string on the Spyder.\n");
    }

    return 1;
  }
}

query_wear() {
  return 1;
}

weapon_breaks() {
  return 1;
}

query_walker_value() { return TIER_4_VALUE + random ( TIER_4_RAND ); }
