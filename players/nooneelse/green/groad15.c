/*
 groad15.c - evil side of green road
*/

inherit "room/room";

object minotaur, coins;

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
      "players/nooneelse/green/groad16", "south",
      "players/nooneelse/green/groad14", "north",
    });
  if (!present("minotaur")) {
    minotaur=clone_object("obj/monster");
    minotaur->set_name("minotaur");
    minotaur->set_level(15);
    minotaur->set_hp(160);
    minotaur->set_wc(13);
    minotaur->set_ac(10);
    minotaur->set_al(-290);
    minotaur->set_ep(84000);
    minotaur->set_short("A minotaur");
    minotaur->set_long("A 7' tall humanoid with the head of a bull.\n");
    minotaur->set_aggressive(1);
    coins=clone_object("obj/money");
    coins->set_money(480);
    move_object(coins, minotaur);
    move_object(minotaur, this_object());
  }
  return;
}
