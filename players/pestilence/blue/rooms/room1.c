#include "/open/ansi.h"
#define TP this_player()
inherit "room/room";

reset(arg) {
  if(arg) return;

if (!present("table")) {
  move_object(clone_object("/players/pestilence/blue/mob/table.c"),
        this_object()); }
short_desc = ""+CYN+"Living Room"+NORM+"";
long_desc =
  "    This is the entry way that opens up into a big room.  The walls\n"+
  "are covered in peach and pink wallpaper.  Plush pink carpet spreads over\n"+
  "the floor.  Pushed against the west wall sits a large overstuffed chair.  Hanging\n"+
  "above the chair is a picture.   To the north is the kitchen and to the\n"+
  "west is Blue's bedroom.\n";

set_light(1);

items = ({
  "chair","A very large overstuffed red chair used for thinking",
  "picture","A picture of a racetrack, maybe you could 'skidoo' there",
  "racetrack","A picture of a racetrack, maybe you could 'skidoo' there",
  "wallpaper","Pink and peach colored wallpaper cover the wall",
  "carpet","Plush pink carpet covers the floor from wall to wall",
  "wall","A wall covered in peach and pink wallpaper",
  "kitchen","You can't quite see the kitchen from here maybe if you moved north",
  "bedroom","Blue's bedroom is to the west, where you just can't quite see it from here",
});

dest_dir = ({
  "/players/pestilence/blue/rooms/broom.c","west",
  "/players/pestilence/blue/rooms/kitchen.c","north",
 "/players/pestilence/blue/rooms/hall.c","east",
  "/players/pestilence/blue/rooms/front.c","south",
});

}
init() {
  ::init();
  add_action("skidoo","skidoo");
}

skidoo() {
  TP->move_player("skidoo#/players/pestilence/blue/rooms/track.c");
  return 1; }
