/*************************************************************/
/*  File:           yellow02.c
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
        short_desc = YEL+"A Yellow Room"+NORM;
        long_desc =  BYEL+BLK+"\
  This is the bottom of a large, "+HIY+"yellow"+NORM+BYEL+BLK+" silo. \
All around is "+HIY+"yellow"+NORM+BYEL+BLK+" \ngrain piled a meter \
high. The walls of the silo are formed from \npure "+HIY+"amber\
"+NORM+BYEL+BLK+". The ceiling glows with a pale "+HIY+"yellow\
"+NORM+BYEL+BLK+" light that faintly \nilluminates the room without \
casting a shadow. There is a tall, \nthin ladder that rises along the \
wall and into the ceiling.\n";
        items = ({
            "room",
            "This is the same room you just entered",
            "bottom",
            "All around are piles of "+HIY+"yellow"+NORM+" grain",
            "silo",
            "This is a large, round, "+HIY+"yellow"+NORM+", cylindrical shaped room",
            "grain",
            "This "+HIY+"yellow"+NORM+" grain represents the latest harvest",
            "wall",
            "The wall is made of "+HIY+"yellow"+NORM+" amber and is curved",
            "walls",
            "The walls are made of "+HIY+"yellow"+NORM+" amber and curved",
            "ceiling",
            "The ceiling glows with a strange, pale,"+HIY+"yellow"+NORM+" light",
            "shadow",
            "There is no shadow here",
            "light",
            "The "+HIY+"yellow"+NORM+" light illuminates the inside of the silo",
            "ladder",
            "The ladder is mounted to the wall and rises through the "+HIY+"\
yellow"+NORM+" ceiling",
        });
        dest_dir = ({"climb_placeholder",NORM+HIY+"climb"+NORM
        });
    }
}

init() {
    ::init();
    add_action("search_me","search");
    add_action("random_exit","climb");
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

