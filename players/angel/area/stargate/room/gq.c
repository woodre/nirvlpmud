/*                                                                    *
 *    File:             /players/angel/area/stargate/room/gq.c        *
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
  if(arg) return;
  set_light(1);
  short_desc = HIC+"Guest Quarters"+NORM;
  long_desc =
"    "+HIC+"~ Guest Quarters ~"+NORM+"\n\
"+CYN+"  This is a basic space that is available for the average guest, not\n\
unlike a typical hotel room. A bed as a centerpiece, flanked by two\n\
night stands, is offered to most individuals, including many of the\n\
base's higher-ranking personnel."+NORM+"\n";

  items =
  ({
    "space",
    "It looks like a hotel room",
    "guest",
    "A forigen dignatary",
    "room",
    "The room looks like a nice hotel room",
    "bed",
    "It look comfy",
    "stands",
    "They appear to be solid oak",
    "base",
    "A large underground falicity that shelters military equipment and personnel",
  });

  dest_dir =
  ({
	"/players/angel/area/stargate/room/hall7", "east",
  });
}

init(){
  ::init();
    this_player()->set_fight_area();
   }

exit(){    if(this_player()) this_player()->clear_fight_area();     }

realm(){ return "NT"; }