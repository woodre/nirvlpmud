#include "/players/forbin/rev/blue/pathdef.h"
inherit "/players/vertebraker/closed/std/room";

reset(arg) {
  if(arg) return;
  short_desc = "The Grand Entrance";
  long_desc = 
    "Scattered all around are the remains of what was once a very\n"+
    "beautiful foyer.  There are several velvet upholstered chairs, all\n"+
    "rotted away, and many paintings, now chipped, beaten, and faded.\n"+
    "Nothing of value seems to have been left here.  To the north you\n"+
    "see an open space, while to east odd signs flash brightly.  A\n"+
    "strange blackness creeps into the room from a opening in the\n"+
    "western wall.\n";
  set_light(1);
  add_item("remains",
    "Rubble, chairs, paintings, and other junk fill the room");
  add_item(({"chair","chairs","upholstered chair","upholstered chairs",
             "velvet chair","velvet chairs","velvet upholstered chair",
             "velvet upholstered chairs"}),
    "The chairs look to have been high-backed and built in what is known\n"+
    "as the Victorian style.  Their shattered legs and armrests are very\n"+
    "intricately carved and the brilliant blue velvet covering is faded\n"+
    "and torn");
  add_item(({"painting","paintings"}),
    "There are a few landscapes, but the majority of the paintings are\n"+
    "portraits, most likely of the former owner and family");
  add_item(({"space","open space"}),
    "To the north, the foyer opens up");
  add_item(({"sign","signs"}),
    "There are signs in the room to the east, but the writing is too\n"+
    "small to make out what is written on them");
  add_item("blackness",
    "A forboding darkness swirls out of the opening to the west.  A\n"+
    "sense of cold dread surrounds it");
  add_item("room",
    "The room here is in total disarray");
  add_item(({"wall","western wall","opening"}),
    "A hole has been roughly torn into the western wall, almost as if\n"+
    "by a tremendous explosion.  An odd darkness swirls through this\n"+
    "large opening, dancing about the west portion of the room");
  add_exit(ROOT+"castle/entry1","north");
  add_exit(ROOT+"stores/storefront","east");
  add_exit(ROOT+"castle/pit_enter", "west");
  add_exit("/room/plane2", "out");
}
