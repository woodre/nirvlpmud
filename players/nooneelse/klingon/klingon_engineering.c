/*
 klingon_engineering.c
*/

#include "/players/nooneelse/klingon/klingon_ship.h"

inherit "room/room";

reset(arg) {
  object obj;
  if (arg) return;

  set_light(1);
  short_desc=("the Engineering Section");
  long_desc=
    "This is the engineering section of this Klingon scout ship.\n"+
    "You hear a low, deep humming comming from the powerful engines.\n";
    "The deck, ceiling and walls are constructed of riveted gray steel.\n"+
    "There is one doorway leading forward into a corridor, another\n"+
    "leading to the transporter room and steel ladders leading to a\n"+
    "level above and another below.\n";
  no_castle_flag=1;
  items=
    ({
      "rivet", "A dull gray steel rivet",
      "rivets", "Dull gray steel rivets",
      "doorway", "An opening in the steel plates of the wall",
      "doorways", "Openings in the steel plates of the walls",
      "ladder", "A steel runged ladder leading through the plates "+
                "of the ceiling",
      "ladders", "Steel runged ladders leading through the plates "+
                 "of the ceiling and the floor",
      "engine", "A totally incomprehensible, flashing and humming device\n"+
                "provides this ship with energy",
      "engines", "Totally incomprehensible, flashing and humming devices\n"+
                 "provide this ship with energy",
    });
  dest_dir=
    ({
      "players/nooneelse/klingon/klingon_corridor5", "fore",
      "players/nooneelse/klingon/klingon_transporter", "port",
      "players/nooneelse/klingon/klingon_phaser", "up",
      "players/nooneelse/klingon/klingon_torpedo", "down",
    });
  obj = clone_object ("obj/monster");
  obj->set_name("Klingon engineer");
  obj->set_alias("engineer");
  obj->set_alt_name("klingon");
  obj->set_level(16);
  obj->set_ep(800000);
  obj->set_hp(750);
  obj->set_al(-500);
  obj->set_race("klingon");
  obj->set_short("Klingon engineer");
  obj->set_long("Klingon engineer.\n");
  obj->set_ac(16);
  obj->set_wc(20);
  obj->set_aggressive(1);
  move_object(clone_object("/players/nooneelse/klingon/klingon_communicator"),
              obj);
  move_object(obj, this_object());
  return;
}

realm() { return "NT"; }
