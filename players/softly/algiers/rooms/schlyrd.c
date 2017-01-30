#include "/players/softly/closed/define.h"
#include "/players/softly/closed/ansi.h"
inherit "/players/softly/closed/std/room";

int i;

reset(arg){
  if(!present("kids"))
    { 
      for(i=0;i<2;i++) {
	move_object(clone_object("players/softly/algiers/mobs/kids.c"),this_object());
      }
    }

  if(arg) return;
  set_light(1);

  short_desc = "School yard";
  long_desc ="\n"+
    "  A small yard with patches of grass covering some of the\n\
earth sits between a road and a small brown wooden schoolhouse.\n\
Two hand made swings and a few weathered tables sit in the yard.\n";

  items = ({
    "yard",
    "A space of earth surrounding the small school house",
    "grass",
    "Scruffy tan and green grass grows in irregular shapes",
    "windows",
    "Small faces show at the small screen-covered windows",
    "earth",
    "The brown earth is dusty, with patches of grass",
    "road",
    "The brown earthen road runs north and south through\n\
the town of Algiers.  It is very dusty",
    "schoolhouse",
    "A wooden building barely contains the voices of the children within",
    "swings",
    "Wooden standards hold two tire swings",
    "tables",
    "Small greyed tables sit near the schoolhouse door",
  });

  dest_dir = ({
    "/players/softly/algiers/rooms/road14.c","east",
    "/players/softly/algiers/rooms/aschl.c","enter",
  });
}
