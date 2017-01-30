/*                                                                    *
 *    File:             /players/angel/area/atlantis/room/brig.c      *
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

reset(arg)
{
  ::reset(arg);
  if( !present("mpo", this_object()) )
    move_object(clone_object("/players/angel/area/stargate/npc/sergeant_02.c"), this_object());
  if( !present("sergeant", this_object()) )
    move_object(clone_object("/players/angel/area/stargate/npc/sergeant.c"), this_object());
if(arg) return;
  set_light(1);
  short_desc = "BRIG";
  long_desc =
"   "+WHT+"~ BRIG ~"+NORM+"\n\
"+HIB+"  This area was constructed with advanced Ancient forcefields,\n\
this rudimentary square space can house many foes. Not even\n\
Wraith are able to penetrate the forcefield barriers.  Only\n\
when the chamber is unlocked do the forcefields drop away,\n\
allowing admittance for personnel."+NORM+"\n";

  items =
  ({
    "forcefield",
	"made of high tech lasers and can be disarmed with the right knowledge",
    "barriers",
    "made of high tech lasers and can be disarmed with the right knowledge",
    "chamber",
    "gray metal mesh walls reinforced with a laser forcefield\n\
    and there is a small box by the entrance",
    "walls",
    "The walls appear to be a solid titanium allow",
    "wall",
    "The walls appear to be a solid titanium allow",
    "box",
    "it looks like someone could swipe an id here",
  });

  dest_dir =
  ({
	"/players/angel/area/atlantis/room/tp_03.c",     "south",
  });
}

init() {
  ::init();
  add_action("disarm","disarm");
}

disarm(str) {
object ob;
if(present("sergeant")) {
  write("The Sergeant jumps in front of you and says\n\
  'I told you this is a restricted area!'\n");
  return 1; }
if(!str) { write("disarm what?\n"); return 1; }
if(str == "forcefield") {
  if(!present("military id",this_player())) {
    write("You do not have the means to disarm the forcefield.\n");
    return 1; }
  if(present("military id",this_player())) {
    ob = present("military id",this_player());
    write("You insert the military id and see the forcefield dissipate.\n");
    destruct(ob);
    this_player()->move_player(
    " walks into the chamber#/players/angel/area/atlantis/room/brig_02.c");
    return 1; }
return 1; }
}