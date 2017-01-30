inherit "room/room";

reset(arg) {
  if(!arg) {
  set_light(1);
  short_desc="On the Trail";
  long_desc=
    "This narrow trail leads up the steep mountain side.  The\n"+
    "winding trail looks easy enough to navigate, but one false\n"+
    "step could be fatal.  The mountain towers above you, its\n"+
    "summit is nearly lost in the clouds.\n";

  dest_dir=({
    "/players/pavlik/guild/room/trail2", "up",
    "/room/eastroad2", "down",
  });

  }
}

