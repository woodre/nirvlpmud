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
The inside is decorated in what might be politely described as \n\
cluttered. There are piles of things everywhere and little attention\n\
has been paid to the placement of anything. It is a wonder that the \n\
owner could find anything in an emergency. The floor is completely \n\
covered and the walls have paintings and pictures all over them.\n ";

items = ({
    "inside",
    "The high piles of junk make you wish for a broom and a large trash can",
    "furnishings",
    "The furniture is covered in stuff",
    "colors",
    "You see "+BOLD+"bright "+HIR+"reds"+NORM+", deep "+BLU+"blues"+NORM+", and brilliant "+HIY+"yellows"+NORM+" all woven into the fabric of the furnishings, and the highlights of the furniture",
    "furniture",
    "The furniture is covered in piles of stuff",
    "walls",
    "You see hand painted scenes and pictures barely remaining stuck to the walls",
    "pictures",
    "The pictures are the repesentations of real people on a photographic medium. The use of pictures instead of 3-dimensional images further emphasizes the rudimentary technology of this place",
    "paintings",
    "The paintings are bright and the obvious work of a master painter",
    "light",
    "The light is provided by the many small globes along the ceiling",
    "ceiling",
    "The ceiling is covered in many of the small globes along the ceiling",
    "globes",
    "The globes are fully lit and are scattered across the ceiling",
    "floor",
    "The floor is covered in piles of junk",
    "piles",
    "There is stuff piled high everywhere. The floor is all but covered in junk"
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
