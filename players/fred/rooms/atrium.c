/*****************************************************************************
 *      File:                   atrium.c
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
  short_desc="Indoor Atrium";
long_desc=
 "This is the inside of ACS.  You have entered the indoor atrium.  Plants\n" +
 "line this entire room in a open pattern.  The plants are what supply the\n" +
 "ambiance of this popular place to work.  Employees stroll around talking\n" +
 "to one another about work, lunch or whatever else they feel like.  There are\n"+
 "steps that lead up to the third floor as well as steps leading down to the\n"+
 "first floor.  Office doors are a plenty in this room as well.  Perhaps you\n"+
 "should 'look' at each door to see where they lead.\n"; 

items=({
  "plants", "Lush green plants glistening in the afternoon sun.",
 });

dest_dir=({
 "/players/highlander/areas/acs/rooms/recruiting.c","office1",
 "/players/highlander/areas/acs/rooms/testing.c","office2",
 "/players/highlander/areas/acs/rooms/payroll.c","office3",
 "/players/highlander/areas/acs/rooms/security.c","out",
 "/players/highlander/areas/acs/rooms/staircase1.c","up",
 "/players/highlander/areas/acs/rooms/staircase2.c","down",
           });
        }
init()
{
  ::init();

  add_action("Cmd_look","look",1);
}

Cmd_look(string str)
{
  if(str == "at door1")
  {
    write("Recruiting\n");
    return 1;
  }
  if(str == "at door2")
  {
    write("Testing\n");
    return 1;
  }
  if(str == "at door3")
  {
    write("Payroll\n");
    return 1;
  }
  else
  {
    write("You can look at door1, door2, or door3.\n");
    return 1;
  }
}
