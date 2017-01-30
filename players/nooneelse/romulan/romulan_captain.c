/*
 romulan_captain.c
*/

#include "/players/nooneelse/romulan/romulan_warbird.h"

inherit "room/room";

reset(arg) {
  object obj;
  if (arg) return;

  set_light(1);
  short_desc=("Captain's Quarters");
  long_desc=
    "This is the Captain's quarters of this Romulan Warbird.\n"+
    "The deck, ceiling and walls are constructed of riveted gray steel.\n"+
    "Other than the sleeping platform riveted to the wall, the room is\n"+
    "bare.  There is one doorway leading out into the corridor.\n";
  no_castle_flag=1;
  items=
    ({
      "rivet", "A dull gray steel rivet",
      "rivets", "Dull gray steel rivets",
      "doorway", "An opening in the steel plates of the wall",
      "platform", "A platform made of smooth steel, riveted to the wall",
    });
  dest_dir=
    ({
      "players/nooneelse/romulan/romulan_corridor1", "starboard",
    });
  obj = clone_object ("obj/monster");
  obj->set_name("Romulan Captain");
  obj->set_alias("captain");
  obj->set_alt_name("romulan");
  obj->set_level(20);
  obj->set_ep(2000000);
  obj->set_hp(750 + random(250));
  obj->set_spell(400);
  obj->set_al(-500);
  obj->set_race("romulan");
  obj->set_short("Romulan Captain");
  obj->set_long("Romulan Captain\n");
  obj->set_ac(19);
  obj->set_wc(25);
  obj->set_aggressive(1);
  obj->set_chance(70);
  obj->set_spell_mess2("You are awestruck by the Captain's ferocity!");
  obj->set_spell_mess1("You are amazed by the Captain's ferocity!\n");
  obj->set_spell_dam(20);
  move_object(clone_object("/players/nooneelse/romulan/romulan_armor"), obj);
  move_object(clone_object("/players/nooneelse/romulan/romulan_phaser"),
              obj);
  move_object(clone_object("/players/nooneelse/romulan/romulan_communicator"),
              obj);
  move_object(obj, this_object());
  return;
}

realm() { return "NT"; }
