/*****************************************************************************
 *      File:                   staircase1.c
 *      Function:               room for acs area
 *      Author(s):              Highlander@Nirvana
 *      Copyright:              Copyright (c) 2011 Highlander 
 *                              All Rights Reserved.
 *      Source:                 2/24/2011
 *      Notes:                 
 *      Change History:         
 ****************************************************************************/
inherit "room/room";
reset(arg){
  set_light(1);
  short_desc="Staircase";
long_desc=
 "You start to climb the staircase.  On the walls are pictures of ACS slogans\n"+
 "Honor, Respect, Dedication, Persistance.  Each picture has a different face\n"+
 "on it.  You can continue 'up' to the third floor, or 'down'to the second.\n";

 


dest_dir=({
 "/players/highlander/areas/acs/rooms/atrium.c","down",
 "/players/highlander/areas/acs/rooms/apple1.c","up",
 
           });
        }