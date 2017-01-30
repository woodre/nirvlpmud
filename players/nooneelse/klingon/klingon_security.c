/*
 klingon_security.c
*/

#include "/players/nooneelse/klingon/klingon_ship.h"

inherit "room/room";

init() {
  ::init();

  add_action("aft", "aft");
}

aft() {
  if (present("security officer") || present("security guard")) {
    tell_room(this_object(),
        "The Klingon steps into the doorway, preventing "+
        this_player()->query_name()+"'s entry.\n");
    return 1;
  }
  if (!present("klingon security key", this_player())) {
    tell_room(this_object(),
        "A brilliant black spark flashes in the doorway, preventing "+
        this_player()->query_name()+"'s entry.\n");
    return 1;
  }
}

reset(arg) {
  object obj;
  if (arg) return;

  set_light(1);
  short_desc=("the Security Section");
  long_desc=
    "This is the security section of this Klingon scout ship.  The\n"+
    "deck, ceiling and walls are constructed of riveted gray steel.\n"+
    "You see several specialized scanners, data terminals and a communicator\n"+
    "for use by the security officer.  There is one doorway leading aft to\n"+
    "the weapon locker and another leading out into the corridor.\n";
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
      "communicator", "A special communicator that's built into the steel\n"+
                      "wall and has a special security code for access\n",
    });
  dest_dir=
    ({
      "players/nooneelse/klingon/klingon_corridor1", "port",
      "players/nooneelse/klingon/klingon_weapon_locker", "aft",
    });
  obj = clone_object ("obj/monster");
  obj->set_name("Klingon Security Officer");
  obj->set_alias("security officer");
  obj->set_alt_name("klingon");
  obj->set_level(14);
  obj->set_ep(600000);
  obj->set_hp(550);
  obj->set_al(-500);
  obj->set_race("klingon");
  obj->set_short("Klingon Security Officer");
  obj->set_long("Klingon Security Officer.\n");
  obj->set_ac(14);
  obj->set_wc(17);
  obj->set_aggressive(1);
  move_object(clone_object("/players/nooneelse/klingon/klingon_blaster"), obj);
  move_object(clone_object("/players/nooneelse/klingon/klingon_captain_key"),
              obj);
  move_object(obj, this_object());
  obj = clone_object ("obj/monster");
  obj->set_name("Klingon Security Guard");
  obj->set_alias("security guard");
  obj->set_alt_name("klingon");
  obj->set_level(12);
  obj->set_ep(400000);
  obj->set_hp(350);
  obj->set_al(-500);
  obj->set_race("klingon");
  obj->set_short("Klingon Security Guard");
  obj->set_long("Klingon Security Guard.\n");
  obj->set_ac(12);
  obj->set_wc(15);
  obj->set_aggressive(1);
  move_object(clone_object("/players/nooneelse/klingon/klingon_dagger"), obj);
  move_object(obj, this_object());
  return;
}

realm() { return "NT"; }
