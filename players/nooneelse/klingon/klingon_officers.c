/*
 klingon_officers.c
*/

#include "/players/nooneelse/klingon/klingon_ship.h"

inherit "room/room";

reset(arg) {
  object obj;
  if (arg) return;

  set_light(1);
  short_desc=("Gunnery & Transporter Officer's Quarters");
  long_desc=
    "This is the gunnery & transporter officer's quarters of this Klingon\n"+
    "scout ship.  The deck, ceiling and walls are constructed of riveted\n"+
    "gray steel.  Other than the three sleeping platforms riveted to the\n"+
    "walls, the room is bare.  There is one doorway leading out into the\n"+
    "corridor.\n";
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
      "players/nooneelse/klingon/klingon_corridor6", "starboard",
    });
  obj = clone_object ("obj/monster");
  obj->set_name("Klingon Phaser Officer");
  obj->set_alias("phaser officer");
  obj->set_alt_name("klingon");
  obj->set_level(14);
  obj->set_ep(600000);
  obj->set_hp(550);
  obj->set_al(-500);
  obj->set_race("klingon");
  obj->set_short("Klingon Phaser Officer");
  obj->set_long("Klingon Phaser Officer.\n");
  obj->set_ac(14);
  obj->set_wc(17);
  obj->set_aggressive(1);
  move_object(clone_object("/players/nooneelse/klingon/klingon_dagger"), obj);
  move_object(clone_object("/players/nooneelse/klingon/klingon_phaser_key"),
              obj);
  move_object(obj, this_object());
  obj = clone_object ("obj/monster");
  obj->set_name("Klingon Torpedo Officer");
  obj->set_alias("torpedo officer");
  obj->set_alt_name("klingon");
  obj->set_level(14);
  obj->set_ep(600000);
  obj->set_hp(550);
  obj->set_al(-500);
  obj->set_race("klingon");
  obj->set_short("Klingon Torpedo Officer");
  obj->set_long("Klingon Torpedo Officer.\n");
  obj->set_ac(14);
  obj->set_wc(17);
  obj->set_aggressive(1);
  move_object(clone_object("/players/nooneelse/klingon/klingon_dagger"), obj);
  move_object(clone_object("/players/nooneelse/klingon/klingon_torpedo_key"),
              obj);
  move_object(obj, this_object());
  obj = clone_object ("obj/monster");
  obj->set_name("Klingon Transporter Officer");
  obj->set_alias("transporter officer");
  obj->set_alt_name("klingon");
  obj->set_level(14);
  obj->set_ep(600000);
  obj->set_hp(550);
  obj->set_al(-500);
  obj->set_race("klingon");
  obj->set_short("Klingon Transporter Officer");
  obj->set_long("Klingon Transporter Officer.\n");
  obj->set_ac(14);
  obj->set_wc(17);
  obj->set_aggressive(1);
  move_object(clone_object("/players/nooneelse/klingon/klingon_dagger"), obj);
  return;
}

realm() { return "NT"; }
