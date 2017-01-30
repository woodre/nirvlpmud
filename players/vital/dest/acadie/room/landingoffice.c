/************************************/
/*    Owner:      Vital@Nirvana     */
/*    Created:    12/18/00          */
/*    Modified:   7/21/01           */
/*    Realm:      Acadie            */
/************************************/

#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"                    /*color header*/
#include "/players/vital/dest/include/dest.h"

inherit "room/room";

object guard, random;

reset(arg) {
  if(!present("trooper",TO)) MO(CO(NPC+"dtroops.c"),TO);
  if(!present("human",TO)) {
    MO(CO(NPC+"human.c"),TO);
    MO(CO(NPC+"human.c"),TO);
  }
  if(!arg) {

set_light(1);

short_desc = RED+"Acadie"+NORM+" Spaceport Office";
long_desc =
  "  "+RED+"Acadie"+NORM+" Spaceport Office\n\
The Acadie branch of the N.U.T.S. Spaceport is much smaller than all \n\
the other offices. There is just this one large room with a window in \n\
the wall and several chairs for passengers to wait and rest in until \n\
they are ready to leave or people come to pick them up. The room must \n\
be heated because it is noticeably warmer inside than it is outside. .\n ";

items = ({
    "spaceport",
    "Every destination along and within the N.U.T.S. Spaceport system has an office as required by the law",
    "office",
    "Every destination along and within the N.U.T.S. Spaceport system has an office as required by the law",
    "offices",
    "Every destination along and within the N.U.T.S. Spaceport system has an office as required by the law",
    "room",
    "As you look around, you notice the ticket window has bars added over it and high impact plass. The chairs are weathered, brown and uncomfortable",
    "window",
    "The ticket window has bars across it and is covered in high impact plass.",
    "chairs",
    "The chairs are modeled after those found in early 20th century railway stations",
    "passengers",
    "There are other people, just like yourself who pass to-and-fro within the boundaries of known space",
    "people",
    "Often, passengers will arrive and await the coming of their friends and relatives to pick them up and bear them off to other places"
});

dest_dir = ({
    ACADIE+"landing.c","pad",
    ACADIE+"room/entry.c","out"
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
  else write("You furiously search the "+str+" but find nothing.\n");
}
