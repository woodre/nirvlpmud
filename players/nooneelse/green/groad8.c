/*
 groad8.c - evil side of green road
*/

inherit "room/room";

object bugbear, coins;

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
      "players/nooneelse/green/groad9", "north",
      "players/nooneelse/green/groad7", "south",
    });
  if (!present("bugbear")) {
    bugbear=clone_object("obj/monster");
    bugbear->set_name("bugbear");
    bugbear->set_level(9);
    bugbear->set_hp(80);
    bugbear->set_wc(6);
    bugbear->set_ac(6);
    bugbear->set_al(-150);
    bugbear->set_ep(42000);
    bugbear->set_short("A bugbear");
    bugbear->set_long(
               "A 7' tall furry humanoid with yellowish skin and fangs.\n");
    bugbear->set_aggressive(1);
    coins=clone_object("obj/money");
    coins->set_money(240);
    move_object(coins, bugbear);
    move_object(bugbear, this_object());
  }
  return;
}
