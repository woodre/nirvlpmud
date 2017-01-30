/*
 groad43.c - good side of green road
*/

inherit "room/room";

object deer, coins;

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
      "players/nooneelse/green/groad44", "north",
      "players/nooneelse/green/groad42", "west",
    });
  if (!present("deer")) {
    deer=clone_object("obj/monster");
    deer->set_name("deer");
    deer->set_level(17);
    deer->set_hp(175);
    deer->set_wc(15);
    deer->set_ac(12);
    deer->set_al(375);
    deer->set_short("A deer");
    deer->set_long("A huge, powerful looking deer.\n");
    deer->set_aggressive(0);
    coins=clone_object("obj/money");
    coins->set_money(600);
    move_object(coins, deer);
    move_object(deer, this_object());
  }
  return;
}
