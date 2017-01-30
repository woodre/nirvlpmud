/*************************************************************/
/*  File:           black09.c
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
        set_light(-2);
        short_desc = BLK+"A Black Room"+NORM;
        long_desc =  BLK+"\
  "+BOLD+"Darkness"+NORM+BLK+" and shadows surround the room of "+BOLD+"\
black"+NORM+BLK+", threatening to \nswallow everything within the \
maw of its overwhelming nothingness. \nA single, large crystal hovers \
motionless in the center of the room. \nThe crystal "+BLINK+"pulses"+
NORM+BLK+" with a "+BOLD+"dark"+NORM+BLK+" energy that sustains the \
existence \nof this void. "+BOLD+"Dark"+NORM+BLK+" wraiths float in and \
out of existence in this \nnever world to the rhythmic timing of the \
crystal's "+BLINK+"pulsing"+NORM+BLK+".\n";
        items = ({
            "room",
            BLK+"This is the same room you just entered"+NORM,
            "darkness",
            BLK+"The "+BOLD+"Darkness"+NORM+BLK+" is suffocating and surrounding"+NORM,
            "shadows",
            BLK+"The shadows are deep and truly dark"+NORM,
            "nothingness",
            BLK+"The power of the darkness is extremely hard to penetrate"+NORM,
            "crystal",
            BLK+"This odd, 5 meter high crystal floats in the center of the room"+NORM,
            "center",
            BLK+"The center of the room is dominated by the massive crystal"+NORM,
            "energy",
            BLK+"You cannot see the energy as much as feel it pulsing in your body"+NORM,
            "void",
            BLK+"This is the nothing, the empty, the dark, the very end"+NORM,
            "wraiths",
            BLK+"Formless figures floating figuratively from forever to forever"+NORM,
            "wraith",
            BLK+"This is one of the unlighted ones who dwell in this everdark"+NORM,
            "world",
            BLK+"This is the neverworld. This is the everdark"+NORM,
            "pulsing",
            BLK+"You cannot see the energy as much as feel is pulsing in your body"+NORM,
        });
        dest_dir = ({
            "place_holder", NORM+BLK+"fade"+NORM,
            "place_holder", NORM+BLK+"pulse"+NORM,
            "place_holder", NORM+BLK+"shadows"+NORM,
        });
    }
}

init()
{
    ::init();
    add_action("search_me","search");
    add_action("random_exit","fade");
    add_action("random_exit","pulse");
    add_action("random_exit","shadows");
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

