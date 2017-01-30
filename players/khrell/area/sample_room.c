/******************************************************************************
 *	File:			sample_room.c
 *	Function:		
 *	Author(s):		Vital@Nirvana
 *	Copyright:		Copyright (c) 2004 v-Dev Code Factory
 *					All Rights Reserved.
 *	Source:			5/1/04
 *	Notes:			
 *	Change History:
 *****************************************************************************/

#include <ansi.h>

inherit "room/room";

reset(arg) {
  if(!arg)
  { 
    set_light(1);
    short_desc = "Bleh";
    long_desc =
"  This is just some text to give the sample room some fill so that \n\
it doesn't look empty when Katya looks at it for an example of \n\
something roomy and spacious in a good neighborhood\n";

    items =
    ({
        "item",
        "description",
        "another",
        "It looks like this",
    });
    dest_dir =
    ({
        "/room/vill_green.c",           "green",
        "/players/vital/workroom.c",    "home",
    });
  }
}

init()
{
    ::init();
    add_action("search_me","search");
}

search_me(str)
{
    if(!str)
    {
        notify_fail("What are trying to search?\n");
        return 0;
    }
    write("You furiously search the "+str+" but find nothing.\n");
    return 1;
}
