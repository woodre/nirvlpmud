/*************************************************************************
 * File:			  c4.c
 * Function:		Bronze Citadel room
 * Author(s):		Sparrow@Nirvana
 * Copyright:		Copyright (c) 2012 Sparrow
 *              All Rights Reserved
 * Source:			8/25/2012
 * Notes:			                                   
 * Change History:
 *
 ************************************************************************/
#include <ansi.h>
#define PATH "/players/sparrow/areas/baator/avernus/citadel/"
#define terrain "city"
#define enviro "outdoors"

inherit "room/room";
  reset(arg){
  if(!arg){
    set_light(1);
    short_desc= HIR+"Baator ["+HIK+"Avernus"+HIR+"] ["+NORM+YELLOW+"Bronze Citadel"+HIR+"]"+NORM;
    long_desc="\n";
    items=({ });
    dest_dir=({
      PATH+"b3.c","northwest",
      PATH+"c5.c","south",
      PATH+"d4.c","east",
      PATH+"c3.c","north",
    });
  }   
}

init()  {
 ::init();
  add_action("search_room","search");
}

search_room() {
  write("You find nothing of interest in the general area.\n");
  say (this_player()->query_name() +" searches the general area.\n");
  return 1;  
}
