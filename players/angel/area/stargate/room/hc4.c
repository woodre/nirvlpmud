/*                                                                    *
 *    File:             /players/angel/area/stargate/room/hc.c        *
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
  short_desc = HIC+"Holding Cell"+NORM;
  long_desc =
"    "+HIC+"~ Holding Cells ~"+NORM+"\n\
"+CYN+"  In the event a threat does not pose a biological hazard to base\n\
personnel (or the population outside), standard holding cells of\n\
varying sizes number in the many at S.G.C. large rooms can hold\n\
prisoners for interrogation from the opposite side."+NORM+"\n";

  items =
  ({
    "cells",
	"Small empty concrete rooms",
	"cell",
	"A small empty concrete room",
  });

  dest_dir =
  ({
	"/players/angel/area/stargate/room/hall9", "west",
  });
}

init(){
  ::init();
    this_player()->set_fight_area();
   }

exit(){    if(this_player()) this_player()->clear_fight_area();     }