/*
 cellar8.c
*/

inherit "room/room";

realm() { return "NT"; }

reset(arg) {
  if (arg) return;

  set_light(0);
  short_desc = "coffin room";
  no_castle_flag=1;
  long_desc =
    "This small room is completely empty except for a large wooden\n"+
    "box in the far corner.\n";
  items =
    ({
      "box", "The box is strangly shaped and has a hinged top.\n"+
             "It is large enough for a human to lay down in",
    });
  dest_dir =
    ({
      "players/nooneelse/red/cellar7", "east",
    });
  if (!find_living("nooneelsevampiress"))
    move_object(clone_object("players/nooneelse/mon/vampiress"), this_object());
}
