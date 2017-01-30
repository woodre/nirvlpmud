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

reset(arg) {
  if(!arg) {

object guard;

set_light(1);

short_desc = "Behind the Counter";
long_desc =
  "  Behind the N.U.T.S. Baggage Claim Office Counter\n\
You have some how managed to get behind the counter of the N.U.T.S. Baggage \n\
Claim Office. This area is clean and utterly without dust or dirt. You feel \n\
guilty because you know you shouldn't be back here.\n";

items = ({
  "counter",
  "This "+BOLD+BLK+"dark"+NORM+"counter maybe just low enough to jump over",
  "dust",
  "You cannot see any dirt or dust here",
  "dirt",
  "You cannot see any dirt or dust here"
});

dest_dir = ({
  });

/*     if(!guard) { */
/*     guard = CO(SPNPC"guard.c"); */
/*     MO(guard,TO); */
/*     } */
  }
}
init() {
  ::init();
  add_action("search_me","search");
  add_action("move_enter","jump");
}

search_me(str) {
  if(!str) {
    notify_fail("What are trying to search?\n");
    return 0;
  }
  else switch(str) {
    case "counter": write("You amazingly find a counter!\n"); break;
    case "floor"  : write("Yep, it really is empty.\n"); break;
    case "guard"  : write("You are cruising for a bruising.\n"); break;
    default :       write("You furiously search the "+str+" and come up \
empty handed.\n");
  }
  return 1;
}

move_enter(str) {
  if(!str || str != "counter") {
    notify_fail("What are you trying to jump over?\n");
    return 0;
  }
  else
  write("You jump over the counter.\n");
  TP->move_player("jumping over the counter#"+SPROOM+"claims.c");
  return 1;
}