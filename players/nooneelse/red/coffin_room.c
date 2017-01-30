/*
  coffin_room.c
*/

inherit "room/room";

realm() { return "NT"; }

reset(arg) {
  if (arg) return;

  set_light(0);
  short_desc = "coffin room";
  no_castle_flag=1;
  long_desc =
    "Your senses reel as you enter this deep blood red colored room.\n"
    + "Your eyes are drawn to the only relief from the disturbing color\n"
    + "of this room.  There is a large, gleaming black box sitting on a\n"
    + "dias of a deep red stone.\n";
  items =
    ({
      "box", "This appears to be a very expensive coffin.",
      "coffin", "This appears to be a very expensive coffin.",
      "dias", "It looks like it is made of one huge, blood red, ruby.",
      "stone", "The dias looks like it is made of one huge, blood red, ruby.",
      "walls", "They are made of warm, dark red stone.",
      "wall", "It is made of warm, dark red stone.",
    });
  dest_dir =
    ({
      "players/nooneelse/red/maze_entrance", "south",
    });
  if (!find_living("nooneelsevampire"))
         move_object(clone_object("players/nooneelse/mon/vampire"),
                     this_object());
}
