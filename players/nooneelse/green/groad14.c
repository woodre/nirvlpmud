/*
 groad14.c - evil side of green road
*/

inherit "room/room";

object cyclops, coins;

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
      "players/nooneelse/green/groad13", "north",
      "players/nooneelse/green/groad15", "south",
    });
  if (!present("cyclops")) {
    cyclops=clone_object("obj/monster");
    cyclops->set_name("cyclops");
    cyclops->set_level(15);
    cyclops->set_hp(160);
    cyclops->set_wc(13);
    cyclops->set_ac(10);
    cyclops->set_al(-260);
    cyclops->set_ep(73500);
    cyclops->set_short("A cyclops");
    cyclops->set_long(
      "A 7 1/2' tall hunanoid with one eye in the center of it's face.\n");
    cyclops->set_aggressive(1);
    coins=clone_object("obj/money");
    coins->set_money(420);
    move_object(coins, cyclops);
    move_object(cyclops, this_object());
  }
  return;
}
