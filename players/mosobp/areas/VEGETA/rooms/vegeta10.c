/*
 *  File:   /players/mosobp/areas/TOWER/rooms/t1.c
 *  Function:  room
 *  Author(s):  Mosobp@Nirvana
 *  Copyright: copyright (c) 2008 Mosobp
 *             all rights reserved 
 *                                       
 *                                       
 *  Source:  7/17/08
 *  Notes:  
 *  
 *   
 *  Change History:              
 */

#include "/sys/lib.h"

#include "/obj/ansi.h"

inherit "room/room";

reset(arg)
{
  ::reset(arg);
   
  if(arg) return;
  set_light(1);
  short_desc = RED+"Planet Vegeta"+NORM;
  long_desc = 
  "  "+HIB+"blah"+NORM+"\n";
  
  items=
  ({
    "tower",
    "This is a shining surface that appears very slick",
    "platform", 
    "The platform is barely distinguishable from this distance",
  });
  
  dest_dir =
  ({
    "/players/mosobp/areas/VEGETA/rooms/vegeta9.c",   "north",
    "/players/mosobp/areas/VEGETA/rooms/vegeta11.c",  "south",
	"/players/mosobp/areas/VEGETA/rooms/vegeta0.c",   "down",
  });
  return 1;
}