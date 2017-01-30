/*****************************************************************************
 *      File:                   recruiting.c
 *      Function:               room for acs area
 *      Author(s):              Highlander@Nirvana
 *      Copyright:              Copyright (c) 2011 Highlander 
 *                              All Rights Reserved.
 *      Source:                 2/24/2011
 *      Notes:                  random clones todd
 *      Change History:         
 ****************************************************************************/
inherit "room/room";
reset(arg)
{
  if(arg) return;
  
  if((!present("Todd"), this_object()) && !random(3))
  {
    move_object(clone_object("/players/highlander/areas/acs/mobs/todd.c"), this_object());
  }

  set_light(1);
  short_desc="Recruiting Office";
long_desc=
 "This is the Recruiting Office for both divisions of this ACS branch.\n" +
 "You would come to this office if you receive an invitation to join the \n" +
 "company.  It is a very busy place at times and on other occasions noone \n" +
 "is here.  This room is littered with tables and chairs.  Computers line \n"+
 "the north wall.  File cabinets line the west wall.\n";
 
items=({
 "table", "A table made of processed wood and plastic supported by steel legs",
 "chairs", "A comfortable chair made of black leather",
 "computer", "A Dell compter currently turned off",
 "Cabinets", "A group pf steel cabinets used to store files and other junk",
 });


dest_dir=({
 "/players/highlander/areas/acs/rooms/atrium.c","out",
 
           });
        }