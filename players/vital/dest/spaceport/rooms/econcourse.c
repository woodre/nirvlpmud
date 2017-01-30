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

int rnd,i;

reset(arg) {
rnd = random(2);
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
  "  The East Concourse\n\
This is the east concourse in the N.U.T.S. The walls and floors here are \n\
"+HIY+"dirtier"+NORM+" than elsewhere. The "+YEL+"light"+NORM+" is muffled \
and casts many "+BOLD+BLK+"shadows"+NORM+". There \nis a large, garrish sign \
to the northeast and drunken people stumble out the \nlarge door next to \
the sign. To the northwest you can see that the gates and \nthe concourse \
extends on toward the south.\n";

items = ({
  "concourse",
  "The concourses are like small cities where just about anything can be\n\
obtained. Many travellers spend hours here waiting for shuttles",
  "walls",
  "The steel alloy here is pitted and scarred. Edges are rounded and the\n\
shine is gone",
  "people",
  "The people here are disheveled and obviously inebriated",
  "floors",
  "The floor has been smoothed by the passing of hundreds of billions of \n\
people",
  "sign",
  HIY+"The "+HIB+"Bomb-"+NORM+RED+"Sh"+GRN+"elt"+CYN+"er "+HIW+":\n\
"+HIR+BLINK+"       OPEN"+NORM,
  "door",
  "Massive blast doors that look like they once offered protection. Today \n\
they only serve to offer a portal into "+HIG+"The "+HIR+"Bomb \
"+NORM+CYN+"Sh"+YEL+"elt"+MAG+"er"+NORM,
  "light",
  "The "+HIW+"light"+NORM+" "+BLINK+"flickers and occassionally goes in and \
"+BLK+"out"+NORM+"",
  "gates",
  "The initial area where passengers come to check in for their shuttle \
flights",
  "shadow",
  "These are large, "+BOLD+BLK+"dark places where things cannot be seen",
  "shadows",
  "These are large, "+BOLD+BLK+"dark places where things cannot be seen"
});

dest_dir = ({
    SPROOM+"gate.c",        "northwest",
    SPROOM+"seconcourse.c", "south",
    SPROOM+"bombbar.c",     "northeast"
});

  }
}

init() {
  ::init();
  add_action("search_me","search");
}

search_me(str) {
  if(!str) {
    notify_fail("What are trying to search?\n");
    return 0;
  }
  else write("You search the "+str+" but find nothing.\n");
  return 1;
}