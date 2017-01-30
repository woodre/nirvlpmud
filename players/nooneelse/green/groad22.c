/*
 groad22.c - evil side of green road
*/

inherit "room/room";

object triffid, coins;

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
      "players/nooneelse/green/groad23", "north",
      "players/nooneelse/green/groad21", "south",
    });
  if (!present("triffid")) {
    triffid=clone_object("obj/monster");
    triffid->set_name("triffid");
    triffid->set_level(19);
    triffid->set_hp(240);
    triffid->set_wc(17);
    triffid->set_ac(14);
    triffid->set_al(-400);
    triffid->set_ep(126000);
    triffid->set_short("A triffid");
    triffid->set_long("A 7' tall plant with a single tulip-like flower "+
                      "at the top and 3 leg-like roots.\n");
    triffid->set_aggressive(1);
    coins=clone_object("obj/money");
    coins->set_money(720);
    move_object(coins, triffid);
    move_object(triffid, this_object());
  }
  return;
}
