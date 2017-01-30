/*
  maze_x.c
*/

inherit "room/room";

realm() { return "NT"; }

reset(arg) {
  object doppleganger_obj;
  if (arg) return;

  set_light(0);
  short_desc = "A plain white room";
  no_castle_flag=1;
  long_desc =
    "Your senses reel as you enter this stark white.\n"+
    "Your eyes hurt as they strugle to focus on something.  Anything.\n"+
    "Though you see nothing in the room, you sense danger from an\n"+
    "unknown source.\n";
  dest_dir =
    ({
      "players/nooneelse/red/maze_x1", "north",
      "players/nooneelse/red/maze_x2", "east",
      "players/nooneelse/red/maze_x3", "south",
      "players/nooneelse/red/maze_x4", "west",
      "players/nooneelse/red/study", "down",
    });
}
