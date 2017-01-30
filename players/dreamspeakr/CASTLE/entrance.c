#include "/players/dreamspeakr/closed/ansi.h"
#define PATH "/players/dreamspeakr/CASTLE/"
#define TPN this_player()->query_name()
#define TP this_player()
inherit "room/room";

reset(arg) {
    if(!present("totem", this_object())){
      move_object(clone_object("/players/dreamspeakr/CASTLE/OBJ/totem.c"),this_object());
    }
  if(arg) return;
set_light(1);

short_desc = "City in the "+HIW+"Clouds"+NORM;
long_desc =
  "\tThis wonderful city floats high in the sky above Nirvana.  \n"+
  "The ground appears transparent but still able to hold a person's \n"+
  "weight.  A shimmering barrier keeps out those who do not have \n"+
  "permission to enter.\n";

items = ({
  "sky","A most soothing color of "+HIB+"blue"+NORM+".  You feel very \n"+
     "at peace as you gaze at it.\n",
  "ground","You gasp as you look down and see that you are walking on \n"+
     "a cloud.",
  "barrier","It almost mesmerizes you as you look at all the pretty \n"+
     "colors dancing within",
  "cloud","Soft white, floating in the heavens",
});

dest_dir = ({
	"room/forest9.c","out",
});

}
