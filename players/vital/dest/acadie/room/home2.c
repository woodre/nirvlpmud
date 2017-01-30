/************************************/
/*    Owner:      Vital@Nirvana     */
/*    Created:    12/18/00          */
/*    Modified:   2/21/01           */
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
    "There are large tapestries of many "+HIR+"c"+HIB+"o"+HIG+"l"+HIY+"o"+HIC+"r"+HIM+"s"+NORM+" covering the walls to provide diversion from the stone and warmth from the cold",
    "tapestries",
    "There are large tapestries of many "+HIR+"c"+HIB+"o"+HIG+"l"+HIY+"o"+HIC+"r"+HIM+"s"+NORM+" covering the walls to provide diversion from the stone and warmth from the cold",
    "tapestry",
    "There are large tapestries of many "+HIR+"c"+HIB+"o"+HIG+"l"+HIY+"o"+HIC+"r"+HIM+"s"+NORM+" covering the walls to provide diversion from the stone and warmth from the cold",
});

dest_dir = ({
    ACADIE+"room/sidewalk12.c","out"
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
    if(str == "tapestry") {
        write("You take a closer look at the large tapestries hanging on the wall.\n\n");
        write("As you move in to touch it, you notice it seem to sway in the breeze as if something could \'move\' the tapestry.\n");
        add_action("move_tapestry","move");
        return 1;
    }
    else write("You furiously search the "+str+" but find nothing.\n");
    return 1;
}

move_tapestry(str) {
    if(str == "tapestry" || str == "tapestries") {
        write("You reach forward and grasp the edge of one of the tapestries,\n");
        write("and find a small doorway that you could \'enter\'.\n");
        add_action("enter_door","enter");
    return 1;
    }
    if(str != "tapestry" || str != "tapestries") { 
        notify_fail("Are you trying to move the right thing?\n");
        return 0;
    }
}

enter_door(str) {
    if(str == "door" || str == "doorway") {
        write("You grab the handle of the small door and give it a push.\n");
        write("As the door swings open, you feel the cool air from the other side wash over your.\n");
        this_player()->move_player("through the door#/players/vital/dest/acadie/room/alley5.c");
    return 1;
    }
    if(!str || str != "door" || str != "doorway") { 
        notify_fail("What are you trying to enter?\n");
        return 0;
    }
}
    