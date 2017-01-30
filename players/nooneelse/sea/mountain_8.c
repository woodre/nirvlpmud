/*
 mountain_8.c
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
      "players/nooneelse/sea/mountain_12", "north",
      "players/nooneelse/sea/mountain_9", "east",
      "players/nooneelse/sea/mountain_7", "west",
      "players/nooneelse/sea/mountain_4", "south",
    });
  if (!present("bee")) {
    monster=clone_object("obj/monster");
    monster->set_name("wasp");
    monster->set_level(9);
    monster->set_hp(180);
    monster->set_wc(15);
    monster->set_ac(9);
    monster->set_al(0);
    monster->set_ep(13000);
    monster->set_short("A giant wasp");
    monster->set_long("A 3' long honey wasp, with a huge stinger and "+
                     "powerful mandibles.\n");
    monster->set_aggressive(0);
    treasure=clone_object("obj/money");
    treasure->set_money(250);
    move_object(treasure, monster);
    move_object(monster, this_object());
  }
}
