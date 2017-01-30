inherit "room/room";

reset(arg) {
  if(!arg) {
  set_light(1);
  short_desc="On the Trail";
  long_desc=
    "You continue on the narrow mountain trail.  The footing\n"+
    "is less stable here but you see the top of the mountain\n"+
    "is not much further ahead.  Don't look down!\n";

  dest_dir=({
    "/players/pavlik/guild/room/entrance", "up",
    "/players/pavlik/guild/room/trail1", "down",
  });

  }
}

