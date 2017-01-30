/*
 sunroom.c
*/

inherit "room/room";

object dog, coins;

init() {
  ::init();

  add_action("sniff", "sniff");
}

sniff() {
  write("You sniff & discover that all the plants have rotted & smell bad.\n");
  return 1;
}

reset(arg) {
  if (arg) return;

  set_light(0);
  short_desc = "sunroom";
  no_castle_flag=1;
  long_desc =
    "The ceiling of this tall room is ringed with windows placed high up on\n"
    + "the walls.  Most of the windows have been blocked by heavy wooden\n"
    + "shutters, but one pair of has blown open.  The unshuttered window\n"
    + "is cracked, but not broken out.  Many vases stand around the room,\n"
    + "but the flowers in them are all wilted.  You smell the strong, harsh\n"
    + "odor of something.\n";
  items =
    ({
      "window", "It is a cracked window.",
      "windows", "All but one are covered by sturdy wooden shutters.",
      "crack",
        "The crack runs from corner to corner, diagonaly across the window.",
      "shutters", "Sturdy wooden shutters.",
      "shutter", "A sturdy wooden shutter.",
      "vases", "Various sized ceramic and stone vases.",
      "vase", "A sturdy looking vase.",
      "flowers", "Wilted, dead plants.",
      "flower", "A wilted, dead plant.",
      "plants", "Wilted, dead flowers.",
      "plant", "A wilted, dead flower.",
    });
  dest_dir =
    ({
      "players/nooneelse/red/ballroom", "north",
      "players/nooneelse/red/study", "east",
      "players/nooneelse/red/hall", "south",
      "players/nooneelse/red/dressing", "west"
    });
  if (!present("dog")) {
    make_dogs();
    make_dogs();
    make_dogs();
    make_dogs();
    make_dogs();
  }
}

make_dogs() {
  dog=clone_object("obj/monster");
  dog->set_name("dog");
  dog->set_alt_name("nooneelsedog");
  dog->set_level(4);
  dog->set_hp(25);
  dog->set_wc(10);
  dog->set_ac(4);
  dog->set_ep(700);
  dog->set_al(0);
  dog->set_short("a dog");
  dog->set_long("It's a mangy, ugly, nasty looking, dog.\n");
  dog->set_whimpy(1);
  dog->set_aggressive(1);
  coins=clone_object("obj/money");
  coins->set_money(6+random(20));
  move_object(coins, dog);
  move_object(dog, this_object());
}
