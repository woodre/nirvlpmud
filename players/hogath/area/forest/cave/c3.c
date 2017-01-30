/*
 *      File:                   c3.c
 *      Function:               room
 *      Author(s):              Hogath@Nirvana
 *      Copyright:              Copyright (c) 2004 Hogath
 *                                      All Rights Reserved.
 *      Source:                 11/2004
 *      Notes:                  Cave room for my area
 *      Change History:
 */

#include <ansi.h>
#include <security.h>
#include "/players/hogath/tools/def.h"

inherit "room/room";

reset(arg) {
  if(!arg){
    if (!present("thornhead") && !random(3)){
    move_object(clone_object("/players/hogath/area/mobs/forest/thead.c"), this_object());}
    set_light(1);
    short_desc = HIK+"Alcove";
    long_desc = HIK+"A small alcove off the enterance to the cave.  It seems\n"+
                    "that it has been mostly forgotten.  Large stalagmites\n"+
                    "and stalactites fill most of the space here.\n"+NORM;
    dest_dir = ({
      "/players/hogath/area/forest/cave/c0.c","left",
      });
  }
  
  items = 
      ({
        "alcove","Cramped, this is a small room",
        "cave","A large cave sits outside the alcove",
        "stalagmite","Cone shaped rock formations protrudeing from the ground",
        "stalagmites","Several cone shaped rock formations protrude from the ground here",
        "stalactite","Icicle-shaped lime deposits hang from the cave's ceiling",
        "stalactites","Several icicle like lime deposits hang from the ceiling",
        });
}    
  init(){
    ::init();
    add_action("search_me","search");
    /*add_action("cmd_listen","listen");*/
    add_action("cmd_smell","smell");
    add_action("block_move","forward");
    }
block_move(){
  if(present("demon")){
    write("A large demon blocks your forward progress.\n");
    return 1;
  }
}
cmd_smell(str){
  switch(str){
  case "cave":
  case "alcove":
  case "area": write("Dank and dirty, a musty disused odor prevades the "+str+".\n");break;
  case "stalagmite" : write("Damp, the stalagmite has an earthy odor.\n");
  case "stalagmites": write("The Damp and dusty stalagmites have an earth odor to them.\n");break;
  case "stalactite": 
  case "stalactites": write("A slightly milky odor comes off the "+str+".\n");break;
  default :
  if (!str){
    write("A slight smell of mildew hangs on the air here.\n");break;
  }
  else {write("Your attempt to smell the "+str+" yields no satisfaction.\n");break;}
 }
  return 1;
}

cmd_listen(str){
  switch(str){
  case "cave":
  case "alcove":
  case "area": 
  if (present("demon")){
    write("A demon growls lowly in the "+str+".\n");break;
  }
  else {
    write("The empty "+str+" is quiet.\n");break;
  }
  case "stalagmite" : write("Almost silent, water drops fall on the stalagmite.\n");
  case "stalagmites": write("Water slowly drips onto the stalagmites.\n");break;
  case "stalactite": 
  case "stalactites": write("Water drips slowly from the "+str+".\n");break;
  default :
  if (!str){
    write("Water gently drips in the room.\n");break;
  }
  else {write("Your attempt to listen to the "+str+" yields no satisfaction.\n");break;}
 }
  return 1;
} 
search_me(str){
    if(!str)
    {
     write("A general search of the room leads no where.\n");
     return 1;
    }
    else {write("You search the "+str+" to no avail.\n"); return 1;}
  }
  
