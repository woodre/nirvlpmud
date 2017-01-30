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
The lights inside the house comes from small globes that are \n\
mounted along the ceiling. The furniture here is sparse and of \n\
a simple quality. The floor has several small rugs and animal \n\
pelts that keep the place warm. The walls have several large \n\
tapestries hung to help insulate this simple house.\n ";

items = ({
    "lights",
    "The light in the room provided by the little globes that are somehow mounted into the ceiling",
    "globes",
    "These globes glow brightly with a sharp light that pierces the darkness",
    "ceiling",
    "The ceiling is full of the light globes and barely 7 feet high",
    "furniture",
    "The furniture is rustic and simply made. The wood is roughly hewn and completely without adornment. Form has followed function",
    "floor",
    "The floor is covered in multiple rugs and skins. They provide the room with a softer, more comfortable feel",
    "rugs",
    "Theses rugs are woven from coarse fabric and other materials",
    "pelts",
    "These animal skins are from strange and exotic beasts that you have never seen before. They have been reverse tanned so that the hair remains upon the large pieces of leather",
    "walls",
    "There are large tapestries of many "+random_color()+"c"+random_color()+"o"+random_color()+"l"+random_color()+"o"+random_color()+"r"+random_color()+"s"+NORM+" covering the walls to provide diversion from the stone and warmth from the cold",
    "tapestries",
    "There are large tapestries of many "+random_color()+"c"+random_color()+"o"+random_color()+"l"+random_color()+"o"+random_color()+"r"+random_color()+"s"+NORM+" covering the walls to provide diversion from the stone and warmth from the cold",
    "tapestry",
    "There are large tapestries of many "+random_color()+"c"+random_color()+"o"+random_color()+"l"+random_color()+"o"+random_color()+"r"+random_color()+"s"+NORM+" covering the walls to provide diversion from the stone and warmth from the cold",
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
