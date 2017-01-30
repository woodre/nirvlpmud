/*
 *      File:                   f4.c
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
      move_object(clone_object("/players/hogath/area/mobs/forest/elemental/fele"),this_object());
       }
    set_light(1);
    short_desc = HIK+"Black Forest"+NORM;
    long_desc = HIK+"The ground and trees here are charred and black.  Thick\n"+
                    "ash ridden smog chokes the air around a flaming portal\n"+
                    "blocking any view of the sky or the sun above.\n"+NORM;
  dest_dir = ({
             "/players/hogath/area/forest/frooms/f3.c","west",
             "/players/hogath/area/forest/frooms/f8.c","south",
             "/players/hogath/area/forest/frooms/f1.c","north",
             "/players/hogath/area/forest/frooms/f5.c","east",
              });   
  }
  
  items = 
      ({
        "clearing","A small circular clearing has formed around the portal",
        "fog","Smokey fog drifts around",
        "portal","You see flaming figures just beyond the portal entrance",
        "forest","The forest is dead and dying",
        "sky","The fog has made the sky grey and hazy here",
        "sun","A grey hazy form peeks through the haze here",
        "ground","The forest floor is charred and blackend here",
        "trees","Charred and blackend husks of once powerful oaks",
        });
 }   
  init(){
    ::init();
    add_action("search_me","search");
    add_action("cmd_listen","listen");
    add_action("cmd_smell","smell");
    add_action("enter_me","enter");
    }
cmd_smell(str){
    switch(str){
      case "portal": write("Brimstone from the portal is overwhelming.\n");break;
      case "fog": write("The smokey scent of brimstone chokes you.\n");break;
      case "trees":
      case "tree": write("They smell crispy.\n"); break;
      case "forest": write("A tar like smell comes off the forest.\n");break;
      case "ground": write("Burnt and incinerated ash rises off the forest floor.\n");break;
      case "sun": write("DOH! How you gonna smell that!\n");break;
      case "sky":
      case "room":
      case "clearing":
      default:
      if(!str){
        write("Brimstone and ash choke the air around you.\n");break;
      }
      else{
         write("you don't smell anything from the "+str+".\n");break;
    }
}
    return 1;
}
cmd_listen(str){
  switch(str){
    case "portal": write("Energy crackles across the portal.\n");break;
    case "sun": write("DOH! How you gonna listen to that!\n");break;
    case "fog": write("Silence.\n");break;
    case "forest" :write("The forest groans.\n");break;
    case "tree":
    case "trees":write("Wind whistles through the dead and dying trees.\n");break;
    case "room":
    case "clearing":
    case "sky":
    default:
    if(!str){
       write("The portal crackles loudly.\n");break;
     }
     else {
       write("The "+str+" doesn't make a sound.\n");
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
    
enter_me(str){
  if (!str) {write("Enter what?!?\n");return 1;}
  if (str == "portal"){
    write(HIR+"The portal rejects you.\n"+NORM);
    return 1;
  }
  else {write("The "+str+" cannot be entered.\n");return 1;}
}
