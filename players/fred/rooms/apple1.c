/*****************************************************************************
 *      File:                   apple1.c
 *      Function:               room for acs area
 *      Author(s):              Highlander@Nirvana
 *      Copyright:              Copyright (c) 2011 Highlander 
 *                              All Rights Reserved.
 *      Source:                 2/24/2011
 *      Notes:                  clones james,john,krista
 *      Change History:         
 ****************************************************************************/
inherit "room/room";
reset(arg)
{
  if(arg) return;
  
  if(!present("James"), this_object())
  {
    move_object(clone_object("/players/highlander/areas/acs/mobs/james.c"), this_object());
  }
  
  if(!present("John"), this_object())
  {
    move_object(clone_object("/players/highlander/areas/acs/mobs/john.c"), this_object());

  if(!present("Krista"), this_object())
  {
    move_object(clone_object("/players/highlander/areas/acs/mobs/krista.c"), this_object());
  }
  
  ::reset();
  
  set_light(1);
  short_desc="Apple Inc";
long_desc=
 "Welcome to Apple Inc!  This room is littered with pictures of Apple products,\n" +
 "computers, big screen LCD television sets, and work stations.  The room is\n" +
 "alive with the voices of dozens of agents hard at work assisting their\n"+
 "customers on whatever problem they are currently having.\n";  

items=({
 "station", "A work station consisting of desk, chair and computer",
 "chairs", "A comfortable chair made of black leather",
 "computer", "An IMac computer, currently manned an agent",
 "desk", "A desk made of metal, shaped like a cubicle",
 "set", "A very large screen that is currently flashing a quarterly report\n"+ 
"across the bottom of the screen",
 });
 


dest_dir=({
 "/players/highlander/areas/acs/rooms/meeting1.c","room1",
 "/players/highlander/areas/acs/rooms/office5.c","om",
 "/players/highlander/areas/acs/rooms/mroom1.c","mens",
 "/players/highlander/areas/acs/rooms/froom1.c","womens",
 "/players/highlander/areas/acs/rooms/staircase1.c","down",
 
           });
        }
}
