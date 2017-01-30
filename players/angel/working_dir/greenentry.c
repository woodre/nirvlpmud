/*
 greenentry.c
*/

inherit "room/room";

string str;

object fork;

int fork_is_gone;

init() {
  ::init();

  add_action("get_fork", "get");
  add_action("get_fork", "take");
}

get_fork(str) {
  if (!str) return;
  if (fork_is_gone) return;
  if (str == "fork" || str == "all") {
    say(this_player()->query_name()+" picks up the silver fork.\n");
    fork=clone_object("obj/treasure");
    fork->set_id("fork");
    fork->set_alias("silver fork");
    fork->set_short("a fork");
    fork->set_long("A nice, silver fork.\n");
    fork->set_value(10);
    fork->set_weight(1);
    move_object(fork, this_player());
    fork_is_gone = 1;
    write("Ok.\n");
    if (str=="fork") return 1;
    if (str=="all") return 0;
  }
}

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc=("a fork in the path");
  no_castle_flag=1;
  fork_is_gone=0;
  long_desc=
    "You are standing under an awning at a fork in the path.\n"+
    "There are two torches attached to stone pillars that provide light.\n"+
    "To the west, the forest looks gloomy, to the east, it looks pretty.\n";
  items =
    ({
      "forest", "It is a dense forest.  The trees are too close together for\n"+
                "you to go anywhere except on the path.",
      "path", "It is a narrow, clear path.",
      "trees", "The trees are strong and tall.",
      "tree", "The tree is strong and tall.",
      "fork", "It is a very nice looking silver fork.",
      "awning", "It is a study awning, roofed with leafy branches.",
      "torch", "It is a metal torch that looks like it will burn forever.",
      "torches",
        "They are metal torches that look like they will burn forever.",
      "pillar", "It is a very sturdy looking stone pillar.",
      "pillars", "They are very sturdy looking stone pillars.",
    });
  dest_dir=
    ({
      "players/nooneelse/dim", "south",
      "players/nooneelse/green/groad1", "west",
      "players/nooneelse/green/groad25", "east",
    });
  return;
}
