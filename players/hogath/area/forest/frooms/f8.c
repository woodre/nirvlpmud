/*
 *      File:                   f8.c
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
    long_desc = HIK+"Darkness surrounds you as the trees upper branches form\n"+
                    "a canopy to block out the sun.  A slight breeze seems to\n"+
                    "blow from the north in an otherwise dull environment.\n"+NORM;
    dest_dir = ({
      "/players/hogath/area/forest/frooms/f7.c","west",
      "/players/hogath/area/forest/frooms/f9.c","east",
      "/players/hogath/area/forest/frooms/f11.c","south",
      "/players/hogath/area/forest/frooms/f4.c","north",
    });
  }
  
  items = 
      ({
        "darkness","It's dark, get over it",
        "trees","The trees here seem to fight the magic that twists them",
        "canopy","A dense canopy of branches and foliage block out the light",
        "north","Glancing into the distance, you believe you see a portal to the north",
        "environment","It is rather dull here, isn't it?",
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
    case "darkness":write("Silence....\n");break;
    case "tree":
    case "trees": write("They sway slightly in the wind.\n");break;
    case "canopy": write("The canopy's branches rustle noisely.\n");break;
    case "north": write("Thunderous wind resounds to the north.\n");break;
    case "environment":
    case "room":
    case "forest": write("A slight rushing of wind animates the area.\n");break;
    default:
    if (!str){
      write("A cooling breeze blows through here.\n");break;
    }
    else {write("The "+str+" seems to not make a noise.\n");break;}
  }
  return 1;
}
cmd_smell(str){
  switch(str){
    case "darkness": write("UM, OK, YOU CAN't SMELL THAT.\n");
    case "trees":
    case "tree": write("The "+str+"smells strongly of wood sap.\n");break;
    case "canopy": write("The "+str+" is too high to give off an odor here.\n");
    case "north": write("A fresh breeze blows from the north.\n");break;
    case "environment":
    case "room":
    case "forest": write("The forest smell of wood say and oakum.\n");break;
    default:
    if(!str){
      write("A musky scent pervades the area.\n");break;
    }
    else {write("The "+str+" can't be smelled.\n");break;}
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
    
  
