#include "/players/pestilence/ansi.h"
#define TP this_player()
inherit "room/room";

reset(arg) {
  if(arg) return;

short_desc = ""+YEL+"Cahara Island Path"+NORM+"";
long_desc =
  "    Thick trees and foliage surround the whole area.  The\n"+
  "path seems to have died here.  There is a large rock to\n"+
  "the north.  In all other directions the trees and foliage\n"+
  "are so thick, that there is no way to move except for the\n"+
  "small path leading back to the southwest.\n";
set_light(1);

items = ({
  "rock","A large rock with a hole in the center",
  "hole","A hole large enough for a person to enter",
  "trees","Large green trees surround the area",
  "foliage","Green foliage fill the ground",
  "path","A small worn path leding to the southwest",
});

dest_dir = ({
  "/players/pestilence/Cahara/room/path.c","southwest",
});
}

init () {
   ::init() ;
     add_action ("enter_hole","enter");
     }

enter_hole(str) {
   if(str != "hole") { write("Enter what?\n");
       return 1;}

     write("You enter a dark cave.\n");
     TP->move_player("enter#/players/pestilence/Cahara/room/cave.c");
     return 1;}
