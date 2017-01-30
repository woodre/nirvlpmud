/*
 *      File:                   f6.c
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
    long_desc = HIK+"Tree branches to form a tightly packed canopy blocking\n"+
                    "out the light from above.  The trees themselves have been\n"+
                    "twisted by the magic surrounding the forest.\n"+NORM;
    dest_dir = ({
      "/players/hogath/area/forest/frooms/f3.c","north",
      "/players/hogath/area/forest/frooms/f5.c","west",
      "/players/hogath/area/forest/frooms/f9.c","south",
      "/players/hogath/area/forest/frooms/f0.c","back",});
  }
  
  items = 
      ({
        "forest","A dark enchanted forest surrounds you",
        "trees","Trees twisted by magic",
        "canopy","A dense growth of tree branches blocks any view of the sky",
        "branches","Tree branches form a dense canopy over you",
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
    case "tree":
    case "trees": write("The lingering scent of dried sap surrounds the "+str+".\n");break;
    case "branches":
    case "canopy": write("It is too high for you to smell it.\n");break;
    case "forest" :write("The dank musty air is overpowering.\n");break;
    case "room": write("The air here is dank and musky.\n");break;
    default:
    if(!str){
      write("Whirling winds bring the smell of crushed rock to this room.\n");break;
    }
    else {write("The "+str+" doesn't give off an odor.\n");break;}
  }
  return 1;
}
cmd_listen(str){
  switch(str){
    case "tree":
    case "trees": write("Wind whistles noisely through the trees.\n");break;
    case "branches":
    case "canopy": write("The branches rustle in the wind.\n");break;
    case "forest": write("Leaves rustle as the wind whips through them.\n");break;
    case "clearing": write("The clearing is too far away for you to hear anything from it.\n");break;
    case "room": write("Winds whip around the room.\n");break;
    case "south":
    case "east": write("You'll have to go "+str+" to listen to that.\n");break;
    default:
    if (!str){
      write("Wind swirls noisely around the area.\n");break;
    }
    else {write("The "+str+" makes no noise.\n");break;}
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
    
