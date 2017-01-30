/*****************************************************************************
 *      File:                   sprint1.c
 *      Function:               room for acs area
 *      Author(s):              Highlander@Nirvana
 *      Copyright:              Copyright (c) 2011 Highlander 
 *                              All Rights Reserved.
 *      Source:                 2/24/2011
 *      Notes:                  clones zeke,amy,linda
 *      Change History:         
 ****************************************************************************/
inherit "room/room";
reset(arg)
{
  if(arg) return;
  
  if(!present("Zeke"), this_object())
  {
    move_object(clone_object("/players/highlander/areas/acs/mobs/zeke.c"), this_object());
  }
  
  if(!present("Amy"), this_object())
  {
    move_object(clone_object("/players/highlander/areas/acs/mobs/amy.c"), this_object());

  if(!present("Linda"), this_object())
  {
    move_object(clone_object("/players/highlander/areas/acs/mobs/linda.c"), this_object());
  }

  ::reset();
 
  set_light(1);
  short_desc="Sprint/Nextel";
long_desc=
 "Welcome to Sprint/Nextel.  This room is littered with pictures of Sprint\n" +
 "products,computers, and work stations.  The room is alive with the voices of\n" +
 "dozens of agents hard at work assisting their customers on whatever problem\n"+
 "they are currently having.\n";

items=({
 "station", "A work station consisting of desk, chair and computer",
 "chairs", "A comfortable chair made of black leather",
 "computer", "An DELL computer, currently manned an agent",
 "desk", "A desk made of metal, shaped like a cubicle",
 }); 


dest_dir=({
 "/players/highlander/areas/acs/rooms/meeting2.c","room1",
 "/players/highlander/areas/acs/rooms/office4.c","om",
 "/players/highlander/areas/acs/rooms/mroom2.c","mens",
 "/players/highlander/areas/acs/rooms/froom2.c","womens",
 "/players/highlander/areas/acs/rooms/staircase2.c","up",
 
           });
        }
}