/*
 *      File:                   f4.c
 *      Function:               
 *      Author(s):              Hogath@Nirvana
 *      Copyright:              Copyright (c) 2004 Hogath
 *                                      All Rights Reserved.
 *      Source:                 10/2004
 *      Notes:                  Black forest for my area
 *      Change History:
 */

#include <ansi.h>
#include <security.h>
#include "/players/hogath/tools/def.h"

inherit "room/room";

reset(arg) {
  if(!arg){
    set_light(-1);
    short_desc = HIK+"Black Forest"+NORM;
    long_desc = HIK+"Thick fog obscures the view of the forest here adding\n"+
                    "a mysterious quality to the surrounding wood.  Dead and\n"+
                    "branches and leaves clutter the ground here.\n"+NORM;
    dest_dir = ({
      "/players/hogath/area/forest/frooms/f8.c","north",
      "/players/hogath/area/forest/frooms/f12.c","east",
      });
  }
  
  items = 
      ({
        "fog","The fog has a peasoup like consistency",
        "forest","Ancient trees make up this dark forest",
        "wood","Ancient trees make up this dark forest",
        "branches","Dead branches have fallen here",
        "leaves","dead leaves clutter the forest floor",
        "ground","It is covered with dead branches and leaves",
        });
}    
  init(){
    ::init();
    add_action("search_me","search");
    add_action("cmd_listen","listen");
    add_action("cmd_smell","smell");
    }
cmd_listen(str){
  switch(str){
    case "fog": write("Silence...\n");break;
    case "forest":
    case "wood": write("Animals scream in the "+str+".\n");break;
    case "branches":
    case "leaves": write("The "+str+" crunch underfoot.\n");break;
    case "ground": write("Leaves and branches crack.\n");break;  
    default:
    if (!str){
      write("Wind stirs through the room.\n");break;
    }
    else {write("You can hear nothing from "+str+".\n");break;}
  }
return 1;
}
cmd_smell(str){
  switch(str){
    case "fog": write("Odorless...\n");break;
    case "forest":
    case "wood": write("A strong earthy scent rises from the "+str+".\n");break;
    case "branches":
    case "leaves": write("The "+str+" smell of decay.\n");break;
    case "ground": write("Dirt and decay.....\n");break;  
    default:
    if (!str){
      write("A strong odor of decay lingers here.\n");break;
    }
    else {write("You can smell nothing from "+str+".\n");break;}
  }
  return 1;
}
search_me(str){
    if(!str)
    {
     notify_fail("What do you want to search?\n");
     return 0;
    }
  write("You search the "+str+" and find nothing.\n");
  return 1;
}
    
