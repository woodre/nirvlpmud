#include "/players/softly/closed/define.h"
#include "/players/softly/closed/ansi.h"
inherit "/players/softly/closed/std/room";

reset(arg){
  if(!present("stfolk")){ 
    move_object(clone_object("players/softly/algiers/mobs/folks.c"),this_object());
  }

  if(arg) return;
  set_light(1);

  short_desc = "Edge of Town";
  long_desc ="\n"+
    "  A broad dirt road stands at the edge of a small town. Brown\n\
patches of grass dot the landscape, with an occasional ancient\n\
gnarled tree interspersed.  A rare flower peeks from the earth.\n\
The grey sky is mottled with patches of blue.  The road bends to\n\
the northeast and widens to the south.\n";


  items = ({
    "earth",
    "The hard soil makes it difficult for flowers to grow",
    "weeds",
    "Drying weeds grown in random patterns",
    "grasses", 
    "Green and brown clumps of grass dot the earth",
    "earth", 
    "The brown earth is packed hard",
    "branches", 
    "Low branches on the oaks look like children's playthings",
    "oaks",
    "Ancient gnarled oaks are scattered about",
    "town",
    "A few small buildings are visible to the south",
    "grass",
    "Small clumps of grasses and weeds sit in random\n\
patches on the side of the road",
    "tree",
    "Several ancient gnarled oaks are scattered across\n\
the earth.  Most have low branches and look as if\n\
they might be used by children for climbing",
    "flower",
    "Pink and white clover is in bloom",
    "sky",
    "A generally overcast sky breaks through in places\n\
to reveal a shining blue backdrop with a few puffy\n\
white clouds",
    "road",
    "The brown earthen road is very dusty",

  });
  dest_dir = ({
    "/players/softly/algiers/rooms/road3.c","northeast",
    "/players/softly/algiers/rooms/road5.c","south",
  });
}
