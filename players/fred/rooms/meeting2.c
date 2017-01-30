/*****************************************************************************
 *      File:                   meeting2.c
 *      Function:               room for acs area
 *      Author(s):              Highlander@Nirvana
 *      Copyright:              Copyright (c) 2011 Highlander 
 *                              All Rights Reserved.
 *      Source:                 2/24/2011
 *      Notes:                  clones mary
 *      Change History:         
 ****************************************************************************/
inherit "room/room";
reset(arg)
{
  if(arg) return;
  
  if(!present("Mary"), this_object())
  {
    move_object(clone_object("/players/highlander/areas/acs/mobs/mary.c"), this_object());
  }

  ::reset();

  set_light(1);
  short_desc="Sprint/Nextel Meeting Room";
long_desc=
 "Welcome to Sprint/Nextel. This room is littered with pictures of Sprint\n"+
 "products. In the middle of the room there is a long desk surrounded by black\n"+
 "leather chairs. There is a lone computer terminal sitting on the desk. This\n" +
 "is obviously where meetings are held that deal with Sprint/Nextel and their\n"+
 "many products. Along one wall is what looks like a movie/projection screen.\n"+  
 "In the middle of the celing there is what appears to be something similiar\n"+
 "to a movie projector but without the reels.\n"; 
 
items=({
 "desk", "A massive desk made of the finest red cherry wood money can buy",
 "chairs", "Several large plush leather chairs",
 "computer", "A Dell computer, currently in screen saver mode",
 "screen", "A plastic,vinyl, white screen used in conjunction with a projector\n"+
 "for viewing",
 "projector", "A piece of equipment used by Sprint managers for training\n"+
 "purposes",

 }); 

dest_dir=({
 "/players/highlander/areas/acs/rooms/sprint1.c","out",
 
 
           });
        }