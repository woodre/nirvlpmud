/*
 groad37.c - good side of green road
*/

inherit "room/room";

object unicorn, coins;

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc=("a pretty path");
  no_castle_flag=1;
  long_desc="You are standing on a path in a pretty forest.  "+
            "You sense good everywhere.\n";
  items =
    ({
      "forest", "It is a dense forest.  The trees are too close together for\n"+
                "you to go anywhere except on the path.",
      "path", "It is a narrow, clear path.",
      "trees", "The trees are strong and healthy.  "+
               "The ground is covered with soft grass.",
      "tree", "The tree is strong and healthy.  "+
              "The ground is covered with soft grass.",
      "grass", "The grass is long, soft and comforatable to walk on.",
    });
  dest_dir=
    ({
      "players/nooneelse/green/groad38", "south",
      "players/nooneelse/green/groad36", "north",
    });
  if (!present("unicorn")) {
    unicorn=clone_object("obj/monster");
    unicorn->set_name("unicorn");
    unicorn->set_level(14);
    unicorn->set_hp(140);
    unicorn->set_wc(12);
    unicorn->set_ac(9);
    unicorn->set_al(260);
    unicorn->set_ep(73500);
    unicorn->set_short("A unicorn");
    unicorn->set_long("An 8' tall white horse with a horn in it's forehead.\n");
    unicorn->set_aggressive(0);
    coins=clone_object("obj/money");
    coins->set_money(420);
    move_object(coins, unicorn);
    move_object(unicorn, this_object());
  }
  return;
}
