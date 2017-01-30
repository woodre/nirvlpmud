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

object monster;

set_light(1);

short_desc = "N.U.T.S. Concourse";
long_desc =
  "  The Southeast Concourse\n\
This is the southeast concourse of the N.U.T.S. The dirty walls and floors \n\
seem to crowd in and create a suffocating space. The dim light here adds to \n\
the feeling of oppression. To the east you see two doors. You were sure \n\
there were guards here a moment ago. Where did they go?\n";

items = ({
  "concourse",
  "The concourses are like small cities where just about anything can be \n\
obtained. Many travellers spend hours here waiting for shuttles",
  "walls",
  "The steel alloy here is pitted and scarred. Edges are rounded and the \n\
shine is gone",
  "floors",
  "The floor has been smoothed by the passing of hundreds of billions of \
people",
  "space",
  "Though just as large as the rest of the concourse, this part seems all \n\
the smaller because of the "+BOLD+BLK+"dim"+NORM+" "+YEL+"light"+NORM+" and \n\
the dirt",
  "dirt",
  "The dirt is covering most things. It varies in shade from black to grey \n\
to brown",
  "light",
  "The "+BOLD+BLK+"dim"+NORM+" "+YEL+"light"+NORM+" casts shadows and makes \
the space seem \nsmaller than normal",
  "shadows",
  "The dark places created by the "+BOLD+BLK+"dim"+NORM+" "+YEL+"light"+NORM+" \
in this end of the concourse",
  "oppression",
  "The suffocating space, the "+BOLD+BLK+"dim"+NORM+" "+YEL+"light"+NORM+" \
and the dirt \nall press you down",
  "doors",
  "The first door has a sign over it. The second door is a dark black and \
unmarked",
  "door",
  "You need to look at the \'first\' or the \'second\' door",
  "first",
  "The \'first\' door leads toward a small shop and had a "+HIR+"red\
"+NORM+" sign",
  "second",
  "The second door is painted "+BLK+"black"+NORM+" and has no writing on it",
  "first door",
  "The first door leads toward a small shop and had a "+HIR+"red"+NORM+" sign",
  "second door",
  "The second door is painted "+BLK+"black"+NORM+" and has no writing on it",
  "guards",
  "Here one moment, gone the next. Tall men in dark "+BLU+"blue"+NORM+" \
uniforms",
  "sign",
  "N.U.T.S. "+HIW+"Duty Free Shop"+NORM
});

dest_dir = ({
    SPROOM+"econcourse.c","north",
    "firstblank","first",
    "secondblank","second"
  });
  }
}

init() {
  ::init();
  add_action("search_me","search");
  add_action("move_first","first");
  add_action("move_second","second");
}

search_me(str) {
  if(!str) {
    notify_fail("What are trying to search?\n");
    return 0;
  }
  else write("You search the "+str+" but find nothing.\n");
  return 1;
}

move_first() {
  write("You walk into the Duty Free Shop.\n");
  TP->MP("in the first door#"+SPROOM+"dutyfree.c");
  return 1;
}

move_second() {
  write("You cannot get the door open.\n");
  return 1;
}
