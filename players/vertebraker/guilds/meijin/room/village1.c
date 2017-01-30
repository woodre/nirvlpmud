inherit "room/room";

reset(arg) {
  if(!arg) {
  set_light(1);
  short_desc="Before the Village";
  long_desc=
    "You are now walking between the grass huts of this lonely\n"+
    "village.  A hut to the east is open, but you cannot see\n"+
    "into its dark entryway.  The trail continues northeast,\n"+
    "where you can see a large circle of stones.\n";

  items=({
  "hut",
  "A tiny hut to the east appears to be open",
  "huts",
  "A small gathering of non-descrip huts lays before you",
  "trail",
  "The trail is well worn here",
  "stones",
  "You cannot tell anything about the stones from here",
  });

  dest_dir=({
    "/players/vertebraker/guilds/meijin/room/entrance", "south",
    "/players/vertebraker/guilds/meijin/room/village2", "northeast",
  });

  }
}

init() {
  ::init();
  add_action("east","east");
}

east() {
  write("You enter the small hut ... \n");
  this_player()->move_player("into the hut#players/pavlik/guild/room/join");
  return 1;
}

