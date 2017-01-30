/*
 klingon_science.c
*/

#include "/players/nooneelse/klingon/klingon_ship.h"

inherit "room/room";

reset(arg) {
  object obj;
  if (arg) return;

  set_light(1);
  short_desc=("the Science Section");
  long_desc=
    "This is the science section of this Klingon scout ship.  The\n"+
    "deck, ceiling and walls are constructed of riveted gray steel.\n"+
    "You see several specialized scanners and data terminals for use\n"+
    "by the Science Officer.  There is one doorway leading aft to the\n"+
    "Medical Section and another leading out into the corridor.\n";
  no_castle_flag=1;
  items=
    ({
      "rivet", "A dull gray steel rivet",
      "rivets", "Dull gray steel rivets",
      "doorway", "An opening in the steel plates of the wall",
      "doorways", "Openings in the steel plates of the walls",
      "scanner", "A specialized device that's built into the steel wall\n"+
                 "and has a special security code for access\n",
      "scanners", "Specialized devices that are built into the steel walls\n"+
                  "and have special security codes for access\n",
      "terminal", "A specialized information device that's built into the\n"+
                  "steel wall and has a special security code for access\n",
      "terminals", "Specialized information devices that are built into the\n"+
                   "steel walls and have special security codes for access\n",
    });
  dest_dir=
    ({
      "players/nooneelse/klingon/klingon_corridor1", "starboard",
      "players/nooneelse/klingon/klingon_medical", "aft",
    });
  obj = clone_object ("obj/monster");
  obj->set_name("Klingon Science Officer");
  obj->set_alias("science officer");
  obj->set_alt_name("klingon");
  obj->set_level(16);
  obj->set_ep(800000);
  obj->set_hp(750);
  obj->set_al(-500);
  obj->set_race("klingon");
  obj->set_short("Klingon Science Officer");
  obj->set_long("Klingon Science Officer.\n");
  obj->set_ac(16);
  obj->set_wc(20);
  obj->set_aggressive(1);
  move_object(clone_object("/players/nooneelse/klingon/klingon_scanner"), obj);
  move_object(obj, this_object());
  return;
}

realm() { return "NT"; }
