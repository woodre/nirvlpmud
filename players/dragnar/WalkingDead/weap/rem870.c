inherit "obj/weapon";

#include <ansi.h>
#include "../defs.h"

reset(arg) {
    ::reset(arg);
  if(arg) return;

  set_name("shotgun");
  set_class(20);
  set_weight(3);
  set_value(2000);
  set_type("gun");
  set_alias("870");
  set_alt_name("remington");
  set_short(BOLD+"Remington "+HIBLK+"870 Express"+NORM+" Shotgun");
  set_long(
"A compact but powerful 12 gauge shotgun with a pistol grip and a\n\
SuperCell recoil pad. It has a matte black finish and holds up to\n\
7 rounds. Reliable and deadly, this is a perfect weapon for taking\n\
out Walkers.\n");
  SetMultipleIds( ({ "remington 870 express shotgun", "walkerobj" }) );

  set_params("physical",5);
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
    set_class(20);
    if(this_player()->query_total_stats() < 240){
      set_class(15);
      write("You fumble around and finally flip the safety off.\n");
    }
    else {
      write("You pump a round into the chamber with satisfying click.\n");
      say(capitalize(this_player()->query_name())+" smiles sinisterly as "+this_player()->query_pronoun()+" pumps the action on the 870.\n");
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

query_walker_value() { return TIER_2_VALUE + random ( TIER_2_RAND ); }
