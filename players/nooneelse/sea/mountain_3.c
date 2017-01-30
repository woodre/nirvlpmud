/*
 mountain_3.c
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
      "players/nooneelse/sea/mountain_7", "north",
      "players/nooneelse/sea/mountain_4", "east",
      "players/nooneelse/sea/mountain_2", "west",
      "players/nooneelse/sea/mountain_11", "south",
    });
  if (!present("troll")) {
    monster=clone_object("obj/monster");
    monster->set_name("troll");
    monster->set_level(8);
    monster->set_hp(100);
    monster->set_wc(13);
    monster->set_ac(7);
    monster->set_al(-100);
    monster->set_ep(11000);
    monster->set_short("A troll");
    monster->set_long("A troll, with a huge club powerful muscles.\n");
    monster->set_aggressive(1);
    treasure=clone_object("obj/weapon");
    treasure->set_name("club");
    treasure->set_class(12);
    treasure->set_weight(3);
    treasure->set_value(550);
    treasure->set_short("A club");
    treasure->set_long("A large, rough, wooden club.\n");
    move_object(treasure, monster);
    move_object(monster, this_object());
  }
}
