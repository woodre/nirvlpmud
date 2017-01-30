/*
 groad40.c - good side of green road
*/

inherit "room/room";

object elf, coins;

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc=("a pretty path");
  no_castle_flag=1;
  long_desc="You are standing on a path in a pretty forest.  "+
            "You sense good everywhere.\n";
  items =
    ({
      "forest", "It is a dense forest.  The trees are too close together for\n"+
                "you to go anywhere except on the path.",
      "path", "It is a narrow, clear path.",
      "trees", "The trees are strong and healthy.  "+
               "The ground is covered with soft grass.",
      "tree", "The tree is strong and healthy.  "+
              "The ground is covered with soft grass.",
      "grass", "The grass is long, soft and comforatable to walk on.",
    });
  dest_dir=
    ({
      "players/nooneelse/green/groad41", "south",
      "players/nooneelse/green/groad39", "north",
    });
  if (!present("elf")) {
    elf=clone_object("obj/monster");
    elf->set_name("elf");
    elf->set_level(16);
    elf->set_hp(180);
    elf->set_wc(14);
    elf->set_ac(11);
    elf->set_al(320);
    elf->set_ep(94500);
    elf->set_short("A tall, thin elf");
    elf->set_aggressive(0);
    coins=clone_object("obj/money");
    coins->set_money(540);
    move_object(coins, elf);
    move_object(elf, this_object());
  }
  return;
}
