#include "/players/fred/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

object kenny;
reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Kenny's House";
long_desc =
"  The room is full of old junk and cardboard boxes.  A green\n"+
"sofa sits against the wall and there are 2 old mattresses laid\n"+  
"out on the floor.  A lamp sitting on a stack of books provides\n"+
"the only light source\n";

items = ({
  "sofa",
  "It is very old, the cushions are dirty and torn.  You can see\n"+
  "what remains of the stuffing sticking out", 
  "wall",
  "The wallpaper is falling off the wall and needs to be replaced badly", 
  "mattresses",
  "They are in worse shape then the sofa.  You wonder how\n"+
  "anyone can sleep on them with all of the exposed springs",
  "floor",
  "Some of the boards are loose and it is covered in a\n"+
  "thick layer of dust",
  "junk",
  "A pile of old broken appliances that need fixing",
  "boxes",
  "'Kenny's school clothes' are written on the sides of them",
  "lamp",
  "It has an antique looking base and is missing the lampshade",
  "books",
  "They are old 'How To' books from Bob Villa", 
  });

dest_dir = ({
  "/players/fred/SP/Rooms/r6.c","out",
  });
  kenny = clone_object("/players/fred/SP/Mon/kenny.c");
  move_object(kenny, this_object());
}
