/*
 groad2.c - evil side of green road
*/

inherit "room/room";

object kobold, coins;

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
      "players/nooneelse/green/groad1", "east",
      "players/nooneelse/green/groad3", "west",
    });
  if (!present("kobold")) {
    kobold=clone_object("obj/monster");
    kobold->set_name("kobold");
    kobold->set_level(3);
    kobold->set_hp(20);
    kobold->set_wc(3);
    kobold->set_ac(3);
    kobold->set_al(-60);
    kobold->set_ep(10500);
    kobold->set_short("A kobold");
    kobold->set_long("A 3' tall hairless humanoid with rusty brown skin "+
                     "and 2 horns in it's forehead.\n");
    kobold->set_aggressive(1);
    coins=clone_object("obj/money");
    coins->set_money(60);
    move_object(coins, kobold);
    move_object(kobold, this_object());
  }
  return;
}
