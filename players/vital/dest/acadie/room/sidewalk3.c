/************************************/
/*    Owner:      Vital@Nirvana     */
/*    Created:    12/18/00          */
/*    Modified:   2/10/01           */
/*    Realm:      Acadie            */
/************************************/

#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"                    /*color header*/
#include "/players/vital/dest/include/dest.h"

inherit "room/room";

reset(arg) {
  if(!arg) {

set_light(1);

short_desc = "Sidewalk";
long_desc =
  "  The Sidewalk\n\
As the sidewalk enters the town, the buildings seem to crowd \n\
in together. The nearest ones have entrances that are open and \n\
people moving in and out. The large structure in the center of \n\
town is now much closer.\n ";

items = ({
    "sidewalk",
    "The presence of an actual paved, unmoving thoroughfare is certainly \n\
unique",
    "town",
    "The town is a collection of very similar, simple buildings",
    "buildings",
    "The buildings are low, cut stone places, apparently used for business \n\
or dwellings",
    "entrances",
    "The entrances are covered in stout doors to protect from the sometimes \n\
harse winds and cold winters",
    "doors",
    "These doors are either reinforced steel or thick oak. Today they are \n\
open in the relatively warm day",
    "people",
    "The people here are dressed in the functional jumpers used by the \n\
general populace",
    "structure",
    "The closer you get to the structure, the more details you can make out",
    "details",
    "The structure is not stone and is easily six or even eight stories \n\
high"
});

dest_dir = ({
    ACADIE+"room/sidewalk2.c","north",
    ACADIE+"room/sidewalk4.c","south",
    ACADIE+"room/shop.c","east",
    ACADIE+"room/drygoods.c","west"
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
