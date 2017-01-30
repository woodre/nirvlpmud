/*
 *      File:                   c2.c
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
    move_object(clone_object("/players/hogath/area/mobs/forest/thead.c"), this_object());
    }
    set_light(1);
    short_desc = HIK+"Demon cave";
    long_desc = HIK+"Bleak and oppressive, this part of the cave serves as\n"+
                    "a sleeping area.  There are several stone beds and straw \n"+
                    "straw pallets throughout the room.  Phosphorhous rocks\n"+
                    "glow in the ceiling adding a gloomy glow to the room.\n"+NORM;
    dest_dir = ({
      "/players/hogath/area/forest/cave/c0.c","right",
      });
  }
  
  items = 
      ({
        "cave","A deep dark cavern",
        "area","This part of the cave serves as a sleeping area",
        "beds","Hard, and cold these serve the demons' sleeping needs",
        "pallets","Arranged neatly, these might be good for sleeping on",
        "rocks","Glowing rocks have been placed into the ceiling",
        "ceiling","Rocks and crags mark the cave's ceiling",});
}    
  init(){
    ::init();
    add_action("search_me","search");
    add_action("cmd_listen","listen");
    add_action("cmd_smell","smell");
    add_action("block_move","right");
    }
block_move(){
  if(present("demon")){
    write("A large demon blocks your forward progress.\n");
    return 1;
  }
}
cmd_smell(str){
  switch(str){
  case "area":
  case "cave": write("A stale odor rests heavily in the "+str+".\n");break;
  case "beds": write("Dirty and unclean, the beds smell of unwashed bodies.\n");break;
  case "pallets": write("A damp musky odor rises off of the pallets.\n");break;
  case "rocks" : write("They have a salty phosporhic scent to them.\n");break;
  case "ceiling": write("It's too high for any dectetable odor.\n");break;
  default :
  if(!str){
    write("A blanket of demonic body odor permeates the room.\n");break;
  }
  else {
    write("You attempt to smell the "+str+" but find you can't.\n");break;
  }
  }
  return 1;
}

cmd_listen(str){
  switch(str){
  case "area":
  case "cave": 
    if(present("demon")){
    write("A low growl resounds in the "+str+".\n");break;
    }
    else {write("There is an errie silence in the "+str+".\n");break;}
  case "beds": write("The stone bed cracks as your hands run across it.\n");break;
  case "pallets": write("The straw pallet rustle noisely.\n");break;
  case "rocks" : write("A low magic hum can be heard in the rocks.\n");break;
  case "ceiling": write("A low hum comes off the ceiling.\n");break;
  default :
  if(!str){
    write("Listening careful you hear a low hum.\n");break;
  }
  else {
    write("You listen to the "+str+" but find it is silent.\n");break;
  }
  }
  return 1;
}

  
search_me(str){
    if(!str)
    {
     write("A general search turns up nothing.\n");
     return 1;
    }
    else {write("You search the "+str+" to no avail.\n"); return 1;}
  }
  
