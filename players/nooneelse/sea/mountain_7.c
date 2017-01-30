/*
 mountain_7.c
*/

inherit "room/room";

reset(arg) {
  object monster, treasure;
  if (arg) return;

  set_light(1);
  short_desc = "on a mountain";
  no_castle_flag=1;
  long_desc =
    "You are on the side of a dry rocky mountain.\n";
  dest_dir =
    ({
      "players/nooneelse/sea/mountain_11", "north",
      "players/nooneelse/sea/mountain_8", "east",
      "players/nooneelse/sea/mountain_9", "west",
      "players/nooneelse/sea/mountain_3", "south",
    });
  if (!present("ram")) {
    monster=clone_object("obj/monster");
    monster->set_name("ram");
    monster->set_level(8);
    monster->set_hp(200);
    monster->set_wc(13);
    monster->set_ac(8);
    monster->set_al(0);
    monster->set_ep(10500);
    monster->set_short("A large ram");
    monster->set_long("A large ram.\n");
    monster->set_aggressive(0);
    treasure=clone_object("obj/armor");
    treasure->set_name("sheepskin");
    treasure->set_short("A grey sheepskin");
    treasure->set_long("A heavy, grey hide from a ram.\n");
    treasure->set_value(320);
    treasure->set_weight(2);
    treasure->set_ac(2);
    treasure->set_type("armor");
    move_object(treasure, monster);
    move_object(monster, this_object());
  }
}
