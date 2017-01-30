#include "/players/softly/closed/define.h"
#include "/players/softly/closed/ansi.h"
inherit "/players/softly/closed/std/room";

reset(arg){
  if(arg) return;
  set_light(1);

  short_desc = "Thin Forest";
  long_desc ="\n"+
    "  The damp dusty trail of brown earth is frosted with leaves\n\
and pine needles.  Movement is easy and light streams through the\n\
thin forest.  A soft mist is falling.  The trail leads north to\n\
a clutch of pines and oaks and south to an open area.\n";


  items = ({
    "pines",
    "Scrub pines are clustered with oaks at the edge\n\
of a forest",
    "oaks",
    "Gnarled oaks are nestled with pines at the edge\n\
of a forest",
    "needles",
    "A dusting of brown crushed pine needles coats the trail",
    "leaves",
    "Brown crushed oak leaves mix with pine needles to\n\
lightly cover the trail",
    "mist",
    "The air is white with mist making it hard to see",
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
    "/players/softly/algiers/rooms/road1.c","north",
    "/players/softly/algiers/rooms/road3.c","south",
  });
}
