/*************************************************************/
/*  File:           white08.c
/*  Function:       
/*  Author(s):      Vital@Nirvana
/*  Copyright:      Copyright (c) 2003 v-Dev Code Factory
/*                  All Rights Reserved.
/*  Source:         11/6/03
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
        short_desc = BOLD+"A White Room"+NORM;
        long_desc =  BWHT+BLK+"\
  This is a featureless "+BOLD+"white"+NORM+BWHT+BLK+" room. Everything is \
nearly \nindistinguishable in the blinding "+BOLD+"white"+NORM+BWHT+BLK+" \
light. The floor \nbecomes the walls which in turn become the ceiling \
without \nany visible definition. It is almost like being in a giant, \n\
"+BOLD+"white"+NORM+BWHT+BLK+" sphere where every position is exactly \
equivalent to \nevery other possible position. Only true \'wander\'ers \
could \nfind their way out of this place.\n";
        items = ({
            "room",
            "This is the same room you just entered",
            "everything",
            "This could be anything as well as everything",
            "light",
            "From no source, the light surrounds you leaving no shadows",
            "floor",
            "The floor disappears beneath your feet and blends into the walls",
            "wall",
            "The wall is very high or very far away",
            "walls",
            "The walls are amorphous and blend into their surroundings",
            "ceiling",
            "Are you sure this is the ceiling? Maybe it is just a high wall",
            "definition",
            "There is no sense of edge, boundary or even matter here",
            "sphere",
            "Your senses tell you that you are both inclosed within a \n\
sphere and at the same time in endless void. How \nconfusing it is",
            "position",
            "You are in a neutral position, neither here nor there",
            "place",
            "This is the culmination of pure nothingness",
        });
        dest_dir = ({
            "place_holder", NORM,
        });
    }
}

init()
{
    ::init();
    add_action("search_me","search");
    add_action("random_exit","wander");
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

