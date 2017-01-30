/*
 groad5.c - evil side of green road
*/

inherit "room/room";

object skeleton, coins;

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc=("a gloomy path");
  no_castle_flag=1;
  long_desc="You are standing on a path in a gloomy forest.  "+
            "You sense evil everywhere.\n"+
            "Beside the road, you see a small clearing and the "+
            "remains of an old graveyard.\n";
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
      "clearing",
        "It is a small clear area in the bushes, with a graveyard filling it.",
      "graveyard", "The marker stones are all crumbling and broken.",
      "stones", "They are are all crumbling and broken.",
      "stone", "It is crumbling and broken.",
      "markers", "They are are all crumbling and broken.",
      "marker", "It is crumbling and broken.",
    });
  dest_dir=
    ({
      "players/nooneelse/green/groad6", "north",
      "players/nooneelse/green/groad4", "south",
    });
  if (!present("skeleton")) {
    skeleton=clone_object("obj/monster");
    skeleton->set_name("skeleton");
    skeleton->set_level(7);
    skeleton->set_hp(60);
    skeleton->set_wc(5);
    skeleton->set_ac(5);
    skeleton->set_al(-120);
    skeleton->set_ep(31500);
    skeleton->set_short("A skeleton");
    skeleton->set_long("A 6' tall human skeleton.\n");
    skeleton->set_aggressive(1);
    coins=clone_object("obj/money");
    coins->set_money(180);
    move_object(coins, skeleton);
    move_object(skeleton, this_object());
  }
  return;
}
