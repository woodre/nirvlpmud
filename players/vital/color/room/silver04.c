/*************************************************************/
/*  File:           silver04.c
/*  Function:       
/*  Author(s):      Vital@Nirvana
/*  Copyright:      Copyright (c) 2003 v-Dev Code Factory
/*                  All Rights Reserved.
/*  Source:         11/7/03
/*  Notes:          
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
        short_desc = BOLD+"A Silver Room"+NORM;
        long_desc =  HBWHT+BLK+"\
  The room "+BOLD+BLINK+"shimmers"+NORM+HBWHT+BLK+" around you. \
The floor is a polished metal that \nreflects the bright lighting \
above with a vengeance. The "+BOLD+"silver"+NORM+HBWHT+BLK+" \n\
furniture is made from a shiny alloy that looks and fees strong and \
\nsturdy. There is a large, shiny "+BOLD+"chrome"+NORM+HBWHT+BLK+" \
portal floating near one of \nthe walls.\n";
        items = ({
            "room",
            "This is the same room you just entered",
            "floor",
            "The metal floor reflects the light as well as your own image",
            "metal",
            "This metal resists dirt, scratches and dents. Is it real? \nIt would make nice armor",
            "lighting",
            "The lighting here is fierce and brings tears with it's intensity",
            "light",
            "The light here is extremely bright and leaves no shadows",
            "furniture",
            "This is lightweight and beautiful furniture",
            "alloy",
            "This alloy is of an unknown origin and is very strong",
            "portal",
            "This seems like the only way in or out of the room",
            "walls",
            "The walls are also made from some type of shiny metal",
            "wall",
            "This wall is dominated by the massive, chrom-alloy portal",
        });
        dest_dir = ({
            "place_holder", NORM+BOLD+"portal"+NORM,
        });
    }
}

init()
{
    ::init();
    add_action("search_me","search");
    add_action("random_exit","portal");
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
