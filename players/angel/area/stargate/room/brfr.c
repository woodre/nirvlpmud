/*                                                                    *
 *    File:             /players/angel/area/stargate/room/brfr.c      *
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
  if( !present("mitchell", this_object()) )
    move_object(clone_object("/players/angel/area/stargate/npc/mitchell.c"), this_object());
  if( !present("tealc", this_object()) )
    move_object(clone_object("/players/angel/area/stargate/npc/tealc.c"), this_object());
  if(arg) return;
  set_light(1);
  short_desc = HIC+"BRIEFING ROOM"+NORM;
  long_desc =
"    "+HIC+"~ BRIEFING ROOM  ~"+NORM+"\n\
"+CYN+"  This briefing room serves as a conference area for S.G. units,\n\
their commanding officers and the General of the base, as well\n\
as neutral territory for alien dignitaries. This room directly\n\
overlooks the entire Gate Room."+NORM+"\n";

  items =
  ({
    "office",
    "It serves as a conference area",
    "units",
    "A group of four or five military personal",
    "officers",
    "military personel",
    "base",
    "A large underground falicity that shelters military equipment and personnel",
    "room",
    "a large concrete area",
    "gate room",
    "a large concrete area where the stargate sits",
    "Gate room",
    "a large concrete area where the stargate sits",
  });

  dest_dir =
  ({
	"/players/angel/area/stargate/room/hall6",  "west",
  });
}

init(){
  ::init();
    this_player()->set_fight_area();
  }

exit(){    if(this_player()) this_player()->clear_fight_area();     }

realm(){ return "NT"; }