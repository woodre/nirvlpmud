/*****************************************************************************
 *      File:                   victory-portal.c
 *      Function:               This appears when a player defeats the OPL
 *                              and provides a free ride to end post office.
 *      Author(s):              Mizan@Nirvana
 *      Copyright:              Copyright (c) 2011 Mizan@Nirvana
 *                              All Rights Reserved.
 *      Source:                 2/2011
 *      Notes:
 *      Change History:
 ****************************************************************************/
#include "/obj/ansi.h"


id(str) { return str == "portal"; }

is_castle() { return 1; }

short() 
{
    return "A " + HIK + HBRED + "VICTORY PORTAL" + NORM + " teleporting to the post office";
}

long() 
{
    write("This magical portal exists because you badasses beat the\n"+
    "ultimate badass of them all... OVERPOWERLORD! That makes you guys\n"+
    "the new ULTIMATE BADASSES of the MUD!\n"+
    "You can 'enter' this portal for a victory march to the post office\n"+
    "and claim some real-world goodies from Mizan.\n");
}

init()
{
    add_action("long_entry","enter");
}

long_entry() 
{
    if(this_player() && this_player()->is_vehicle())
    {
        write("Nice try, wise guy.\n");
        return 1;
    }

    this_player()->move_player("portal#/room/post.c");
    return 1;
}


