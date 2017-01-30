/*
 groad19.c - evil side of green road
*/

inherit "room/room";

object hellhound, coins;

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc=("a gloomy path");
  no_castle_flag=1;
  long_desc="You are standing on a path in a gloomy forest.  "+
            "You sense evil everywhere.\n"+
            "The foilage seems to have scorch marks on them.\n";
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
      "players/nooneelse/green/groad20", "north",
      "players/nooneelse/green/groad18", "east",
    });
  if (!present("hellhound")) {
    hellhound=clone_object("obj/monster");
    hellhound->set_name("hellhound");
    hellhound->set_alt_name("hell hound");
    hellhound->set_alias("hound");
    hellhound->set_level(17);
    hellhound->set_al(-375);
    hellhound->set_hp(200);
    hellhound->set_ep(105000);
    hellhound->set_short("A hell hound");
    hellhound->set_long("A large sooty black hound with glowing red eyes.\n");
    hellhound->set_aggressive(1);
    hellhound->set_wc(15);
    hellhound->set_ac(12);
    coins=clone_object("obj/money");
    coins->set_money(600);
    move_object(coins, hellhound);
    move_object(hellhound, this_object());
  }
  return;
}
