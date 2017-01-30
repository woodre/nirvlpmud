/************************************/
/*    Owner:      Vital@Nirvana     */
/*    Created:    12/18/00          */
/*    Modified:   2/19/01           */
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
The inside is decorated in bright colors and full of beautiful \n\
furnishings. The walls are filled with pictures and paintings. \n\
The light is provided by small globes along the ceiling. The floor \n\
is covered in a large, thick area rug that is warm and comfortable \n\
to stand upon.\n ";

items = ({
    "inside",
    "The bright colors and beautiful furnishings almost make you forget that the low, stone building is on a colony at the far reaches of the known universe",
    "furnishings",
    "The furniture is solid wood, and finely crafted. The attention to detail can be seen in the carving, the upholstery, and the beautiful, rich colors of the world",
    "wood",
    "The wood is very nice and would be of great value",
    "detail",
    "You can see the fine and intricate attention that was placed into the creation of these pieces",
    "carving",
    "The carvings depict scenes of pastoral beauty",
    "carvings",
    "The carvings depict scenes of pastoral beauty",
    "upholstery",
    "The fabric is bright and colorful",
    "colors",
    "You see "+BOLD+"bright "+HIR+"reds"+NORM+", deep "+BLU+"blues"+NORM+", and brilliant "+HIY+"yellows"+NORM+" all woven into the fabric of the furnishings, and the highlights of the furniture",
    "furniture",
    "The furniture is solid wood, and finely crafted. The attention to detail can be seen in the carving, the upholstery, and the beautiful, rich colors of the world",
    "walls",
    "You see hand painted scenes and pictures mounted carefully on the walls",
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
    "The floor is covered in a beautiful carpet, that feels nice beneath you",
    "rug",
    "This rug has a thick pile that offers soft, comfortable support to the people that stand upon it, and warmth to the room"
});

dest_dir = ({
    ACADIE+"room/sidewalk4.c","out"
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
    say(CTPN+" searches the room furiously.\n");
    return 1;
}
