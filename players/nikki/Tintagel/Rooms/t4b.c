#include "/players/nikki/ansi.h"
#define TP this_player()
inherit "room/room";

reset(arg) {
   if(!arg) {
set_light(1);
short_desc = "Tower Anteroom";
long_desc = 
 "   The circular room gives an impression of simplicity.  A gigantic\n"+
 "table and chair are arranged in the middle of the spacious room.  A\n"+
 "pallet of straw and blankets lay on the floor a short distance from\n"+
 "the stairs.  A single torch burns right next to the stairs to help\n"+
 "illuminate the room.  There is also a window above the pallet.  The\n"+
 "stairs allow access to both the upper and lower levels of the tower.\n"+NORM;

items = ({
  "table","The top of the table sits about six feet high from the floor.\n"+
          "It is exquisitely carved from oak wood",
  "torch","The torch is made in a simple manner like the room.  The piece\n"+
          "of driftwood soaked in oil displays adequate light for the room",
  "room","A simple room with a few items of interest",
  "chair","The chair is as tall as the table and made from the same wood",
  "pallet","Straw is layed thickly over a large portion of the floor.\n"+
           "The blankets on top of the straw make the pallet look\n"+
           "like a comfortable place to sleep",
  "straw","The straw looks fresh and it is tucked under the blankets",
  "blankets","Ivory coloured, wool blankets lay neatly ontop of the straw",
  "window","The window looks down on the entryway of the tower and allows\n"+
           "light into the room",
  "stairs","The stairs give you access to both the upper tower and to\n"+
           "the exit downstairs",
  "tower","The tower is getting darker as you go further up the stairs",
  
});

dest_dir = ( {
    "players/nikki/Tintagel/Rooms/t4a.c", "down",
    "players/nikki/Tintagel/Rooms/t4c.c", "up",
});
}}

realm() { return "NT"; }