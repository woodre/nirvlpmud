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
"  A Home in EdmonTown\n\
The house is lit by the glow of the globes that are mounted in the \n\
ceiling. The stone walls are bare and the floor is clear and clean. \n\
The furniture here is the same simple, functional furniture that is \n\
seen everywhere on Acadie. There is a small window in the back wall.\n";

items = ({
    "lights",
    "The light in the room is provided by the softly glowing globes that are \n\
mounted in the ceiling",
    "light",
    "The light in the room is provided by the softly glowing globes that are \n\
mounted in the ceiling",
    "globes",
    "These globes are bright and shining, illuminating the whole room",
    "ceiling",
    "The ceiling is full of the bright globes and about 2 meters high",
    "furniture",
    "The furniture is functional and spartan",
    "floor",
    "The floor is clean and has been well maintained",
    "walls",
    "The "+BOLD+"grey"+NORM+", stone walls are bare and clean",
    "wall",
    "There is a small, square window in the back wall about 1 m off of the floor",
    "window",
    "The window is roughly square in shape and sits about 1 m high on the wall",
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
