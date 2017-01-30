/************************************/
/*    Owner:      Vital@Nirvana     */
/*    Created:    12/18/00          */
/*    Modified:   12/26/00          */
/*    Realm:      Spaceport         */
/************************************/

#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"
#include "/players/vital/dest/include/spaceport.h"     /*area header */

inherit "room/room";

int rnd, i;

reset(arg) {
rnd = random(5);
  if(!present("human",this_object())) {
    for(i=0; i < rnd; i++) {
      human = CO(SPNPC+"human.c");
      MO(human, TO);
    }
  }
  if(!arg) {

  set_light(1);

  short_desc = "The N.U.T.S. Transitway";
  long_desc =
  "  The N.U.T.S. Transitway.\n\
This is the long hallway that connects the landing pad with the concourse \n\
gates. Though there are people moving all around, no one is actually \n\
walking. The floor seems to convey people along towards the end of the \n\
hallway without needing to walk. All they have to do is step on the right \n\
belt. A large "+RED+"red"+NORM+" belt is on the left side of the hallway \
and a large "+BLU+"blue"+NORM+" \nbelt is on the right side of the hallway.\n";

  items = ({
  "hallway",
  "This long hallway would be monotonous without the quick belts",
  "pad",
  "The pad is where the rho-craft land and take off",
  "concourse",
  "The concourses are like small cities where just about anything can be\n\
obtained. Many travellers spend hours here waiting for shuttles",
  "gates",
  "The gates are large, steel structures that are common throughout the\n\
spaceport. They look like they could withstand an attack or a shuttle\n\
"+RED+"explosion"+NORM,
  "people",
  "The people are fellow travellers and adventurers who \
are heading toward \n the landing pad \
or returning from some foreign destination",
  "floor",
  "At your feet are two large belts. One is "+RED+"red"+NORM+" and the other \
next to it is \n"+BLU+"blue"+NORM+". Perhaps you could step on one of them",
  "belt",
  "One belt is "+RED+"red"+NORM+" and the other next to it is "+BLU+"blue"+NORM,
  "belts",
  "One belt is "+RED+"red"+NORM+" and the other next to it is "+BLU+"blue"+NORM
});

dest_dir = ({
  });


  }
}

init() {
  ::init();
  add_action("move_belt","step");
  }

move_belt(str) {
  string room;
  switch(random(4)+1) {
    case 1: room = "blue#"+SPROOM+"pad1.c"; break;
    case 2: room = "blue#"+SPROOM+"pad2.c"; break;
    case 3: room = "blue#"+SPROOM+"pad3.c"; break;
    case 4: room = "blue#"+SPROOM+"pad4.c"; break;
    }
  if(!str) {
    notify_fail("You probably need to \'step on\' <color> \'belt\'.\n");
    return 0;
  }
  else {
    switch(str) {
      case "on red belt": TP->move_player("red#"+SPROOM+"gate.c"); break;
      case "on blue belt": TP->move_player(room); break;
      case "on vital": write("You wish!\n"); break;
      default: write("You NEED to \'step on\' <color> \'belt\'.\n\
There is no way to step "+str+" right now.\n");  
    }
    return 1;
  }
}
