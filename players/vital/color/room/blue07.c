/*************************************************************/
/*  File:           blue07.c
/*  Function:       
/*  Author(s):      Vital@Nirvana
/*  Copyright:      Copyright (c) 2003 v-Dev Code Factory
/*                  All Rights Reserved.
/*  Source:         9/13/03
/*  Notes:          
/*  Change History: 
/*************************************************************/

#include "/players/vital/closed/headers/vital.h"
#include <ansi.h>
#include "../color.h"

inherit "room/room";
inherit PROBABLE_EXITS;
reset(arg) {
    if(!arg) { 
        set_light(1);
        short_desc = BLU+"A Blue Room"+NORM;
        long_desc =  BBLU+BLK+"\
  This is a "+CYN+"blue"+BLK+" room. It looks like every other "+CYN+"blue"+BLK+" room. There is\n\
"+CYN+"blue"+BLK+" tile on the floor. The walls are all a uniform "+HIC+"azure"+NORM+BBLU+BLK+" that create\n\
one continuous surface without joint, seam or interruption. There is\n\
only one break in the wall where one door exits the room.\n";
        items = ({
            "room",
            "This is the same room you just entered",
            "tile",
            "This is a normal ceramic tile with a light "+CYN+"blue"+NORM+" \
glaze that would\ncomplement most bathrooms",
            "tiles",
            "This is a normal ceramic tile with a light "+CYN+"blue"+NORM+" \
glaze that would\ncomplement most bathrooms",
            "wall",
            "The walls here are a slightly darker "+BLU+"blue"+NORM+" than the \
tiles on the\nfloor",
            "walls",
            "The walls here are a slightly darker "+BLU+"blue"+NORM+" than the \
tiles on the\nfloor",
            "floor",
            "This is a normal ceramic tile with a light "+CYN+"blue"+NORM+" \
glaze that would\ncomplement most bathrooms",
            "surface",
            "The walls are all connected in a manner that removes definition\n\
from them",
            "break",
            "The only break in the wall is the door",
            "joint",
            "There are no discernable joints",
            "seam",
            "There is nothing that could be qualified as a seam",
            "interruption",
            "Read. There is no interruption",
            "joints",
            "There are no discernable joints",
            "seams",
            "There is nothing that could be qualified as seams",
            "interruptions",
            "Read. There are no interruptions",
            "door",
            "This is the entrance to the room, or is it the exit.."
        });
        dest_dir = ({"out_placeholder",NORM+BLU+"out"+NORM
        });
    }
}

init() {
    ::init();
    add_action("search_me","search");
    add_action("random_exit","out");
}

search_me(str) {
    if(!str) {
        notify_fail("What are trying to search?\n");
        return 0;
    }
    write("You furiously search the "+str+" but find nothing.\n");
    return 1;
}

random_exit();

