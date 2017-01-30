#include "/open/ansi.h"
#define TP this_player()
inherit "room/room";

reset(arg) {
  if(arg) return;

if (!present("rabbit")) {
  move_object(clone_object("/players/pestilence/blue/mob/rabbit.c"),
        this_object()); }
short_desc = "Race Track";
long_desc =
  "    This is the race track that was in the picture.  This is a small oval track\n"+
  "that is paved, with white lines on the outside.  There seems to be a race going\n"+
  "on right now.\n";
set_light(1);

items = ({
  "track","A track with black pavement and white lines",
  "pavement","Black pavement with white lines",
  "lines","White lines border the pavement on both sides",
  "animals","A bunch of assorted animals riding toys",
  "toys","A bunch of assorted toys made for riding",
  "race","A race with few animals riding different toys",

});

dest_dir = ({
  "/players/pestilence/blue/rooms/room1.c","back",

});

}
