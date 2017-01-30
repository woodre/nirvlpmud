/*                                                                    *
 *    File:             /players/angel/area/atlantis/room/mb.c        *
 *    Function:         room                                          *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2007 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           08/15/07                                      *
 *    Notes:                                                          *
 *                                                                    *
 *                                                                    *
 *    Change History:                                                 *
 */

#include "/sys/lib.h"

#include <ansi.h>

inherit "room/room";
int x;

reset(arg)
{
  ::reset(arg);
  if( !present("beckett", this_object()) )
    move_object(clone_object("/players/angel/area/atlantis/npc/beckett.c"), this_object());
  if( !present("wounded", this_object()) )
  {
    for(x=0; x<3; x++)
    {
    move_object(clone_object("/players/angel/area/atlantis/npc/wp.c"), this_object());
    }}
if(arg) return;
  set_light(1);
  short_desc = "MEDICAL BAY";
  long_desc =
"    "+WHT+"~ MEDICAL BAY ~"+NORM+"\n\
"+HIB+"  Chief facility for tending to the sick and injured, which is also\n\
well-equipped for biological research. The room can accommodate\n\
multiple wounded, as well as Dr. Carson Beckett's on-going gene\n\
therapy and medical research. An adjacent room can also house\n\
recovering wounded."+NORM+"\n";

  items =
  ({
    "wounded",
    "hurt people",
    "sick",
    "they have seen better days",
    "injured",
    "hurt people",
  });
  
  dest_dir =
  ({
	"/players/angel/area/atlantis/room/hall_03.c",     "south",
  });
}