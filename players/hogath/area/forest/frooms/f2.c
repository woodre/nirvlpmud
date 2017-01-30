/*
 *      File:                   ft2.c
 *      Function:               room.c
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
    short_desc = HIK+"Black forest"+NORM;
    long_desc = HIK+"Trees grow untamed and seem to reach out in an attempt to\n"+
                    "crush those who wander the forest.  A thick fog hangs heavy\n"+
                    "in the air here, blocking out the light from above.\n"+NORM;
                    /*"A small path leads north out of the forest.\n"+NORM;*/
    dest_dir = ({
             "/players/hogath/area/forest/frooms/f1.c","west",
             "/players/hogath/area/forest/frooms/f5.c","south",
             });
  }

  
  items = 
      ({"trees","Gnarled, ancient trees have grown unchecked in this portion of the forest",
        "floor","The forest floor is obscured by fog",
        "fog","A heavy thick pea-soup fog drifts around",
        "forest","The forest seems to be dying",
        /*"path","A small path leads north out of the forest, perhaps you could walk on it",*/});
}    
  init(){
    ::init();
    add_action("search_me","search");
    add_action("cmd_smell","smell");
    add_action("cmd_listen","listen");
    add_action("move_north","walk");}
move_north(str){
  if(str == "north"  || str == "path")
  {  write("A large fallen tree blocks the path.\n"); return 1;}
  else {write("Walk where?\n");return 1;}
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
    
cmd_smell(str){
    switch(str){
      case "fog": write("The fog bears the scent of decay.\n");break;
      case "trees":
      case "tree": write("A sickly sweet odor exudes from the trees.\n"); break;
      case "forest": 
      case "room":
      default:
      if(!str){
        write("An oppressive scent of decay fills the air.\n");break;
      }
      else{
         write("you don't smell anything from the "+str+".\n");break;
    }
}
    return 1;
}
cmd_listen(str){
  switch(str){
    case "fog": write("Silence.....\n");break;
    case "forest" :write("Branches sway in the wind.\n");break;
    case "tree":
    case "trees":write("Wind rustles through the trees.\n");break;
    case "room":
    default:
    if(!str){
       write("Aside from the whistling of the wind, the area around here is silent.\n");break;
     }
     else {
       write("The "+str+" doesn't make a sound.\n");
     }
   }
  return 1;
}  
