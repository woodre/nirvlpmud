/*
 groad24.c - evil side of green road
*/

inherit "room/room";

object bat, coins;

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
      "players/nooneelse/green/groad49", "east",
      "players/nooneelse/green/groad23", "south",
    });
  if (!present("bat")) {
    bat=clone_object("obj/monster");
    bat->set_name("bat");
    bat->set_level(20);
    bat->set_hp(260);
    bat->set_wc(18);
    bat->set_ac(15);
    bat->set_al(-500);
    bat->set_ep(136500);
    bat->set_short("A giant bat");
    bat->set_aggressive(1);
    coins=clone_object("obj/money");
    coins->set_money(780);
    move_object(coins, bat);
    move_object(bat, this_object());
  }
  return;
}
