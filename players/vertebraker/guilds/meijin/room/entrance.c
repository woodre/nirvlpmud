inherit "room/room";
#include "/players/vertebraker/guilds/meijin/room/room.h";

reset(arg) {
  if(!arg) {
  set_light(1);
  short_desc="Before the Village";
  long_desc=
    "You stand at the head of a mountain trail.  The air is crisp\n"+
    "and crystal clear.  A small village of grass-sewn huts lies\n"+
    "before you.  Behind you, the small winding trail leads back\n"+
    "down the mountain.\n";

  items=({
  "huts",
  "A small gathering of non-descrip huts lays before you",
  "trail",
  "The trail is well worn here",
  });

  dest_dir=({
    "/players/vertebraker/guilds/meijin/room/village1", "north",
    "/players/vertebraker/guilds/meijin/room/trail2", "down",
  });

  }
}

init() {
  ::init();
  add_action("xmove", "xmove");
}

