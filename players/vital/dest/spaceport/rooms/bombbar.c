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
rnd = random(2);
	if(!present("human", this_object())) {
	  for(i=0; i < rnd; i++) {
	    human = CO(SPNPC+"human.c");
	    MO(human, TO);
	  }
	}
  if(!arg) {

set_light(1);

short_desc = "Bomb-Shelter Bar";
long_desc =
  "  The Bomb-Shelter Bar\n\
Welcome to the Bomb-Shelter Bar. This is perhaps the most heavily armored \n\
and structurally sound room you have ever seen. Large beams support heavy, \n\
armored panels along the walls and ceiling. The bar is crowded with \n\
customers and furniture. No matter what happens to the rest of the world, \n\
this bar will survive to serve you swill. Your ability to survive this \n\
experience may not be so sure.\n ";

items = ({
  "bar",
  "The bar is central to the whole room and drinks make their way from there",
  "stools",
  "These are metallo-plastic constructs that look like they could withstand \n\
any attack",
  "tables",
  "These dull "+BOLD+BLK+"grey"+NORM+" metal objects are small and scattered \n\
throughout the shadows of the bar",
  "shadows",
  "Darkness hides the corners were some people drink and speak in whispers",
  "armor",
  "The armor is dark "+BOLD+BLK+"grey"+NORM+" and incredibly thick",
  "room",
  "The room is full of "+HIW+"smoke"+NORM+" and hard faces drowning in \n\
whatever brings them here",
  "beams",
  "The beams are almost 60 cm wind and 30 cm thick",
  "panels",
  "The panels are made out of 25 cm thick alloy and armor the entire bar",
  "walls",
  "The walls are dark and made of large armor panels sandwiched between \n\
supporting beams",
  "ceiling",
  "The low ceiling seems so different compared to the rest of the N.U.T.S.",
  "customers",
  "All around you are people who have come to do one of two things. Engage \n\
in something illegal, or find someone who already is",
  "furniture",
  "Crowded stools and tables where people absently stare at their drinks and \n\
think of more pleasant times"
});

dest_dir = ({
    SPROOM+"econcourse.c","out"
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
  else switch(str) {
    case "bar": write("You find a bar full of people who don't like people \
poking around.\n"); break;
    case "tables"  : write("You try to find a free table.\n"); break;
    case "floor"  : write("The floor is too dirty to search.\n"); break;
    case "walls"  : write("Your closer inspection of the walls finds that the \
dark "+BOLD+BLK+"grey"+NORM+"\ncolor is the result of years of dust.\n"); break;
    case "stools"  : write("All the stools are currently full of other people \
wishing you would stop.\n"); break;
    default :       write("You furiously search the "+str+" and come up \
empty handed.\n");
  }
  return 1;
}
