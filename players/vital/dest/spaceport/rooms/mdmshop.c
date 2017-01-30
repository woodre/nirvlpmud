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

object mrs;

reset(arg) {
  if(!present("mrs",this_object())) {
     mrs = CO(SPNPC+"mrs.c");
     MO(mrs, TO);
   }
  if(!arg) {
set_light(1);

short_desc = "The Soothsayer's Shop";
long_desc =
  "  The Soothsayers's Shop\n\
This is a small, dusty room. The room itself is a converted maintenance \n\
closet and is cluttered with an eclectic collection of items that cause the \n\
room to look even more cramped. The only "+YEL+"light"+NORM+" in the room \
comes from a \ngrimy, soot-covered, and "+BLINK+"shaky"+NORM+" lamp"+NORM+". \
In the middle of the piles of junk is a table.\n";

items = ({
  "room",
  "This small, "+BOLD+BLK+"dark"+NORM+" room is filled with junk and pieces \
of other junk",
  "dust",
  "The dust is nearly thick enough to plant an herb garden",
  "closet",
  "Many years ago, this room served as a maintenance closet, now it has been \n\
forgotten and overlooked",
  "clutter",
  "A wide variety of odds and ends that are best left undisturbed",
  "collection",
  "A wide variety of odds and ends that are best left undisturbed",
  "items",
  "Pieces of furniture, lamps, jewellery, parts from machinery, things that \n\
used to be other things and broken promises litter the room",
  "light",
  "The "+BLINK+"shaky"+NORM+", "+BLK+"grim"+NORM+" "+YEL+"lamp"+NORM+" casts \
more "+BOLD+BLK+"shadows"+NORM+" than "+WHT+"light"+NORM,
  "lamp",
  "Almost indestinguishable from the surrounding junk, is an old lamp that \
is \nnearly ready to go out",
  "piles",
  "The piles are smaller collections of junk and items that have less dust \n\
on them",
  "junk",
  "A wide variety of odds and ends that are best left undisturbed",
  "table",
  "A small round table with a dark "+HIM+"purple"+NORM+" cloth draped over it \
and \nsome smaller odds and ends scattered around on it",
  "odds",
  "Trinkets on the table that look old",
  "ends",
  "These are the things that accumulate after years of pack-ratting"
});

dest_dir = ({
    SPROOM+"wconcourse.c","out"
});

  }
}

init() {
    ::init();
    add_action("search_me","search");
    add_action("move_out","dive");
}

search_me(str) {
  if(!str) {
    notify_fail("What are trying to search?\n");
    return 0;
  }
  else switch(random(6)) {
    case 0: write("You find yourself.\n"); break;
    case 1: write("You rifle through the "+str+" and get "+BOLD+BLK+"dirty\
"+NORM+" hands from the junk.\n"); break;
    case 2: write("You search the "+str+" but find nothing.\n"); break;
    case 3: write("The "+str+" threatens to fall on you if you keep \
searching.\n"); break;
    case 4: write("You have no idea how to search the "+str+".\n"); break;
    case 5: 
            write("You find a secret exit, hidden amongst the piles of junk.\nYou might be able to \'dive\' into the pile and get somewhere.\n");
            break;
  }
  return 1;
}

move_out() {
    TP->move_player("into a pile of junk#"+SPROOM+"backroom.c");
    return 1;
}