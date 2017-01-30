#include "../defs.h"

inherit ROOM;

void reset(int arg) {
  if(!present("kaiser"))
    move_object(clone_object(NPCDIR+"kaiser.c"),this_object());
  if(arg) return;
  set_light(1);
  move_object(clone_object(OBJDIR+"summoning_circle.c"),this_object());
  short_desc="Kaiser's Hut";
  long_desc=
"  This is obviously the residence of someone who regularly works with\n\
magic.  To one side of the room, shoved out of the way, is an unmade\n\
bed.  On the wall next to it is a fireplace with a crackling fire.  The\n\
rest of the room is taken up by a huge, incredibly intricate summoning\n\
circle with various spell components placed at carefully designated\n\
points.\n";
  items=({
    "bed","A bed.  It's not made",
    "fireplace","A fireplace.  It's lit",
    "circle","A large, incredibly elaborate summoning circle with complex\n"+
             "interlocking runes forming a pattern.  As you stare closer\n"+
             "at the circle, you realize that the pattern seems to blur\n"+
             "in your mind as you look at it",
    "components","You have difficulty focusing upon the inside of the summoning\n"+
                 "circle",
  });
  dest_dir=({
    ROOMDIR+"plaza.c","out",
  });
}
