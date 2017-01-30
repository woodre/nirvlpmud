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
    set_light(1);
    short_desc = "A Home";
    long_desc =
    "  A Small Home\n\
The house has not been occupied for some time. There is a thick layer \n\
of dust covering nearly every surface. The people who lived here \n\
before must have left in a rush because the table is still set for \n\
dinner and the remains of what must have been dinner are still on the \n\
large platter.\n ";

items = ({
    "house",
    "The dust is thick and there are spiderwebs everywhere",
    "spiderwebs",
    "The spiders have been busy making this their home",
    "webs",
    "The spiders have been busy making this their home",
    "furnishings",
    "The furniture is covered in dust and grime",
    "funiture",
    "The furniture is covered in dust and grime",
    "table",
    "The table is still set for dinner and there is a large platter in the center",
    "platter",
    "There remains what must have been dinner a long time ago",
    "dust",
    "The dust is very thick and must have take a long time to accumulate",
    "ceiling",
    "The ceiling is covered in many of the small globes along the ceiling",
    "globes",
    "The globes are dim and many of them are missing",
    "floor",
    "The floor is covered in a thick carpet of dust like everything else",
    "surface",
    "Everywhere you look you see nothing but dust, dust, dust"
});

dest_dir = ({
    ACADIE+"room/sidewalk25.c","out"
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
