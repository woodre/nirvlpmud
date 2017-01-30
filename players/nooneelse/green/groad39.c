/*
 groad39.c - good side of green road
*/

inherit "room/room";

object hawk, coins;

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
      "players/nooneelse/green/groad40", "south",
      "players/nooneelse/green/groad38", "north",
    });
  if (!present("hawk")) {
    hawk=clone_object("obj/monster");
    hawk->set_name("hawk");
    hawk->set_level(15);
    hawk->set_hp(160);
    hawk->set_wc(13);
    hawk->set_ac(10);
    hawk->set_al(-290);
    hawk->set_ep(84000);
    hawk->set_short("A large hawk");
    hawk->set_aggressive(0);
    coins=clone_object("obj/money");
    coins->set_money(480);
    move_object(coins, hawk);
    move_object(hawk, this_object());
  }
  return;
}
