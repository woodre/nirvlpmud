/*
 romulan_crew1.c
*/

#include "/players/nooneelse/romulan/romulan_warbird.h"

inherit "room/room";

reset(arg) {
  int i;
  if (arg) return;

  set_light(1);
  short_desc=("Crew's Quarters");
  long_desc=
    "These are the quarters of some of the crew of this Romulan Warbird.\n"+
    "The deck, ceiling and walls are constructed of riveted gray steel.\n"+
    "Other than the four sleeping platforms riveted to the walls, the room\n"+
    "is bare.  There is one doorway leading out into the corridor.\n";
  no_castle_flag=1;
  items=
    ({
      "rivet", "A dull gray steel rivet",
      "rivets", "Dull gray steel rivets",
      "doorway", "An opening in the steel plates of the wall",
      "platform", "A platform made of smooth steel, riveted to the wall",
      "platforms", "Platforms made of smooth steel, riveted to the walls",
    });
  dest_dir=
    ({
      "players/nooneelse/romulan/romulan_corridor2", "starboard",
    });
  for (i=0; i < random(3); i++) make_crewman();
  return;
}

make_crewman() {
  object obj;
  obj = clone_object ("obj/monster");
  obj->set_name("romulan crewman");
  obj->set_alias("crewman");
  obj->set_alt_name("romulan");
  obj->set_level(10);
  obj->set_ep(200000);
  obj->set_hp(150);
  obj->set_al(-500);
  obj->set_race("romulan");
  obj->set_short("Romulan crewman");
  obj->set_long("Romulan crewman.\n");
  obj->set_ac(10);
  obj->set_wc(15);
  obj->set_aggressive(1);
  obj->set_move_at_reset();
  obj->set_whimpy(1);
  move_object(obj, this_object());
}

realm() { return "NT"; }
