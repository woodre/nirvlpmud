/*************************************************************/
/*  File:           gold05.c
/*  Function:       
/*  Author(s):      Vital@Nirvana
/*  Copyright:      Copyright (c) 2003 v-Dev Code Factory
/*                  All Rights Reserved.
/*  Source:         11/8/03
/*  Notes:          exiting the room handled by cexits.h
/*  Change History: 
/*************************************************************/

#include "/players/vital/closed/headers/vital.h"
#include <ansi.h>
#include "../color.h"

inherit "room/room";
inherit PROBABLE_EXITS;
reset(arg)
{
    if(!arg)
    { 
        set_light(1);
        short_desc = HIY+"A Gold Room"+NORM;
        long_desc =  HBYEL+HIY+"\
  The shine of the "+BLK+"gold"+HBYEL+HIY+" around the room is \
almost overwhelming in \nits opulence and grandeur. "+BLK+"Golden"+
HBYEL+HIY+" nuggets are piled and scattered \non the floor. "+BLK+
"Golden"+HBYEL+HIY+" tapestries are hung along the walls and "+BLK+
"golden"+HBYEL+HIY+" \nflowers bloom in large, gilded planters. \
The statuary and every \nother aspect of the room suffers under \
the weight of King Midas' \nrule. Everything is made of "+BLK+"gold"+
HBYEL+HIY+". Many explorers have searched for \nthis place for \
their entire lives.\n";
        items = ({
            "room",
            "This is the same room you just entered",
            "gold",
            "The color of the room is overwhelmingly "+HIY+"golden"+NORM,
            "opulence",
            "There is just so much wealth here. It is amazing",
            "grandeur",
            "This has to be one of the largest collections of wealth",
            "nuggets",
            "Large chunks of "+HIY+"gold"+NORM+" just lying around the room",
            "floor",
            "The floor is filled with "+HIY+"golden"+NORM+" objects of \
every shape and size",
            "tapestries",
            "These elegant, woven canvases tell the history of this place",
            "walls",
            "Covered by "+HIY+"golden"+NORM+" tapestries, they are made \
of golden bricks",
            "flowers",
            "Goldenrods, dandelions and daiseys fill the planters",
            "planters",
            "These are large pots made from pure "+HIY+"gold"+NORM,
            "statuary",
            "The statues are all large "+HIY+"gold"+NORM+"-leaf \
representations of heroes",
            "statues",
            "There are many different statues here in this place",
            "statue",
            "The statues stares back in "+HIY+"golden"+NORM+" indifference",
            "aspect",
            "The very essence of this place is decadent",
        });
        dest_dir = ({
            "place_holder", NORM+HIY+"out"+NORM,
        });
    }
}

init()
{
    ::init();
    add_action("search_me","search");
    add_action("random_exit","out");
}

search_me(str)
{
    if(!str) {
        notify_fail("What are trying to search?\n");
        return 0;
    }
    write("You furiously search the "+str+" but find nothing.\n");
    return 1;
}

random_exit();

