/*
 klingon_crew3.c
*/

#include "/players/nooneelse/klingon/klingon_ship.h"

inherit "room/room";

reset(arg) {
  int i;
  if (arg) return;

  set_light(1);
  short_desc=("Crew's Quarters");
  long_desc=
    "These are the quarters of some of the crew of this Klingon scout ship.\n"+
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
      "players/nooneelse/klingon/klingon_corridor5", "port",
    });
  for (i=0; i < random(3); i++) make_crewman();
  return;
}

make_crewman() {
  object obj;
  obj = clone_object ("obj/monster");
  obj->set_name("klingon crewman");
  obj->set_alias("crewman");
  obj->set_alt_name("klingon");
  obj->set_level(10);
  obj->set_ep(200000);
  obj->set_hp(150);
  obj->set_al(-500);
  obj->set_race("klingon");
  obj->set_short("Klingon crewman");
  obj->set_long("Klingon crewman.\n");
  obj->set_ac(10);
  obj->set_wc(15);
  obj->set_aggressive(1);
  obj->set_move_at_reset();
  obj->set_whimpy(1);
  move_object(obj, this_object());
}

realm() { return "NT"; }
