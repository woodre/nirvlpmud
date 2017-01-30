/*
 *      File:                   f9.c
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
    long_desc = HIK+"Large oak trees close up and prevent further access to\n"+
                    "the more western portions of the forest.  A canopy of tree\n"+
                    "branches shades and darkens this area.\n"+NORM;
    dest_dir = ({
      "/players/hogath/area/forest/frooms/f5.c","north",
      "/players/hogath/area/forest/frooms/f8.c","west",
      "/players/hogath/area/forest/frooms/f12.c","south",
      "/players/hogath/area/forest/frooms/f10.c","east",
      });
  }
  
  items = 
      ({
        "trees","Tall trees that have been here for generations",
        "oak","Tall oaks, as yet unaffected by the magic of the forest",
        "branches","Tree branches form a canopy blocking out the light",
        "canopy","A dense gathering of branches",
        "oak trees","Tall oaks, as yet unaffected by the magic of the forest",
        "clearing","A small clearing lies to the south",
        "north","More trees!\n",
        "east","DOH! even more trees!\n",
        "south","The forest opens to a clearing to the south",
        });
}     
  init(){
    ::init();
    add_action("search_me","search");
    add_action("cmd_smell","smell");
    add_action("cmd_listen","listen");
    }
cmd_smell(str){
  switch(str){
    case "oak":
    case "oak trees":
    case "trees":
    case "tree": write("The "+str+"smells strongly of wood sap.\n");break;
    case "branches": write("The "+str+" are too high to carry an odor.\n");break;
    case "canopy": write("The "+str+" is too high to carry an odor.\n");break;
    case "north":
    case "east":
    case "south": ("You'll have to go "+str+" to see what it smells like there.\n");break;
    default :
    if(!str){
      write("A deep woody odor surrounds the area.\n");break;
    }
    else {write("You can't pick up a scent for the "+str+".\n");break;}
  }
}
cmd_listen(str){
  switch(str){
    case "oak":
    case "oak trees":
    case "trees":
    case "tree": write("The "+str+" sway in the wind.\n");break;
    case "branches": write("The "+str+" rustle.\n");break;
    case "canopy": write("The "+str+" creaks and rustles.\n");break;
    case "north":
    case "east":
    case "south": ("You'll have to go "+str+" to hear that.\n");break;
    default :
    if(!str){
      write("Wind moves about the area.\n");break;
    }
    else {write("You can't pick up a scent for the "+str+".\n");break;}
  }
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
    
 
