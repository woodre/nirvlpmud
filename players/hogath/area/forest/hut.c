/*
 *      File:                   hut.c
 *      Function:               room
 *      Author(s):              Hogath@Nirvana
 *      Copyright:              Copyright (c) 2004 Hogath
 *                                      All Rights Reserved.
 *      Source:                 11/2004
 *      Notes:                  hut for my area
 *      Change History:
 */

#include <ansi.h>
#include <security.h>
#include "/players/hogath/tools/def.h"

inherit "room/room";

reset(arg) {
  if(!arg){
    if (!present("jahira")){
    move_object(clone_object("/players/hogath/area/mobs/forest/druid.c"), this_object());}
    set_light(1);
    short_desc = HIY+"Hut";
    long_desc = HIY+"A small hut, it's thatched walls are surprisingly sturdy\n"+
                    "The interior is quite neat and although it's interior is\n"+
                    "simple and sparse, it feels as though a person of great\n"+
                    "power resides here.\n"+NORM;
    dest_dir = ({
      "/players/hogath/area/forest/path3.c","out",
      });
  }
  
  items = 
      ({
        "walls","sturdy wooden walls thatched with straw for insulation",
        "interior","Simple surrounding for a simple life",
        "ceiling","A causal glance shows a simply straw and stick cieling",
        });
}    
  init(){
    ::init();
    add_action("search_me","search");
    /*add_action("cmd_listen","listen");*/
    add_action("cmd_smell","smell");
    
    }

cmd_smell(str){
  switch(str){
  case "ceiling": write("It is out of your reach.\n");
  case "hut": write("It smells as though someone has been burning spices.\n");break;
  case "walls" : write("Dried hay causes you to sneeze.\n");
                 tell_room(this_player(), tpn+" sneezes!\n");break;
  case "interior" : write("A combination of incense and the earthy aroma of nature provide a pleasent sensation.\n");break;
  default :
  if(!str){
    write("The pleasing aroma of nature wafts through the air.\n");
    break;
    }
    else {
      write("You try to smell the "+str+" and fail.\n");
      break;
    }
    }
  return 1;
}

cmd_listen(str){
  switch(str){
  case "hut": write("Bird twitter in the huts ceiling.\n");break;
  case "ceiling": write("TWEET...\n");break;
  case "walls" : write("Wind causes the thatched walls to sway.\n");break;
  case "interior":
  if(present("jahira")){
    write(BOLD+"Jahira"+NORM+" hums softly.\n");
    break;
  }
    else {write("No one is home.\n");break;}
  default:
  if(!str){
    write("The gentle sounds of nature caress your ears.\n");break;
  }
  else{
     write("You try to listen to the "+str+" and fail.\n");
     break;
     }
   }
   return 1;
 }
 
search_me(str){
    if(!str)
    {
     write("Search what?\n");
     return 1;
    }
    else {write("You search the "+str+" to no avail.\n"); return 1;}
  }
  
