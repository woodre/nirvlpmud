/*
 *      File:                   c1.c
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
    if (!present("thornhead")){
    move_object(clone_object("/players/hogath/area/mobs/forest/beast.c"), this_object());}
    set_light(-2);
    short_desc = HIK+"Cave Throne Room";
    long_desc = HIK+"This large throne room serves as the back end of the cave.\n"+
                    "A stone throne dominates the centeral area of the room.  \n"+
                    "Several large stalagmites ominously sit around it and seem\n"+
                    "to be sucking in all available light.\n"+NORM;
    dest_dir = ({
      "/players/hogath/area/forest/cave/c0.c","back",
      });
  }
  
  items = 
      ({
        "cave","A deep dark cavern",
        "throne","A gigantic throne carved from stone, and covered with a\n"+
                 "blanket of human flesh."+
        "stalagmite","Rock formations created by dripping water.  These\n"+
                     "seem to draw light into them",
        "stalagmites","These rocky protrusions have been enchanted to asorb light",
        });
}    
  init(){
    ::init();
    add_action("search_me","search");
    add_action("cmd_listen","listen");
    add_action("cmd_smell","smell");
    }
cmd_smell(str){
  switch(str){
    case "area":
    case "cave": write("The opressive odor of brimestone fills the "+str+".\n");break;
    case "stalagmite": 
    case "stalagmites": write("Small puffs of smoke surround the "+str+".\n");break;
    default :
    if(!str){
      write("An oppressive brimstone odor fills the room.\n");break;
    }
    else {write("The "+str+" doesn't seem to have a detectable odor.\n");break;}
    }
  return 1;
}
cmd_listen(str){
  switch(str){
    case "area":
    case "cave":
    if(present("beast")){
       write("A low growl fills the "+str+".\n");break;
     }
     else {write("The "+str+" has grown quiet.\n");break;}
    case "stalagmite": 
    case "stalagmites": write("The "+str+" give off a low hum.\n");break;
    default :
    if(!str){
      if(present("beast")){
        write("A demon beast rumbles around the room noisely.\n");break;
      }
      else {write("The cave is strangely quiet.\n");break;}
      }
    else {write("The "+str+" doesn't seem to have a detectable sound.\n");break;}
    }
  return 1;
}
  
search_me(str){
    if(!str)
    {
     write("A general search of the room shows nothing.\n");
     return 1;
    }
    else {write("You search the "+str+" to no avail.\n"); return 1;}
  }
  
