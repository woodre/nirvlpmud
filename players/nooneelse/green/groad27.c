/*
 groad27.c - good side of green road
*/

inherit "room/room";

object brownie, coins;

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
      "players/nooneelse/green/groad28", "north",
      "players/nooneelse/green/groad26", "west",
    });
  if (!present("brownie")) {
    brownie=clone_object("obj/monster");
    brownie->set_name("brownie");
    brownie->set_level(3);
    brownie->set_hp(20);
    brownie->set_wc(3);
    brownie->set_ac(3);
    brownie->set_al(60);
    brownie->set_ep(10500);
    brownie->set_short("A brownie");
    brownie->set_long(
      "A 1 1/2' tall humanoid with long pointed ears and nose.\n");
    brownie->set_aggressive(0);
    coins=clone_object("obj/money");
    coins->set_money(60);
    move_object(coins, brownie);
    move_object(brownie, this_object());
  }
  return;
}
