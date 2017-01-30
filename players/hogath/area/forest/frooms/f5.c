/*
 *      File:                   f5.c
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
    if (!present("elemental")){
      move_object(clone_object("/players/hogath/area/mobs/forest/elemental/aele"),this_object());
       }set_light(-1);
    short_desc = HIK+"Black Forest"+NORM;
    long_desc = HIK+"Twisted trees populate the forest here, their branches\n"+
                    "create a canopy blocking out the light.  Strong wind swirls\n"+
                    "about room with some sort of doorway shimmering in the vortex\n"+
                    "of the wind.\n"+NORM;
    dest_dir = ({
      "/players/hogath/area/forest/frooms/f4.c","west",
      "/players/hogath/area/forest/frooms/f2.c","north",
      "/players/hogath/area/forest/frooms/f6.c","east",
      "/players/hogath/area/forest/frooms/f9.c","south",
      });
  }
  
  items = 
      ({
        "trees","The trees here have been twisted by magic",
        "forest","It is hard to see the forest for the trees",
        "canopy","Tree branches have grown together to block out the light",
        "vortex","A vortex of wind swirls about the room",
        "wind","Strangly the wind can be seen in this room",
        "doorway","A vortex which seems to be spewing out wind",
        "portal","Wind streams from this portal",
        "branches","Tree branches have intertwined to form a canopy here",
        });
    }
  init(){
    ::init();
    add_action("search_me","search");
    add_action("cmd_smell","smell");
    add_action("cmd_listen","listen");
    add_action("enter_vortex","enter");
    }
enter_vortex(str){
  if (!str){
    write("Enter what?\n");
    return 1;
  }
  if (str == "portal" || str == "doorway" || str == "vortex"){
    write("Strong winds from the "+str+" prohibit entrance.\n");
    return 1;
  }
}

cmd_smell(str){
  switch (str){
    case "portal":
    case "doorway":
    case "vortex": write("Fresh air streams from the portal.\n");
    case "tree":
    case "trees": write("Wood and sap dominate the air around the trees.\n");break;
    case "branches":
    case "canopy": write("It is too far away for you to pick up an odor.\n");break;
    case "room":
    case "forest":
    default :
    if(!str){
       write("A subtle scent of oak sap lingers in this room.\n");break;
    }
    else {
      write("You can't smell anything from the "+str+".\n");break;
    }
  }
  return 1;
}

cmd_listen(str){
  switch(str){
    case "tree":
    case "trees": write("Wind rustles through the trees.\n");break;
    case "fog": write("Silence...\n");break;
    case "branches":write("Strong winds blow through the branches.\n");break;
    case "canopy": write("Birds twitter in the canopy.\n");break;
    case "room":
    case "forest":
    default :
    if (!str){
      write("Thunderous winds swirl around the room.\n");break;
    }
    else {
      write("Not a sound can be heard from the "+str+".\n");break;
    }
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
       
 
