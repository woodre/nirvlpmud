#include "../def.h"
inherit ROOM;
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="Copper Street";
  long_desc=
"    Copper street bends to the west here, but the rampant\n"+
"poverty and filth continues unabated.  An impromptu garbage\n"+
"heap sits in the middle of the street, preventing most people\n"+
"from going west unless they have pressing business.\n";
  items=({
    "garbage","You see numerous odds and ends, stuff even the most\n"+
           "desperate can't find a use for.  There's nothing\n"+
           "useful to you here",
    
    "heap","You see numerous odds and ends, stuff even the most\n"+
           "desperate can't find a use for.  There's nothing\n"+
           "useful to you here"
  });
  dest_dir=({
    PATH+"Haven/copper1","north",
    PATH+"Haven/copper3","west",
  });
}   
