#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
#include <ansi.h>


reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "The Caves of the "+HIG+"Green "+NORM+GRN+"Dragon Clan"+NORM;
long_desc =
" This is a large open cavern.  A huge hole spans most of the\n"+
"distance across the room leading down into an even larger\n"+
"chamber. A small stream of lava flows down the wall to your\n"+
"right. A tunnel leads further into the volcano to the west.\n";

items = ({
"hole",
"A huge hole that spans most of the chamber and leads down into\n"+
"a larger room",
"stream",
"A small stream of molten rock that flows from the wall to a\n"+
"crack in the floor",
"crack",
"A large crack with lava flowing into it",
"lava",
"Molten hot rock",
"wall",
"A wall of black volcanic stone. It is smooth",
});

dest_dir = ({
  "/players/dragnar/SevenSpires/rooms/gdragon/r11.c","west",
  "/players/dragnar/SevenSpires/rooms/gdragon/r9.c","down"
});

}
