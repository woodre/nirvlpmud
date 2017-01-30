/*                                                                    *
 *    File:             /players/angel/area/stargate/room/cr.c        *
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
  short_desc = HIC+"COMMISSARY"+NORM;
  long_desc =
"    "+HIC+"~ COMMISSARY ~"+NORM+"\n\
"+CYN+"  The kitchen primarily serves the commissary, open to all base\n\
personnel. Rotating foods vary from lemon chicken to colored gelatin.\n\
The base is stocked with several months worth of food in the event of\n\
a lockdown."+NORM+"\n";

  items =
  ({
	"kitchen",
	"A large commercial style room for food preparation",
	"commissary",
	"It provides cooked meals and some groceries to military personnel",
	"base",
	"A large underground facility that shelters military equipment and personnel",
	"foods",
	"It looks edible",
	"food",
	"It looks edible",
	"lemon",
	"It appears to be round and yellow",
	"chicken",
	"Its no longer living",
	"gelatin",
	"J E L L O",
  });

  dest_dir =
  ({
	"/players/angel/area/stargate/room/hall1", "west",
  });
}

init(){
  ::init();
    this_player()->set_fight_area();
   }

exit(){    if(this_player()) this_player()->clear_fight_area();     }

realm(){ return "NT"; }