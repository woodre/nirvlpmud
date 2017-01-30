/*****************************************************************************
 *      File:                   testing.c
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
  short_desc="Testing Room";
long_desc=
 "This is the Testing Room for both divisions of this ACS branch.\n" +
 "You would come to this office if you receive an invitation to take the \n" +
 "tests required to work for either Apple or Sprint/Nextel.  At times this\n" +
 "room is packed with people on the computers taking the entrance tests, but\n"+
 "today your lucky if the tester is in the office.  A single desk sits in the\n"+
 "northeast corner.  Computer terminals and chairs line the south, east, and\n"+
 "west walls.\n";
 
items=({
 "table", "A table made of processed wood and plastic supported by steel legs",
 "chairs", "A comfortable chair made of black leather",
 "computers", "Several Dell compters currently turned off",
 "desk", "A desk made of hickory that has been varnished using a red wood stain",
 });


dest_dir=({
 "/players/highlander/areas/acs/rooms/atrium.c","out",
 
           });
        }