/*                                                                              *
 *      File:             /players/angel/area/school/room/nurse_office_01.c     *
 *      Function:         room                                                  *
 *      Author(s):        Angel@Nirvana                                         *
 *      Copyright:        Copyright (c) 2006 Angel (Josh Hatfield)              *
 *                                All Rights Reserved.                          *
 *      Source:           11/15/06                                              *
 *      Notes:                                                                  *
 *                                                                              *
 *                                                                              *
 *      Change History:                                                         *
 */

#include <ansi.h>

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if( !present("principal", this_object()) )
    move_object(clone_object("/players/angel/area/school/npc/nurse_01.c"), this_object());
  if(arg) return;
  set_light(1);
  short_desc = "Nurses Office";
  long_desc =
"  This is the Nurses office. The walls are white, the drapes\n\
are white, the cots are white, and the cabinets on the wall are\n\
white as well. This is where the nurse takes care of sick students\n\
and where the student wait for their parents to pick them up.\n";
 
  items =
  ({
    "office",
    "This is a small white room",
    "students",
    "They are sick",
    "walls",
    "The walls are white and very clean. The only thing on the walls are\n\
the medicine cabinets",
    "drapes",
    "They hang over the window",
    "cots",
    "The cots are white and look uncomfortable",
    "cabinets",
    "Medicine cabinet's on the wall with a sign that says\n\
students' meds",
    "medical supplies",
    "You see some different types of medical supplies to aid the nurse",
  });
  dest_dir =
  ({
    "/players/angel/area/school/room/entrance", "south",	  
  });
}