/*
 *  File:   /players/mosobp/areas/VEGETA/rooms/vegeta4.c
 *  Function:  room
 *  Author(s):  Mosobp@Nirvana
 *  Copyright: copyright (c) 2008 Mosobp
 *             all rights reserved 
 *                                       
 *                                       
 *  Source:  08/24/2014
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
    "/players/mosobp/areas/VEGETA/rooms/vegeta5.c",  "northwest",
    "/players/mosobp/areas/VEGETA/rooms/vegeta3.c",    "southwest",
  });
  return 1;
}