/*****************************************************************************
 *      File:                   security.c
 *      Function:               room for acs area
 *      Author(s):              Highlander@Nirvana
 *      Copyright:              Copyright (c) 2011 Highlander 
 *                              All Rights Reserved.
 *      Source:                 2/24/2011
 *      Notes:                  non fight room. clones mike and steve
 *      Change History:         
 ****************************************************************************/
inherit "room/room";

reset(arg)
{
  if(arg) return;
  
  if(!present("Steve"), this_object())
  {
    move_object(clone_object("/players/highlander/areas/acs/mobs/steve.c"), this_object());
  }
  
  if(!present("Mike"), this_object())
  {
    move_object(clone_object("/players/highlander/areas/acs/mobs/mike.c"), this_object());
  } 

  ::reset();

  set_light(1);
  short_desc="ACS Security Room";
long_desc=
 "This is the security room of ACS.  It is a company that gets contracts\n" +
 "with companies all over the world as outsource help. This particuler\n" +
 "site deals with Apple Inc and Sprint/Nextel.  For Apple, agents provide\n" +
 "tech support for ipod, iphone, imac and ipad.  Each department has\n"+
 "several Tier 1 and Tier 2 techs.  For Sprint/Nextel, agents provide help\n"+
 "with customers cell phone bills.  There are 2 security guards manning the\n"+
 "desk in this room.  Maybe you should 'enter_acs' or 'out' to leave.\n"; 
items=({
  "desk", "A long wooden desk covered in paper and phones",
  "paper", "A stack of papers",
  "phone", "You know what a phone looks like",
 });
dest_dir=({
 "/players/highlander/areas/acs/rooms/atrium.c","enter_acs",
           });

        }
query_no_fight () { return 1; }