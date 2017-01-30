/*                                                                    *
 *    File:             /players/angel/area/town/room/emain_10.c      *
 *    Function:         room                                          *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2007 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           11/15/07                                      *
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
  if( !present("bradly", this_object()) )
    call_out("get_bradly", 1);
  ::reset(arg);
  set_light(1);
  short_desc = "East Main & 10th";
  long_desc =
"    "+HIB+"East Main and Tenth"+NORM+".\n\
  This is the main street that goes through the middle of town.\n\
Most businesses are off of main street. It remains busy at all times\n\
of the day and night. During the day there is the hustle and bustle\n\
of business and at night the road stays busy with young kids cruising\n\
around town. There is a new Wal-Mart store is to the northeast.\n";

  items =
  ({
    "businesses",
    "There are many different business that keep the local economy going",
    "street",
    "Two way paved lanes with large sidewalks along the road",
    "town",
    "This is a small community",
    "road",
    "Two way paved lanes",
    "walmart",
    "Wal-Mart is a large retailer bent on overtaking the world!",  
});

  dest_dir =
  ({
    "/players/angel/area/town/room/10thna",               "north",
    "/players/angel/area/town/room/hw_354",               "east",
    "/players/angel/area/town/room/emain_09",             "west",
    "/players/angel/area/walmart/room/walmart_checkout",  "walmart",
  });
}

void get_bradly(){
  for(x=0; x<1; x++)
    {
  move_object(clone_object("/players/angel/area/town/npc/bradly.c"), this_object());
    }
  tell_room(this_object(), "Bradley has arrived.\n");
}