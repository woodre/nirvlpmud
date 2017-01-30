/*
 groad33.c - good side of green road
*/

inherit "room/room";

object sprite, coins;

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
      "players/nooneelse/green/groad34", "north",
      "players/nooneelse/green/groad32", "south",
    });
  if (!present("sprite")) {
    sprite=clone_object("obj/monster");
    sprite->set_name("sprite");
    sprite->set_level(9);
    sprite->set_hp(80);
    sprite->set_wc(6);
    sprite->set_ac(6);
    sprite->set_al(150);
    sprite->set_ep(42000);
    sprite->set_short("A sprite");
    sprite->set_long("A 2' tall humanoid with pointed ears, transparent "+
                     "wings and antennae.\n");
    sprite->set_aggressive(0);
    coins=clone_object("obj/money");
    coins->set_money(240);
    move_object(coins, sprite);
    move_object(sprite, this_object());
  }
  return;
}
