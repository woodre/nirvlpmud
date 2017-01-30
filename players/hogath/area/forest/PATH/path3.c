/*
 *      File:                   path3.c
 *      Function:               
 *      Author(s):              Hogath@Nirvana
 *      Copyright:              Copyright (c) 2004 Hogath
 *                                      All Rights Reserved.
 *      Source:                 06/15/2004
 *      Notes:                  Black forest for my area
 *      Change History:
 */

#include <ansi.h>
#include <security.h>
inherit "/room/room";
#include "/players/hogath/tools/def.h"
#include "/players/hogath/area/forest/DEFS/fexits.h"

reset(arg) {
  if(!arg){
    set_light(1);
    short_desc = YEL+"Dirt Path"+NORM;
    long_desc = YEL+"Abruptly, the dirt path on which you have been traveling comes\n"+
                    "to an end.  A small hut has been constructed slightly to the \n"+
                    "north of the path's end, and the forest opens up to the west.\n"+NORM;
    
    dest_dir = ({
      "/players/hogath/area/forest/PATH/path2.c","south",});
  }
  
  items = 
      ({"hut","This hut looks abandoned and closed off",
        "path","A dirt path",
        "forest","A dark forbodeing forest lies to the west",
        "end","The dirt path ceases to be here",
        });
 }   
  init(){
    ::init();
    add_action("search_me","search");
    add_action("enter_it","enter");
    add_action("cmd_smell","smell");
    add_action("cmd_listen","listen");
    }
  
search_me(str){
    if(!str)
    {
     notify_fail("What do you want to search?\n");
     return 0;
    }
  switch(str){
    case "path":
    case "end": write("Several footprints enter the forest here.\n");break;
    case "forest": write("You'll have to enter the forest to actually search it.\n");break;
    case "hut": write("You search the outside of the hut and find nothing special.\n");break;
    default :write("You search the "+str+" and find nothing.\n");break;
  }
  return 1;
}
cmd_smell(str){
    switch(str){
      case "trees":
      case "tree": write("A sickly sweet odor exudes from the trees.\n"); break;
      case "path": write("It smells like well....dirt.\n");break;
      case "room":
      case "forest":
      default:
      if(!str){
        write("A cool breeze from the north carries fresh air to your lungs.\n");break;
      }
      else{
         write("you don't smell anything from the "+str+".\n");break;
    }
}
    return 1;
}
cmd_listen(str){
  switch(str){
    case "forest" :write("The forest has grown quiet here.\n");break;
    case "tree":
    case "trees":write("The trees sway peacefully in the wind.\n");break;
    case "path": write("Leaves crunch underfoot.\n");break;
    case "hut": write("Shingles on the hut's roof rattle.\n");break;
    case "room":
    default:
    if(!str){
       write("The wind whistles past you.\n");break;
     }
     else {
       write("The "+str+" doesn't make a sound.\n");
     }
   }
  return 1;
}  
enter_it(str){
  if (!str)
  {
    write("Enter what???\n");
    return 1;
    }
  if (str == "forest")
  {write(BOLD+"You boldly enter the black forest.\n");
  move_object(this_player(),"/players/hogath/area/forest/frooms/f0.c");
  command("look", this_player());
  return 1;
  }
  if (str == "hut")
  {write("You enter the hut\n");
  move_object(this_player(),"/players/hogath/area/forest/PATH/hut.c");
  command("look", this_player());
  return 1;
  }
 }
 
