/*
 groad49.c - the end of the green road (from both good & evil sides)
*/

inherit "room/room";

object garlic;

init() {
  ::init();

/* taken out 3/22/97 nooneelse - to stop garlic from comming from here
   (make them find the sphinx in the mountains)
  add_action("sniff", "sniff");
*/
}

sniff() {
  write("You sniff and discover what the stong odor was.  "+
        "You find a clove of garlic.\n");
  if (!present("garlic") && !present("garlic", this_player()))
    move_object(clone_object("players/nooneelse/obj/garlic"), this_object());
  return 1;
}

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc=("a forest clearing");
  no_castle_flag=1;
  long_desc=
    "You are standing in a clearing in a forest.  "+
    "As you look around, you realise\n"+
    "the path you entered on has disappeared!  You smell something strong.\n";
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
      "players/nooneelse/greenentry", "south",
    });
/* taken out 3/22/97 nooneelse - stop sphinx from being here
  if (!find_living("nooneelsesphinx"))
    move_object(clone_object("players/nooneelse/mon/sphinx"), this_object());
*/
  return;
}
