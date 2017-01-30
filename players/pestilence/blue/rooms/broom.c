#include "/open/ansi.h"
#define TP this_player()
inherit "room/room";

reset(arg) {
  if(arg) return;

if (!present("tickety")) {
move_object(clone_object("/players/pestilence/blue/mob/tickety.c"),
        this_object()); }
short_desc = ""+CYN+"Blue's Bedroom"+NORM+"";
long_desc =
  "    This is Blue's Bedroom.  A fuzzy purple carpet stretches over the\n"+
  "floor.  Purple and white polka dot wallpaper covers the walls.  A\n"+
  "small bed sits pushed against the north wall beneath a window.  To the east\n"+
  "brings you back to the living room.\n";
set_light(1);

items = ({
  "carpet","A fuzzy purple carpet",
  "wallpaper","Purple and white polka dot wallpaper",
  "walls","Purple and white polka dot wallpaper covers the walls",
  "bed","A small bed just right for a dog",
  "stand","A normal bedside stand",
  "window","You can see the back lawn through the window",
  "spot","Blue's special spot, you can't quite see it all from here",
});

dest_dir = ({
  "/players/pestilence/blue/rooms/room1","east",
  "/players/pestilence/blue/rooms/bplace.c","west",

});

}
