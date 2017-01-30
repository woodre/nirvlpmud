/*
 groad44.c - good side of green road
*/

inherit "room/room";

object gnome, coins;

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
      "players/nooneelse/green/groad45", "north",
      "players/nooneelse/green/groad43", "south",
    });
  if (!present("gnome")) {
    gnome=clone_object("obj/monster");
    gnome->set_name("gnome");
    gnome->set_level(18);
    gnome->set_hp(220);
    gnome->set_wc(16);
    gnome->set_ac(13);
    gnome->set_al(395);
    gnome->set_ep(115500);
    gnome->set_short("A gnome");
    gnome->set_long("An exceptionally strong and powerful gnome.\n");
    gnome->set_aggressive(0);
    coins=clone_object("obj/money");
    coins->set_money(660);
    move_object(coins, gnome);
    move_object(gnome, this_object());
  }
  return;
}
