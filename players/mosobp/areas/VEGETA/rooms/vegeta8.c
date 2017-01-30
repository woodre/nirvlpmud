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

#define TP this_player()

inherit "room/room";

reset(arg)
{
  ::reset(arg);
   
  if(arg) return;
  set_light(1);
  short_desc = RED+"Vegeta Planet"+NORM;
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
    "/players/mosobp/areas/VEGETA/rooms/vegeta16.c",  "west",
    "/players/mosobp/areas/VEGETA/rooms/vegeta7.c",   "out",
  });
  return 1;
}

init() { 
    ::init(); 
   this_player()->set_fight_area();
   add_action("crawl opening","enter opening");
}
crawl(arg) {
if(!arg) {return 0;}
if(arg == "crawl" || arg == "opening" || arg == "the door") 
{
TP->move_player("through the opening#players/mosobp/areas/VEGETA/rooms/vegeta24.c");
return 1; 
}}