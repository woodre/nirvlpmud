/*
 groad4.c - evil side of green road
*/

inherit "room/room";

object goblin, coins;

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc=("a gloomy path");
  no_castle_flag=1;
  long_desc="You are standing on a path in a gloomy forest.  "+
            "You sense evil everywhere.\n";
  items =
    ({
     "forest", "It is a dense forest.  The trees are too close together for\n"+
                "you to go anywhere except on the path.",
      "path", "It is a narrow, clear path.",
      "trees", 
        "The trees are twisted and diseased.  There are many thornbushes.",
      "tree", "The tree is twisted and diseased.  There are many thornbushes.",
      "thornbush", "The bush is thick and has long, dangerous thorns.",
      "thornbushes", "The bushes are thick and have long, dangerous thorns.",
      "bushes", "The bushes are thick and have long, dangerous thorns.",
      "bush", "The bush is thick and has long, dangerous thorns.",
      "thorns", "The thorns are long and sharp.",
      "thorn", "The thorn is long and sharp.",
    });
  dest_dir=
    ({
      "players/nooneelse/green/groad5", "north",
      "players/nooneelse/green/groad3", "south",
    });
  if (!present("goblin")) {
    goblin=clone_object("obj/monster");
    goblin->set_name("goblin");
    goblin->set_level(5);
    goblin->set_hp(40);
    goblin->set_wc(4);
    goblin->set_ac(4);
    goblin->set_al(-90);
    goblin->set_ep(21000);
    goblin->set_short("A goblin");
    goblin->set_long(
      "A 4' tall humanoid with dull orange skin and redish eyes.\n");
    goblin->set_aggressive(1);
    coins=clone_object("obj/money");
    coins->set_money(120);
    move_object(coins, goblin);
    move_object(goblin, this_object());
  }
  return;
}
