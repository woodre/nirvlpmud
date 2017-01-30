/*                                                                    *
 *    File:             /players/sami/area/carnival/room/oak_tree.c   *
 *    Function:         room                                          *
 *    Author(s):        Sami@Nirvana                                  *
 *    Copyright:        Copyright (c) 2008 Sami                       *
 *                              All Rights Reserved.                  *
 *    Source:           11/12/08                                      *
 *    Notes:                                                          *
 *                                                                    *
 *                                                                    *
 *    Change History:                                                 *
 */
inherit "/players/jareel/room";
#include "/players/jareel/define.h"

#define MOCO move_object(clone_object

reset(arg) {
  if(!present("spider"))  {
    MOCO("/players/sami/monsters/spider2.c"),this_object()); }
  if(!present("spider"))  {
    MOCO("/players/sami/monsters/spider2.c"),this_object()); } 
      if(arg) return; 
  set_light(-1);
  short_desc = "In a Tree";
  long_desc =
    "A very small, makeshift platform allows you to stand easily high\n"+
    "up in this oak. undings, however you can see a huge tent to the north of\n"+
    "the pathway.\n"; 
  items =  ({
    "tent",
    "You can see a Huge red and black tent much resembleing the others\n\
     in the distance.",
    "platform",
    "Obviously placed here many years ago has withstood the test of time.\n\
     There are termite holes in some of the planks which are beginning\n\
     to rot away",
   });
 
 dest_dir =  
   ({ "/players/sami/area/carnival/room/path_to_ruin0", "climb oak",});
 }
init()   {
  ::init();
    add_action("climb","climb");
}

int climb(string str)   {
  if(!str || str != "oak")
    return 0;
  say(this_player()->query_name() + " climbs the oaktree.\n");
    move_object(this_player(),"/players/sami/area/carnival/room/path_to_ruin0");
     command("look",this_player());
  return 1;
}
 
x
