inherit "obj/weapon";

#include <ansi.h>
#include "../defs.h"

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("glock");
  set_class(19);
  set_weight(2);
  set_type("gun");
  set_alias("pistol");
  set_alt_name("40");
 
  set_value( 1800 );
  SetMultipleIds( ({ "glock pistol", "walkerobj" }) );
  
  set_short( HIBLK+"Glock"+NORM+" Pistol" );
  set_long( "A Glock .40 caliber pistol. This one of the most reliable\n\
pistols ever made. The finish is a flat matte black. A good Walker killer\n\
but the lack of a silencer makes it loud.\n" );
  set_params("physical", 5);
  
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
    if(this_player()->query_total_stats() < 210 ){
      set_class(12);
      write("You fumble around and finally flip the safety off.\n");
    }
    else {
      write("You slam a magazine into the Glock with a satisfying click.\n");
      say(capitalize(this_player()->query_name())+" looks determined as "+this_player()->query_pronoun()+" slams a magazine into the Glock.\n");
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
