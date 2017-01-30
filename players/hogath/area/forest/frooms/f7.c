/*
 *      File:                   f7.c
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
    long_desc = HIK+"Dark shadows cast a frightening image as the forest seems\n"+
                    "to move in here.  A chilling sense of dread pervades the\n"+
                    "atmosphere as dark forms flit in and out of the shadows.\n"+NORM;
    dest_dir = ({
      "/players/hogath/area/forest/frooms/f3.c","north",
      "/players/hogath/area/forest/frooms/f8.c","east",
      });
  }
  
  items = 
      ({
        "forest","Dark trees populate this part of the forest",
        "forms","Dark shapes seem to move quickly about the room",
        "shadows","The trees of the forest cast long shadows",
        "image","The shadows cast a demonic image",
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
    case "forest": write("Dirt and decay rise off the forest.\n");break;
    case "tree":
    case "trees": write("The scent of death and decay rises from the "+str+".\n");break;
    case "forms":write("Nothing...\n");break;
    default :
    if (!str){
      write(".\n");break;
    }
    else {write("The "+str+" doesn't give off an odor.\n");break;}
  }
  return 1;
}

cmd_listen(str){
  switch(str){
    case "forest":write("The screams for blood.\n");break;
    case "forms":write("Silence...\n");break;
    case "trees":
    case "tree":write("Wind rustles through the "+str+" branches.\n");break;
    case "room":
    default:
    if(!str){
      write("Angry voices are carried on the wind.\n");break;
    }
    else {write("The "+str+" doesn't make a sound.\n");break;}
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
    
  
