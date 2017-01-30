/*                                                                    *
 *    File:             /players/angel/area/stargate/room/go.c        *
 *    Function:         room                                          *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2006 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           11/15/06                                      *
 *    Notes:                                                          *
 *                                                                    *
 *                                                                    *
 *    Change History:                                                 *
 */

#include "/sys/lib.h"
 
#include <ansi.h>

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if( !present("landry", this_object()) )
    move_object(clone_object("/players/angel/area/stargate/npc/landry.c"), this_object());
  if(arg) return;
  set_light(1);
  short_desc = HIC+"General's Office"+NORM;
  long_desc =
"    "+HIC+"~ General's Office ~"+NORM+"\n\
"+CYN+"  The General's office is directly accessible from the briefing room.\n\
Through a smaller version of the star map the base's commander can view the\n\
briefing room and the Stargate (if the blast door is raised), but still have\n\
enough privacy to carry out personal matters with officers or guests, and to\n\
fill out paperwork at his leisure."+NORM+"\n";

  items =
  ({
    "office",
    "It is all decked out",
    "star map",
    "a map of the star systems",
    "blast door",
    "They appear to be heavy duty alloy titanium",
    "briefing room",
    "This room serves as a conference area",
  });

  dest_dir =
  ({
	"/players/angel/area/stargate/room/hall6", "east",
  });
}

init(){
  ::init();
    this_player()->set_fight_area();
   }

exit(){    if(this_player()) this_player()->clear_fight_area();     }

realm(){ return "NT"; }