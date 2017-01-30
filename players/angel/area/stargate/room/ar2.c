/*                                                                    *
 *    File:             /players/angel/area/stargate/room/ar.c        *
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

int x;

/* The NPC code had to be placed outside the reset inorder for\n\
 * the NPC's roam to kick in when loaded */
void reset(int arg){
  if(arg) return;
  if( !present("mp", this_object()) )
    call_out("get_mp", 1);
  ::reset(arg);
  set_light(1);
  short_desc = HIC+"ARMORY"+NORM;
  long_desc =
"    "+HIC+"~ ARMORY ~"+NORM+"\n\
"+CYN+"  Though there is a main armory at S.G.C., several smaller arms\n\
lockers like this can be found throughout the base. Often equipped\n\
with bullet-proof gear, P-90s and other Earth equipment, the armories\n\
can be stocked with alien weaponry, such as zat'ni'katels and staff\n\
weapons in the event an intruder cannot be disabled otherwise."+NORM+"\n";

  items =
  ({
   "armory",
    "military weapon storage",
    "arms",
    "weapons",
    "lockers",
    "metal spaces to hold personal affects",
    "base",
    "A large underground falicity that shelters military equipment and personnel",
    "gear",
    "It is locked up and not accessable",
    "P90",
    "A machine gun",
    "equipment",
    "It is locked up and not accessable",
    "weaponary",
    "It is locked up and not accessable",
    "zatnikatels",
    "A weapon formed in the shape of a coiled serpent",
    "staff",
    "A weapon of Goa'uld design",
    "weapons",
    "many types of hand guns",
    "intruder",
    "usually an enemy",
  });

  dest_dir =
  ({
	"/players/angel/area/stargate/room/hall8", "west",
  });
}

void get_mp(){
  for(x=0; x<3; x++)
    {
  move_object(clone_object("/players/angel/area/stargate/npc/private_02.c"), this_object());
    }
  tell_room(this_object(), "An MP arrives.\n");
}

init(){
  ::init();
    this_player()->set_fight_area();
   }

exit(){    if(this_player()) this_player()->clear_fight_area();     }