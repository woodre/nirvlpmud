#include "DEF.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Hogwarts";
long_desc =
  "  This smooth, compacted dirt landing looks south upon a huge grass lawn that\n"+
  "runs all the way to the lake in the distance.  Immediately to your north is a\n"+
  "set of huge doors.  The structure curves around you to the east and west and\n"+
  "forbids passage in either of those directions.\n";

items = ({
"landing",
  "This area is the entryway into the castle to the north of it.  Because of\n"+
  "its sheer size, a great many people could stand here waiting to get in.\n"+
  "It is black and worn smooth by the feet of many who have crossed over it",
"lawn",
  "An expansive green with lush, thick grass growing across it almost as\n"+
  "if it were manicured",
"structure",
  "A giant castle with 4 corner spires that reach up into the mist.  This\n"+
  "massive structure is made of solid rock and appears to be cut into the\n"+
  "side of a large cliff.  Huge double doors with ornate knockers stand a\n"+
  "the rear of the large, stone entry",
"lake",
  "Large, dark and forboding, this swirling, frothy body of water looks to\n"+
  "churned up by something big underneath its surface",
"doors",
  "The largest doors you've ever seen.  They measure 6 feet wide and 10 feet\n"+
  "high with no handles to open then.  At eye height is a set of door\n"+
  "knockers",
  "knockers",
  "Ornate, polished knockers that resemble a golden broomstick hung by the\n"+
  "handle.  It lookes like a simple 'knock knock' might get you in",
});

dest_dir = ({
  "players/eurale/Pot/hw1.c","south",
});

}

realm() { return "NT"; }

init() {
  ::init();
  add_action("Knock","knock");
}

Knock(str) {
if(!str) {
  write("A spider crawls by whispering 'knock twice for entry'\n");
  return 1; }
if(str != "knock") {
  write("A mouse scurries by squeaking 'try again'\n");
  return 1; }
write("The huge doors open quickly sucking you into the building with a whoosh!\n");
TP->move_player("into the building#players/eurale/Pot/hw3.c");
return 1;
}
