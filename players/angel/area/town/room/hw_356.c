/*                                                                    *
 *    File:             /players/angel/area/town/room/hw_356.c        *
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
  if( !present("johnny", this_object()) )
    call_out("get_johnny", 1);
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc = "Highway 35";
  long_desc =
"    "+HIC+"HW 35"+NORM+"\n\
  Highway 35 west leads to more towns, however the bridge is\n\
currently under construction. Tote-a-burger is to the southeast.\n\
To the south is Broadway street which leads to the local park.\n";

  items =
  ({
  "highway",
  "Highway 35 runs through Gas City connecting it to I-69.",
  "towns",
  "There are several small towns closely located to Gas City,\n\
but you can't see them from here",
  "tote-a-burger",
  "This is a burger joint where you can sit down and eat",
  "street",
  "The road has been newly paved and appears to be rich black in color",
  "broadway",
  "This road leads to the park and other city services",
  "park",
  "The park is fully loaded.  It looks to be very large with\n\
3 baseball fields, 2 soccer field, 2 basketball courts and\n\
a public swimming pool. There is a ton of equipment for\n\
children to play on and several picnic areas around the pond",
  "bridge",
  "There was an old suspension bridge that has become unstable\n\
so the city is putting in a new state of the art bridge. The\n\
city council has decided to name the new bridge after Mayor\n\
Robert Ray",
});
  dest_dir =
  ({
    "/players/angel/area/town/room/hw_355",           "east",
    "/players/angel/area/town/room/toteaburger",      "burger",
/*
    "/players/angel/area/town/room/broadway_01",      "south",
    
*/
  });
}

void get_johnny(){
  for(x=0; x<1; x++)
    {
  move_object(clone_object("/players/angel/area/town/npc/johnny.c"), this_object());
    }
  tell_room(this_object(), "Johnny has arrived.\n");
}

init()
  {
  ::init();
  add_action("no_south","south"); 
  add_action("no_west","west");
  }

no_south(){
write("The road is blocked by fallen trees.\nYou will have to find another way.\n");
return 1;
}

no_west(){
write("the bridge is currently under construction.\nYou will have to find another way.\n");
return 1;
}