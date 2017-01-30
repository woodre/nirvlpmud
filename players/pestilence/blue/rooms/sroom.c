#include "/open/ansi.h"
#define TP this_player()
inherit "room/room";

reset(arg) {
  if(arg) return;

if (!present("steve")) {
  move_object(clone_object("/players/pestilence/blue/mob/steve.c"),
        this_object()); }
short_desc = "Steve's Bedroom";
long_desc =
  "    This is Steve's bedroom.  The walls are dark green with light green\n"+
  "stripes.  On the east wall there is a dresser made of oak, with a mirror\n"+
  "above it. At the southern end of the room there is a closet.  A bed sits in the \n"+
  "center of the room.\n";
set_light(1);

items = ({
  "walls","The walls are dark green with light green stripes",
  "wall","The wall is dark green with light green stripes",
  "dresser","An oak dresser that holds most of Steve's clothes with a mirror above it",
  "mirror","A mirror, you can see your reflection in it",
  "closet","You can't see what's in it, but it's open so go south and find out",
  "blankets","Green blankets on Steve's bed",
  "bed","A double bed with green blankets where Steve sleeps",
});

dest_dir = ({
  "/players/pestilence/blue/rooms/closet.c","south",
  "/players/pestilence/blue/rooms/hall.c","west",

});

}
