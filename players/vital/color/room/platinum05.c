/*************************************************************/
/*  File:           platinum05.c
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
        short_desc = HIW+"A Platinum Room"+NORM;
        long_desc =  HBWHT+BLK+"\
  All around the room are brushed metal benches that have micro-\n\
forges on them. Platinum tools line the walls or are scattered \n\
around the room on the benches. The metal floor echoes with every \n\
step. While not as shiny as the gold and silver rooms, the things \n\
in this room are quite a bit more valuable. This room is the source \n\
of all imagination, inspiration and creativity for the world.\n";
        items = ({
            "room",
            "This is the same room you just entered",
            "benches",
            "The benches are about a meter high and made from a brushed metal",
            "metal",
            "The metal is a dull grey, brushed to a smooth finish",
            "forges",
            "The forges are small but efficient and glow white with heat",
            "micro-forges",
            "The forges are small but efficient and glow white with heat",
            "micro forges",
            "The forges are small but efficient and glow white with heat",
            "forge",
            "The forges are small but efficient and glow white with heat",
            "tools",
            "There are tools of every shape and size. Tools for banging, \n\
tools for cutting, tools for pulling, tools for pushing, tools \n\
for making everything imaginable under the sun",
            "walls",
            "The walls are also made of the same dull, grey, brushed \n\
metal that is found on the floor and the benches",
            "floor",
            "The floor is made of some dull, grey, brushed metal",
            "things",
            "The number of things in this room exceeds the laws of physics. \n\
Some of the objects even seem to exist in the same space",
            "imagination",
            "This room is a fountain of imagination",
            "inspiration",
            "This place is the cloudburst of imagination",
            "creativity",
            "Herein resides the culmination of all creativity",
            "world",
            "Everywhere around you, everything you can feel, see, hear and \n\
touch is a product of this environment",
        });
        dest_dir = ({
            "place_holder", NORM+HIW+"flash"+NORM,
        });
    }
}

init()
{
    ::init();
    add_action("search_me","search");
    add_action("random_exit","flash");
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

