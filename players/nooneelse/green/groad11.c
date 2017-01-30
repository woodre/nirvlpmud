/*
 groad11.c - evil side of green road
*/

inherit "room/room";

object gargoyle, coins;

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
      "players/nooneelse/green/groad10", "west",
      "players/nooneelse/green/groad12", "east",
    });
  if (!present("gargoyle")) {
    gargoyle=clone_object("obj/monster");
    gargoyle->set_name("gargoyle");
    gargoyle->set_level(11);
    gargoyle->set_hp(100);
    gargoyle->set_wc(8);
    gargoyle->set_ac(7);
    gargoyle->set_al(-200);
    gargoyle->set_ep(52500);
    gargoyle->set_short("A gargoyle");
    gargoyle->set_long("A 5' tall humanoid with long pointed ears and a "+
                       "horn in it's forehead.\n");
    gargoyle->set_aggressive(1);
    coins=clone_object("obj/money");
    coins->set_money(300);
    move_object(coins, gargoyle);
    move_object(gargoyle, this_object());
  }
  return;
}
