/*
 *      File:                   f12.c
 *      Function:               room
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
int peeps;
reset(arg) {
  if(!arg){
    if (!present("elemental")){
      move_object(clone_object("/players/hogath/area/mobs/forest/elemental/wele"),this_object());
       }
      set_light(1);
    short_desc = BOLD+"A Clearing"+NORM;
    long_desc = BOLD+"The forest has opened into a small clearing here in this\n"+
                     "corner.  Strangely calm and peaceful, an old stone fountain\n"+
                     "seems to have been abandoned here.\n"+NORM;
    dest_dir = ({
      "/players/hogath/area/forest/frooms/f9.c","north",
      "/players/hogath/area/forest/frooms/f11.c","west",
      });
}
  
  items = 
      ({
        "forest","The forest surrounds this calm clearing",
        "clearing","Tall grass has sprung up in this open area",
        "fountain","Cool water gently bubbles in this ancient fountain.\n",
        "center","Someone, or something, has placed a fountain here",
        "grass","Vibrant green grass grows here",
        "water","Figures seem to move just under the water.",
        });
    }
  init(){
    ::init();
    add_action("search_me","search");
    add_action("wade_fountain","wade");
    add_action("cmd_smell","smell");
    add_action("cmd_listen","listen");
   }
cmd_smell(str){
  switch (str){
    case "forest": write("Oak sap rises off the forest.\n");break;
    case "grass": write("The grass has a mildy sweet odor to it.\n");break;
    case "fountain":
    case "water": write(str+" has an air of ozone to it.\n");break;
    case "center": write("A strong ozone odor surrounds the center of the clearing.\n");break;
    case "clearing":
    case "room": write("This clearing has a clean crisp odor.\n");break;
    default:
    if (!str){
      write("Clean and crisp, the air is surpriseingly fresh here.\n");break;
    }
    else {write("An odor can't be detected from "+str+".\n");break;}
  }
  return 1;
}

cmd_listen(str){
  switch(str){
    case "forest": write("The moans through the forest just beyond the clearing.\n");break;
    case "grass": write("Wind blows through the grass.\n");break;
    case "fountain":write("A gentle rushing of water.\n");break;
    case "water": write("Water bubbles.\n");break;
    case "clearing":
    case "room":
    case "center": write("Air swirls loudly around the clearing.\n");break;
    default :
    if (!str){
      write("Strangely, birds can be heard singing in this clearing.\n");break;
    }
    else {write("Nothing can be heard from the "+str+".\n");break;}
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
    

wade_fountain(str){
  if(!str){
    write("What are you wadeing into?\n");
    return 1;
  }
  if (str == "fountain"){
    write("The waters reject you.\n");
    return 1;}
    else {write("You can't wade into the "+str+".\n");return 1;}
  }
