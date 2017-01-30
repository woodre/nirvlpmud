/************************************/
/*    Owner:      Vital@Nirvana     */
/*    Created:    12/18/00          */
/*    Modified:   12/18/00          */
/*    Realm:      Spaceport         */
/************************************/

#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"
#include "/players/vital/dest/include/spaceport.h"     /*area header */

inherit "room/room";

reset(arg) {
  if(!arg) {

object monster;

set_light(1);

short_desc = "Baggage Claim";
long_desc =
  "  The N.U.T.S. Baggage Claim\n\
A long counter separates you from a large guard. The walls and floor here \n\
are completely bare. People are supposed to come here to file claims for \n\
lost baggage and property, but the room is strangely empty of all baggage \n\
or other items.\n";

items = ({
  "counter",
  "This "+BOLD+BLK+"dark"+NORM+"counter maybe just low enough to jump over",
  "sign",
  "Perhaps you should 'read' it",
  "guard",
  "The guard is here to make sure that the wrong people don't get the wrong \n\
articles",
  "articles",
  "Articles is just a generic term used to refer to the baggage and property \n\
that people come here to claim",
  "walls",
  "The walls are bare of any signage, writing or other indication of what \n\
this room is used for",
  "floor",
  "The floor is conspicously clean and bare. The lack of packages, parcels, \n\
baggage, or other missing property is truly odd for a place that is supposed \n\
to hold such articles for people to claim",
  "baggage",
  "If you are looking for baggage, you won't see it in this room",
  "property",
  "Any property that was turned in here is NOT here now",
  "packages",
  "The packages that people lost or misplaced are now completely beyond their reach",
  "parcels",
  "You need to keep a close eye on your stuff, it might disappear like the \n\
parcels that were in this room"
});

dest_dir = ({
    SPROOM+"swconcourse.c", "east"
  });

  }
}
init() {
  ::init();
  add_action("search_me","search");
  add_action("move_enter","jump");
  add_action("read_sign","read");
}

search_me(str) {
  if(!str) {
    notify_fail("What are trying to search?\n");
    return 0;
  }
  else switch(str) {
    case "counter": write("You find a small sign.\n"); break;
    case "floor"  : write("Yep, it really is empty.\n"); break;
    case "guard"  : write("You cannot search the guard from this side of \
the counter.\n"); break;
    default :       write("You furiously search the "+str+" and come up \
empty handed.\n");
  }
  return 1;
}

move_enter(str) {
  if(str != "counter") {
    notify_fail("What are you trying to jump over?\n");
    return 0;
  }
  else
  write("You jump over the counter.\n");
  TP->move_player("over the counter#"+SPROOM+"backcounter.c");
  return 1;
}

read_sign(str) {
  if(!str) {
    notify_fail("So do you know what it is you are trying to do here? \
Perhaps you need to actually read the sign?\n");
    return 0;
  }
  else if(str == "sign") {
    write("N.U.T.S. Baggage Claim Center \nPlease form a que to the left.\n");
  }
  return 1;
}