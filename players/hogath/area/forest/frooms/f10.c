/*
 *      File:                   f10.c
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
    long_desc = HIK+"The rampant growth of the forest prevents travel\n"+
                    "south and east.  A large hole has been tunneled \n"+
                    "into a hill here.\n"+NORM;
    dest_dir = ({
                 "/players/hogath/area/forest/frooms/f6.c","north",
                 "/players/hogath/area/forest/frooms/f9.c","west",
                 });
  }
  
  items = 
      ({
        "growth","Brambles and bushes have formed a wall blocking further exploration",
        "south","Travel is prohibited in that direction by the forest growth",
        "east","Travel is prohibited in that direction by the forest growth",
        "hole","A gaping hole sits mournfully in the hill side",
        "hill","Gentle in it's slope, this hill looks to have been here for ages",
        "forest","A dark dreary forest full of black trees",
        "trees","These trees have been twisted",
        });
}    
  init(){
    ::init();
    add_action("search_me","search");
    add_action("cmd_listen","listen");
    add_action("cmd_smell","smell");
    add_action("enter_hole","fall");
    }
cmd_listen(str){
  switch(str){
    case "growth": write("Wind rustles through the brambles and bushes.\n");break;
    case "south": 
    case "east":write("You try to listen "+str+" but hear nothing.\n");break;
    case "hole": write("Stone crashes in the distance.\n");break;
    case "hill": write("Chirp...Chirp.\n");break;
    case "trees": write("The branches of the trees rustle in the wind.\n");break;
    case "room":
    case "forest": write("Wind whistles through the forest.\n");break;
    default:
    if (!str){
      write("A low rumble comes from within the cave.\n");break;
    }
    else {write("The "+str+" doesn't seem to make any noise.\n");}
  }
  return 1;
}
cmd_smell(str){
  switch(str){
    case "growth": write("It smells of holly and mistletoe.\n");break;
    case "south": 
    case "east":write("You breathe in deeply but still can't smell "+str+".\n");break;
    case "hole": write("A strange odor of crushed stone and earth eminates from it.\n");break;
    case "hill": write("It smells like dirt and grass, what else can you expect.\n");break;
    case "trees": write("Wood sap comes off the tree.\n");break;
    case "room":
    case "forest": write("The odors of the forest surround you.\n");break;
    default:
    if (!str){
      write("An earthy scent fills the air here.\n");break;
    }
    else {write("The "+str+" doesn't seem to have an odor.\n");}
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
    
enter_hole(str){
  if (str != "hole"){
    write("Enter what?\n");
    return 1;
  }
  else {write("It's not done yet fool.\n");return 1;}
}
 
