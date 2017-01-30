/*
 *      File:                   path1.c
 *      Function:               
 *      Author(s):              Hogath@Nirvana
 *      Copyright:              Copyright (c) 2004 Hogath
 *                                      All Rights Reserved.
 *      Source:                 06/15/2004
 *      Notes:                  Black forest for my area
 *      Change History:
 */

#include <ansi.h>
#include <security.h>
#include "/players/hogath/tools/def.h"
inherit "room/room";
int spri;

reset(arg) {
  spri = 0;
  if(!arg){
    set_light(1);
    short_desc = YEL+"Dirt Path"+NORM;
    long_desc = YEL+"The dirt here is tightly packed and looks as though it has\n"+
                    "seen many travelers.  On either side of the path are large\n"+
                    "foreboding trees which seem to discourage travel into the.\n"+
                    "forest.\n"+NORM;
    
    dest_dir = ({"/players/hogath/area/forest/PATH/path0.c","south",
                 "/players/hogath/area/forest/PATH/path2.c","north",});
  }
  
  items = 
      ({"trees","Gigantic trees infused by magic line the sides of this path",
        "path","This well worn dirt path has the footprints of many travelers on it",
        "dirt","Tightly packed into a path, this dirt has seen the passage of many",
        "footprints","There are dried footprints throughout the dirt path",
        "forest","A dark forest lines either side of the path",
        });
}             
  init(){
    ::init();
    add_action("search_me","search");
    add_action("cmd_smell","smell");
    add_action("cmd_listen","listen");
    }
  
  search_me(str){
    if(!str)
    {
     notify_fail("What do you want to search?\n");
     return 0;
    }
  if (str == "tree" || str == "trees" && spri == 0){
    write("The loud obnoxious searching disturbs a tree sprite's resting place.\n");
    move_object(clone_object("/players/hogath/area/mobs/forest/tsprite.c"), this_object());
    spri = 1;
    return 1;
  }
  else write("You search the "+str+" and find nothing.\n");
  return 1;
}
  cmd_smell(str){
    switch(str){
      case "trees":
      case "tree": write("A sickly sweet odor exudes from the trees.\n"); break;
      case "footprints":
      case "path": write("It smells like well....dirt.\n");break;
      case "room":
      case "forest":
      default: 
      if(!str){
        write("A cool breeze from the north carries fresh air to your lungs.\n");break;
      }
      else {
        write("The "+str+" doesn't seem to have an odor.\n");break;
      }
    }
    return 1;
}
cmd_listen(str){
  switch(str){
    case "forest": 
    if (!random(1) && spri == 0){
      write("A quiet voice mutters: \"go back.\"\n");break;
      }
    else {
      write("Whispering can be heard just beyond the trees.\n");break;
      }
    case "tree":
    case "trees":
    if (spri == 0){
      write("A strange chattering is coming from the trees.\n");break; 
    }
    else {
      write("The trees are strangely quiet.\n");break;
    }
    case "path": write("Leaves crunch underfoot.\n");break;
    case "room":
    default: 
    if(!str){
      write("The wind whistles past you.\n");break;
    }
    else {
      write("The "+str+" makes no noise.\n");break;
    }
  }
  return 1;
}
          
  
