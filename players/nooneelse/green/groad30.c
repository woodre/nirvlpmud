/*
 groad30.c - good side of green road
*/

inherit "room/room";

object pixie, coins;

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
      "players/nooneelse/green/groad31", "north",
      "players/nooneelse/green/groad29", "south",
    });
  if (!present("pixie")) {
    pixie=clone_object("obj/monster");
    pixie->set_name("pixie");
    pixie->set_level(5);
    pixie->set_hp(40);
    pixie->set_wc(4);
    pixie->set_ac(4);
    pixie->set_al(90);
    pixie->set_ep(21000);
    pixie->set_short("A pixie");
    pixie->set_long(
           "A 2 1/2' tall humanoid with pointed ears and transparent wings.\n");
    pixie->set_aggressive(0);
    coins=clone_object("obj/money");
    coins->set_money(120);
    move_object(coins, pixie);
    move_object(pixie, this_object());
  }
  return;
}
