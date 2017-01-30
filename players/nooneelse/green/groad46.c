/*
 groad46.c - good side of green road
*/

inherit "room/room";

object fox, coins;

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
      "players/nooneelse/green/groad47", "north",
      "players/nooneelse/green/groad45", "south",
    });
  if (!present("fox")) {
    fox=clone_object("obj/monster");
    fox->set_name("fox");
    fox->set_level(19);
    fox->set_hp(240);
    fox->set_wc(17);
    fox->set_ac(14);
    fox->set_al(400);
    fox->set_ep(126000);
    fox->set_short("A fox");
    fox->set_long("A quick, smart, fox with sharp teeth.\n");
    fox->set_aggressive(0);
    coins=clone_object("obj/money");
    coins->set_money(720);
    move_object(coins, fox);
    move_object(fox, this_object());
  }
  return;
}
