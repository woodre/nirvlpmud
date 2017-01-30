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
rnd = random(5);
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
  "  The Southwest Concourse\n\
This is the southwest concourse of the N.U.T.S. The walls and floors show \n\
signs of usage and age. The air here is musty and stale, but not yet \n\
noxious. To the east is a set of glass doors with a large sign above them. \n\
As you look to the west you see the N.U.T.S Baggage Claims Office, where \n\
baggage and property claims are filed. The concourse extends on around the \n\
corner to the northeast.\n";

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
  "doors",
  "Each of 4 doors is over 2 meters tall, and 1 meter wide. The doors are \n\
folded back to provide a large opening",
  "opening",
  "This is the entrance to "+HIW+"Perfect"+NORM+" \
"+HIB+"P"+NORM+"e"+HIB+"t"+NORM+"e"+HIB+"r"+NORM+"'s \
"+HIG+"P"+HIR+"a"+HIC+"r"+HIM+"a"+HIY+"p"+HIW+"h"+HIB+"e"+HIG+"r"+HIR+"n\
"+HIC+"a"+HIM+"l"+HIY+"i"+HIW+"a",
  "sign",
  "Welcome to "+HIW+"Perfect"+NORM+" \
"+HIB+"P"+NORM+"e"+HIB+"t"+NORM+"e"+HIB+"r"+NORM+"'s \
"+HIG+"P"+HIR+"a"+HIC+"r"+HIM+"a"+HIY+"p"+HIW+"h"+HIB+"e"+HIG+"r"+HIR+"n\
"+HIC+"a"+HIM+"l"+HIY+"i"+HIW+"a",
  "office",
  "The N.U.T.S. Baggage Claim Office collects the articles that passengers \n\
and and other people lose"
});

dest_dir = ({
  SPROOM+"wconcourse.c","northeast",
  SPROOM+"pppshop.c",   "east",
  SPROOM+"claims.c",    "west"
});
  }
}

init() {
  ::init();
  add_action("search_me","search");
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