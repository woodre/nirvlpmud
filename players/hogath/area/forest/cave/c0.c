/*
 *      File:                   c0.c
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
    move_object(clone_object("/players/hogath/area/mobs/forest/thead.c"), this_object());}
    set_light(1);
    short_desc = HIK+"Cave"+NORM;
    long_desc = HIK+"Bleak and oppressive, this cave appears to be home to\n"+
                    "several demonic creatures.  A palpable sense of evil \n"+
                    "pervades the atmosphere here causeing  a deep feeling\n"+
                    "of dread and dismay.  The walls of the cave give off \n"+
                    "soft glow illuminating the cave.\n"+NORM;
    dest_dir = ({
      "/players/hogath/area/forest/frooms/f3.c","out",
      "/players/hogath/area/forest/cave/c1.c","forward",
      "/players/hogath/area/forest/cave/c2.c","left",
      "/players/hogath/area/forest/cave/c3.c","right",
      });
  }
  
  items = 
      ({
        "cave","A deep dark cavern",
        });
}    
  init(){
    ::init();
    add_action("search_me","search");
    /*add_action("cmd_listen","listen");*/
    add_action("cmd_smell","smell");
    add_action("block_move","forward");
    add_action("block_move","left");
    add_action("block_move","right");
    }
block_move(){
  if(present("demon")){
    write("A large demon blocks you.\n");
    return 1;
  }
}
cmd_smell(str){
  switch(str){
  case "cave": write("A dank dirty odor pervades the cave.\n");break;
  case "air" : write("You breathe deeply of the evil presence in the area.\n");break;
  }
  return 1;
}

/*cmd_listen(str){
  switch(str){
  }
}*/
  
search_me(str){
    if(!str)
    {
     write("A general search of the room shows footprints leading deeper into the cave.\n");
     return 1;
    }
    else {write("You search the "+str+" to no avail.\n"); return 1;}
  }
  
