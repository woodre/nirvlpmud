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

int rnd;

reset(arg) {
  if(!arg) {

set_light(1);

short_desc = "Customs Office";
long_desc =
  "  N.U.T.S. Customs Office\n\
This office is the central clearing house for the Customs Officials. In \n\
the course of policing the travellers of the N.U.T.S., the Customs Officials \n\
have invariably collected a lot of contraband. This room is where all of the \n\
illegal plunder is brought to be stored or shipped off to wholesellers. The \n\
Customs Officials are very thorough and catch everything.\n ";

items = ({
  "office",
  "This is where the Customs' Guards come to kick back",
  "house",
  "This is how the N.U.T.S. manages to keep crime down",
  "officials",
  "These are the people who fight smugglers in the N.U.T.S",
  "travellers",
  "These are people who are bound for other worlds",
  "contraband",
  "Large piles of illegal items that travellers have tried to bring through \n\
the N.U.T.S",
  "wholesellers",
  "This is how the N.U.T.S. really finances the operations around here"
});

dest_dir = ({
    SPROOM+"seconcourse.c","out"
  });

  }
}

init() {
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
