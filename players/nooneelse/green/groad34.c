/*
 groad34.c - good side of green road
*/

inherit "room/room";

object centaur, coins;

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
      "players/nooneelse/green/groad35", "west",
      "players/nooneelse/green/groad33", "south",
    });
  if (!present("centaur")) {
    centaur=clone_object("obj/monster");
    centaur->set_name("centaur");
    centaur->set_level(11);
    centaur->set_hp(100);
    centaur->set_wc(8);
    centaur->set_ac(7);
    centaur->set_al(200);
    centaur->set_ep(52500);
    centaur->set_short("A centaur");
    centaur->set_long("An 8' tall horse with a human upper torso.\n");
    centaur->set_aggressive(0);
    coins=clone_object("obj/money");
    coins->set_money(300);
    move_object(coins, centaur);
    move_object(centaur, this_object());
  }
  return;
}
