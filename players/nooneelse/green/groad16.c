/*
 groad16.c - evil side of green road
*/

inherit "room/room";

object ettin, coins;

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
      "players/nooneelse/green/groad15", "north",
      "players/nooneelse/green/groad17", "south",
    });
  if (!present("ettin")) {
    ettin=clone_object("obj/monster");
    ettin->set_name("ettin");
    ettin->set_level(16);
    ettin->set_hp(180);
    ettin->set_wc(14);
    ettin->set_ac(11);
    ettin->set_al(-320);
    ettin->set_ep(94500);
    ettin->set_short("An ettin");
    ettin->set_long("A 13' tall humanoid with two heads, wearing skins.\n");
    ettin->set_aggressive(1);
    coins=clone_object("obj/money");
    coins->set_money(540);
    move_object(coins, ettin);
    move_object(ettin, this_object());
  }
  return;
}
