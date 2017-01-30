#include "/players/softly/closed/define.h"
#include "/players/softly/closed/ansi.h"
inherit "/players/softly/closed/std/room";

reset(arg){
  if(arg) return;
  set_light(1);

  short_desc = "Open Road";
  long_desc ="\n"+
    "  A few scattered pine and oak trees stand near the edges\n\
of a broad open road.  Its surface of brown earth is packed hard,\n\
but dust rises with each step.  Soft mist falls from the cloudless\n\
grey sky.  The road continues to the southwest and tapers into a\n\
forest trail to the north.\n";


  items = ({
    "dust",
    "The road is dry.  Particles rise with each step",
    "pines",
    "Scrub pines are clustered with oaks at the edge\n\
of a forest",
    "oaks",
    "Gnarled oaks are nestled with pines at the edge\n\
of a forest",
    "trees",
    "The pines and oaks are scraggly, as if struggling to\n\
grow in the hard packed earth",
    "road",
    "A broad road, no more than a wide path, is made of\n\
well-packed brown earth.  Its dusty surface has an\n\
occasional leaf and pebble on it",
    "earth",
    "The earth is the color of burnt sienna, a kind of\n\
yellow brown",
    "mist",
    "The mist is not heavy enough to form drops, but dampens\n\
everything it touches",
    "sky",
    "The sky appears to be a flat pale grey surface",   
    "trail", 
    "The trail of brown earth is covered with a light\n\
scattering of leaves and pine needles",
    "forest",
    "The forest is has many pine and oak trees.  It seems\n\
very old",
    "area",
    "Southward the trees thin to nothingness",
    "light",
    "In contrast to the dim forest, the bright grey light is blinding\n",
  });
  dest_dir = ({
    "/players/softly/algiers/rooms/road2.c","north",
    "/players/softly/algiers/rooms/road4.c","southwest",
  });
}
