#include "/open/ansi.h"
#define TP this_player()
#define TPN this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;

if (!present("lizant")) {
  move_object(clone_object("/players/pestilence/amity/mob/lizant.c"),
        this_object()); }

short_desc = ""+BLU+"Bedroom"+NORM+"";
long_desc =
  "    This is the bedroom of the house.  This room is very large.\n"+
  "There is a king-sized bed pushed against the east wall.  Next to\n"+
  "the bed there is a small stand with a lamp on it.  A dresser sits\n"+
  "against the north wall.  There is a plush blue carpet that extends\n"+
  "from wall to wall.\n";
set_light(1);

items = ({
"bed","A king-sized bed with a blue comforter, and two pillows sit against the east wall",
"stand","A small wooden stand with one drawer sits next to the bed, with a lamp on it",
"lamp","A small white lamp sitting on a stand",
"dresser","A white dresser, with gold handles on the three drawers sits against the north wall",
"carpet","A plush blue carpet covering the entire floor",
"wall","The wall has a light blue wallpaper with flowers on it",
"walls","The walls have a light blue wallpaper with flowers on it",
"north wall","The wall is light blue, with a dress pushed up against it",
"east wall","The wall is light blue, with the bed against it",
"flowers","Daisies on the wallpaper",
"wallpaper","Light blue wallpaper with flowers on it",
});

dest_dir = ({
"/players/pestilence/amity/room/madhouse3.c","west",
});
}
