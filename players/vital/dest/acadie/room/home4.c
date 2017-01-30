/************************************/
/*    Owner:      Vital@Nirvana     */
/*    Created:    3/8/01            */
/*    Modified:   4/10/01           */
/*    Realm:      Acadie            */
/************************************/

#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"                 /*universal header*/
#include "/players/vital/dest/include/dest.h"

inherit "room/room";
object mob;

reset(arg) {
    if(!(present("becky",TO))) { MO(CO(ACADIE+"npc/rebecca.c"),TO); }
    if(!arg) { 
    set_light(1);
    short_desc = "Rebecca's House";
    long_desc =
"  This is Rebecca's house on Acadie. The interior is adorned with \n\
many beautiful pieces of furniture. The walls have been covered in \n\
large, solid, wooden panels. The floor is covered in a large carpet \n\
and it's light "+HIW+"grey"+NORM+" color helps to brighten up the room. The majority \n\
of the "+HIY+"light"+NORM+" in the room is provided by the ubiquitous globes that \n\
are mounted alone the ceilings.\n ";

items = ({
    "interior",
    "This is truly a beautiful house that is a close reflection of the owner",
    "pieces",
    "The furniture all comes from the same design. They are coordinated and ornate. \n\
There is a greater emphasis on beauty over functionality, as the chairs and \n\
couches do not appear comfortable",
    "furniture",
    "The furniture all comes from the same design. They are coordinated and ornate. \n\
There is a greater emphasis on beauty over functionality, as the chairs and \n\
couches do not appear comfortable",
    "walls",
    "These are some of the most beautiful, large pieces of solid wood you have ever seen",
    "panels",
    "These are some of the most beautiful, large pieces of solid wood you have ever seen",
    "floor",
    "There is a light, "+HIW+"grey"+NORM+" colored carpet on the floor",
    "carpet",
    "The carpet has a deep, rich pile that keeps the floor warm",
    "ceilings",
    "The ceilings are covered in the hemi-spherical globes that emit a strange "+HIY+"light"+NORM,
    "globes",
    "These are found in nearly every building in EdmonTown"
});

dest_dir = ({
    ACADIE+"room/courtyard.c","out"
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
