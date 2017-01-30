#include "/players/fred/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "South Park";
long_desc =
"  You are on the main road heading through South Park.  There are\n"+
"cars driving down the busy streets.  Some people are going in and\n"+ 
"out of a few small shops.  A meter maid is putting a ticket on an\n"+
"illegally parked car.\n";

items = ({
  "streets",
  "The street made of blask asphalt and has several potholes in it",
  "potholes",
  "They are about 8 inches deep on average and have puddles of water\n"+
  "forming in them",
  "shops",
  "They are very clean and have little open signs on the doors",
  "doors",
  "They are light screen doors that blow open and shut in the breeze",
  "cars",
  "They are moving slowly down the street avoiding the many potholes",
  "maid",
  "She is writing out a ticket",
  "car",
  "The car is old and starting to rust.  The license plate is almost\n"+
  "falling off",
  "license",
  "It reads: MMmkay",
  "plate",
  "It reads: MMmkay",
  });

dest_dir = ({
  "/players/fred/SP/Rooms/r1.c","west",
  "/players/fred/SP/Rooms/r5.c","east",
  });
}
