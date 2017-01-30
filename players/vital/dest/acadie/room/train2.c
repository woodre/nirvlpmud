/************************************/
/*    Owner:      Vital@Nirvana     */
/*    Created:    4/9/01            */
/*    Modified:   4/16/01           */
/*    Realm:      Acadie            */
/************************************/

#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"                 /*universal header*/
#include "/players/vital/dest/include/dest.h"

inherit "room/room";

reset(arg) {
    if(!arg) { 
    set_light(1);
    short_desc = "Train Station";
    long_desc =
"  An Abandoned MagLev Train Station\n\
This train station has obviously not been used in years. The walls \n\
have been scorched by fire and the windows have been broken. The \n\
platform has been cleared of everything and the station as a whole \n\
is bare.\n";

items = ({
    "walls",
    "The walls are scarred with marks of fire",
    "windows",
    "The glass in the windows has been broken",
    "platform",
    "The benches and paraphernalia normally found in a train station have been \n\
removed from the platform",
    "station",
    "This is an old, abandoned MagLev train station"
});

dest_dir = ({
    ACADIE+"room/sidewalk29.c","out"
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
