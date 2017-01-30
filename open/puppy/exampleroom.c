/*                      /                                             *
 *    File:             /players/sami/area/GPO/entrance.c   *
 *    Function:         room                                          *
 *    Author(s):        Sami@Nirvana                                  *
 *    Copyright:        Copyright (c) 2014 Sami                       *
 *                              All Rights Reserved.                  *
 *    Source:                   10/4                                  *
 *    Notes:                                                          *
 *                                                                    *
 *                                                                    *
 *    Change History:                                                 *
 */
inherit "/players/vertebraker/closed/std/room.c";
#include <ansi.h>
#include "/players/jareel/define.h"

reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("teleporter room");
  long_desc =
" O-==========================================================================-O\n"+
" |    |    |  You find yourself in a dark room with a transporter device in\n"+
" |    |    |  the middle.  There room has four open exits each leading to a\n"+
" |    |    |  dimly lit hallway.  The smell of death is prevalent in the air,\n"+
" | ---"+HIR+"*"+NORM+"--- |  and you can hear things slinking around in the darkness.  From\n"+
" |    |    |  what you can tell this entire part of the space station has been\n"+
" |    |    |  destroyed.\n"+
" |    |    |\n"+
" O-==========================================================================-O\n";

   items =
    ({
	"transporter",
	 "an alien mechanism formed of some strange metals. it appears to be broken.",
    "metals",
    "Strange metallic alloy, unlike any that you have seen before.",
    	
});
add_exit("/players/sami/area/GPO/nhallway1.c","north");
add_exit("/players/sami/area/GPO/shallway1.c","south");
add_exit("/players/sami/area/GPO/hih1.c","west");
add_exit("/players/sami/area/GPO/labhall1.c","east");
add_exit("room/mount_pass.c","out");
}