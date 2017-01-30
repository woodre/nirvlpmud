/*****************************************************************************
 *      File:                   meeting1.c
 *      Function:               room for acs area
 *      Author(s):              Highlander@Nirvana
 *      Copyright:              Copyright (c) 2011 Highlander 
 *                              All Rights Reserved.
 *      Source:                 2/24/2011
 *      Notes:                  clones scott
 *      Change History:         
 ****************************************************************************/
inherit "room/room";
reset(arg)
{
  if(arg) return;
  
  if(!present("Scott"), this_object())
  {
    move_object(clone_object("/players/highlander/areas/acs/mobs/scott.c"), this_object());
  }

  ::reset();

  set_light(1);
  short_desc="Apple Inc Meeting Room";
long_desc=
 "Welcome to Apple Inc.  This room is littered with pictures of Apple products.\n" +
 "In the middle of the room there is a long desk surrounded by black leather\n" +
 "chairs. This is obviously where meetings are held that deal with Apple Inc.\n"+
 "and their products.\n";  

items=({
 "desk", "A massive desk made of the finest red cherry wood money can buy",
 "chairs", "Several large plush leather chairs",

 }); 


dest_dir=({
 "/players/highlander/areas/acs/rooms/apple1.c","out",
 
 
           });
        }