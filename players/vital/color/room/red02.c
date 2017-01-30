/*************************************************************/
/*  File:           red02.c
/*  Function:       
/*  Author(s):      Vital@Nirvana
/*  Copyright:      Copyright (c) 2003 v-Dev Code Factory
/*                  All Rights Reserved.
/*  Source:         9/15/03
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
        short_desc = RED+"The Red Room"+NORM;
        long_desc =  BRED+BLK+"\
  Welcome to the room of "+HIR+"red"+NORM+BRED+BLK+". The room is \
carpeted with a thick, \nplush rug that extends from wall to wall. \
The walls are composed \nof "+HIR+"red"+NORM+BRED+BLK+" bricks that \
have been expertly stacked and mortared. The \ndoor is framed with \
lacquered wood that fairly glows with the \nbright "+HIR+"red"+NORM+
BRED+BLK+" pigment that was used to paint it. There is a rope \n\
ladder hanging from a glowing "+HIR+"red"+NORM+BRED+BLK+" hole in \
the ceiling.\n";
        items = ({
            "room",
            "This is the same room you just entered",
            "carpet",
            "Thick, luxurious, deep-pile carpet that is soft and plush",
            "rug",
            "Thick, luxurious, deep-pile carpet that is soft and plush",
            "wall",
            "The wall is made of well stacked bricks that glow "+RED+"red"+NORM,
            "walls",
            "The walls are made of well stacked bricks that glow "+RED+
"red"+NORM,
            "bricks",
            "The bricks are glowing "+RED+"red"+NORM,
            "door",
            "The door is wooden and appears to be on fire! No, wait, \
it is just\n paint",
            "frame",
            "The frame has been lacquered a bright "+RED+"red"+NORM,
            "pigment",
            "An ethereal paint that fairly glows with color",
            "paint",
            "An ethereal paint that fairly glows with color",
            "rope",
            "This is just ordinary, braided, sisal rope, used to make \
a ladder",
            "ladder",
            "This is rope ladder that you could climb",
            "hole",
            "The hole in the ceiling glows "+RED+"red"+NORM+" where the rope \
ladder disappears \ninto the ceiling",
            "ceiling",
            "This is the flat, planar surface parallel and directly \
opposite \nfloor beneath you",
        });
        dest_dir = ({"climb_placeholder",NORM+HIR+"climb"+NORM,
                     "door_placeholder",HIR+"door"+NORM
        });
    }
}

init() {
    ::init();
    add_action("search_me","search");
    add_action("climb_exit","climb");
    add_action("door_exit","door");
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

climb_exit() {
    write("You scramble up the ladder.\n");
    say(TPN+" scrambles up a rope ladder.\n");
    random_exit();
    return 1;
}

door_exit() {
    write("You open the door and wander out.\n");
    say(TPN+" opens the door and wanders out.\n");
    random_exit();
    return 1;
}

