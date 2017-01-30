/******************************************************************************
 *	File:			enter.c
 *	Function:		
 *	Author(s):		Vital@Nirvana
 *	Copyright:		Copyright (c) 2003 v-Dev Code Factory
 *					All Rights Reserved.
 *	Source:			9/11/03
 *	Notes:			
 *	Change History: 9/13/03
 *****************************************************************************/

#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"
#include "../color.h"

inherit "room/room";
inherit PROBABLE_EXITS;

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(1);
    set_short("Realm of Color");
    set_long("\
  This is the entrance to the realm of color. Here colors bound and\n\
wound around the fabric of space and time. Each color is unique and\n\
holds a special promise within it of greater power. Collect and \n\
combine color within your own sphere of influence to open the doors\n\
of power unimagined.\n");
    items =
    ({
      "color","The colors swirl all around, under, over, behind and infront.\n",
      "fabric","The very essence of reality.\n"
    });
    dest_dir =
    ({
        "/players/vital/dest/spaceport/rooms/entrance.c","out",
        "placeholder_enter","enter"
    });
  }
}

init()
{
  ::init();
  add_action("search_me","search");
  add_action("random_exit","enter");
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

random_exit();

