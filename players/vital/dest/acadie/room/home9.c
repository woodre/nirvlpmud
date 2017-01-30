/************************************/
/*    Owner:      Vital@Nirvana     */
/*    Created:    12/18/00          */
/*    Modified:   5/8/01            */
/*    Realm:      Acadie            */
/************************************/

#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"                    /*color header*/
#include "/players/vital/dest/include/dest.h"

inherit "room/room";

reset(arg) {
    if(!arg) { 
    set_light(0);
    short_desc = "A Home";
    long_desc =
"  A Home in EdmonTown\n\
There lights inside the house should come from the small, dark globes \n\
that are mounted along the ceiling. There is no furniture here and it \n\
seems that the house was abandoned. The floor has several inches of \n\
dust and there are animal prints present. The walls are bare except \n\
for the tattered remains of a tapestry or two.\n";

items = ({
    "lights",
    "The light in the room would be provided by the little globes that are \n\
somehow mounted into the ceiling",
    "light",
    "The light in the room would come from the little globes that are somehow \n\
mounted into the ceiling",
    "globes",
    "These globes are dark and dim",
    "ceiling",
    "The ceiling is full of the dim globes and barely 7 feet high",
    "furniture",
    "The furniture is missing from this house",
    "floor",
    "The floor is covered in nearly 2 cm of dust and there are animal tracks \n\
present",
    "prints",
    "These animal prints have been left behind in the dust as animals have \n\
come and gone in this deserted house",
    "dust",
    "The dust is thick and covers everything in the house",
    "remains",
    "These could have once been beautiful tapestries",
    "walls",
    "There are large strips of cloth that might have been a tapestry or wall hanging",
    "tapestries",
    "There are large strips of cloth that might have been a tapestry or wall hanging",
    "tapestry",
    "There are large strips of cloth that might have been a tapestry or wall hanging",
});

dest_dir = ({
    ACADIE+"room/sidewalk32.c","out"
  });

  }
}

init() {
    ::init();
    add_action("search_me","search");
}

search_me(str) {
    if(!str) { FAIL("What are you trying to search?"); }
    else OUT("You furiously search the "+str+" but find nothing.");
    return 1;
}
