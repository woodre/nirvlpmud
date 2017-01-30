/*
 mountain_2.c
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
      "players/nooneelse/sea/mountain_6", "north",
      "players/nooneelse/sea/mountain_3", "east",
      "players/nooneelse/sea/mountain_4", "west",
      "players/nooneelse/sea/mountain_1", "south",
    });
  if (!present("bee")) {
    monster=clone_object("obj/monster");
    monster->set_name("bee");
    monster->set_level(7);
    monster->set_hp(60);
    monster->set_wc(13);
    monster->set_ac(6);
    monster->set_al(0);
    monster->set_ep(10500);
    monster->set_short("A giant bee");
    monster->set_long("A 3' long honey bee, with a huge stinger and "+
                     "powerful mandibles.\n");
    monster->set_aggressive(0);
    treasure=clone_object("obj/food");
    treasure->set_name("honey");
    treasure->set_short("A ball honey");
    treasure->set_long("A ball of sticky, sweet honey.\n");
    treasure->set_value(100);
    treasure->set_weight(1);
    treasure->set_strength(20);
    treasure->set_eater_mess(
      "You pop the honey into your mouth and lick your fingers clean.\n"+
      "Mmmmmm.  That tasted good!");
    treasure->set_eating_mess(
      "Eats some honey and licks their fingers clean.\n");
    move_object(treasure, monster);
    move_object(monster, this_object());
  }
}
