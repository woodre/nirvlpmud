/*
 groad48.c - good side of green road
*/

inherit "room/room";

object dwarf, coins;

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
      "/players/nooneelse/green/groad49", "west",
      "/players/nooneelse/green/groad47", "south",
    });
  if (!present("dwarf")) {
    dwarf=clone_object("/obj/monster");
    dwarf->set_name("dwarf");
    dwarf->set_level(20);
    dwarf->set_hp(260);
    dwarf->set_wc(18);
    dwarf->set_ac(15);
    dwarf->set_al(500);
    dwarf->set_ep(136500);
    dwarf->set_short("A dwarf");
    dwarf->set_long("A sturdy looking dwarf with bulging muscles.\n");
    dwarf->set_aggressive(0);
    coins=clone_object("/obj/money");
    coins->set_money(780);
    move_object(coins, dwarf);
    move_object(dwarf, this_object());
  }
  return;
}
