/************************************/
/*    Owner:      Vital@Nirvana     */
/*    Created:    12/18/00          */
/*    Modified:   1/4/01            */
/*    Realm:      Spaceport         */
/************************************/

#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"
#include "/players/vital/dest/include/spaceport.h"     /*area header */

inherit "room/room";

int rnd, i;

reset(arg) {
rnd = random(4);
	if(!present("human", this_object())) {
	  for(i=0; i < rnd; i++) {
	    human = CO(SPNPC+"human.c");
	    MO(human, TO);
	  }
	}
  if(!arg) {

set_light(1);

short_desc = "N.U.T.S. Concourse";
long_desc =
  "  The West Concourse\n\
This is the west concourse in the N.U.T.S. The walls and floors show the \n\
signs of great age and use. The air is musty, smells processed, and probably \n\
not very healthy. There is an odd looking door and window to the northwest \n\
and to the northeast you can see the N.U.T.S. security gates. The concourse \n\
extends on toward the south.\n ";

items = ({
  "concourse",
  "The concourses are like small cities where just about anything can be\n\
obtained. Many travellers spend hours here waiting for shuttles",
  "walls",
  "The steel alloy here is pitted and scarred. Edges are rounded and the\n\
shine is gone",
  "floors",
  "The floor has been smoothed by the passing of hundreds of billions of \
people",
  "signs",
  "Dirt, grime, and even the effects of time can be seen here",
  "door",
  "This odd-looking, small, "+YEL+"wooden"+NORM+" door. Perhaps if you \
'enter' \nthis door, you will find....",
  "window",
  "What first looked like a window, now can be seen as old movie posters \n\
that have bonded to the walls over time",
  "gates",
  "The initial area where passengers come to check in for their shuttle \
flights"
});

dest_dir = ({
    SPROOM+"swconcourse.c","south",
    SPROOM+"gate.c","northeast"
});
  }
}
init() {
  ::init();
  add_action("search_me","search");
  add_action("move_enter","enter");
  add_action("smell_me","smell");
}

search_me(str) {
  if(!str) {
    notify_fail("What are trying to search?\n");
    return 0;
  }
  else write("You search the "+str+" but find nothing.\n");
  return 1;
}

move_enter() {
  TP->MP("enter#"+SPROOM+"mdmshop.c");
  return 1;
}

smell_me(str) {
  if(!str) {
    notify_fail("What do you want to smell?\n");
    return 0;
  }
  else switch(str) {
    case "air": write("The musty air feels thick upon your lungs as you \
draw it into \nyour body. There is also a heavy metallic twang as if to \
tell you \nabout air processors that work to keep it minimally breathable.\n\
"); break;
    case "vital": write("Vital smells good. His odor brings to mind the \
beautiful spring \ndays of your youth that can never be equalled.\n"); break;
    default : write("You cannot smell "+str+" here.\n");
  }
  return 1;
}
