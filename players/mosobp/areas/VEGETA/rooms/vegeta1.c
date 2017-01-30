/*
 *  File:   /players/mosobp/areas/VEGETA/rooms/vegeta1.c
 *  Function:  room
 *  Author(s):  Mosobp@Nirvana
 *  Copyright: copyright (c) 2013 Mosobp
 *             all rights reserved 
 *                                       
 *                                       
 *  Source:  08/13/2013
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
  "This is the road to the entrance of the Saiyan Castle. The spaceship\n"+
  "which brought you is behind, and the Castle looming in the distance.\n"+
  "There are bushes on the ground around, and trees giving\n"+
  "shade overhead.\n";
  
  items=
  ({
    "road",
    "This is a shining surface that appears very slick",
    "castle", 
    "The castle is barely distinguishable from this distance",
	"bushes",
	"The bushes are dotted along the side of the road",
	"trees",
	"The trees are surrounded by bushes along the side of the road",
	"ship",
	"Behind is the ship which brought you here to Planet Vegeta",
  });
  
  dest_dir =
  ({
    "/players/mosobp/areas/VEGETA/rooms/vegeta0.c",   "down",
    "/players/mosobp/areas/VEGETA/rooms/vegeta2.c",   "north",
	"/players/mosobp/areas/VEGETA/rooms/vegeta9.c",   "west",
	"/players/mosobp/areas/VEGETA/rooms/vegeta15.c",  "east",
  });
  return 1;
}