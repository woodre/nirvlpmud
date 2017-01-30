/*
 *      File:                   f0.c
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
#include "/players/hogath/tools/def.h"

inherit "room/room";  /*inherits room obj*/

reset(arg){
    if(!arg)
    {
     set_light(1);
     short_desc =HIK+"Black Forest"+NORM;  /*room short description*/
     long_desc = HIK+"The entrance to the Black Forest.  The forest though sparse\n"+
                     "here, is begining to thicken. Tall trees block any view of the \n"+
                     "sky, but light seems to still filter through.\n"+NORM;/*long description of room*/
              
dest_dir = ({
             "/players/hogath/area/forest/PATH/path3.c","east",
             "/players/hogath/area/forest/frooms/f6.c","southwest",
             });
            
    }
items = 
     ({"trees","Twisted by magic, these gigantic oaks tower over you.",
       "path","A simple dirt path it leads into the forest to the north.",
       "entrance","The path on which you came lies to the east",
       "oaks","These tree have been infused by whatever magical force"+
              "there is in the forest",
       "sky","The sky is blocked from view by the trees",
              });
}              

init()
{
    ::init();
    add_action("search_me","search"); /*adds search option to room*/
    add_action("cmd_smell","smell");
    add_action("cmd_listen","listen");
    }   

search_me(str)   /*search function*/
{
    if(!str)
    {
     notify_fail("What are you trying to search?\n");
     return 0;
    }
    write("You furiously search the "+str+" but find nothing.\n");
    return 1;
}

cmd_smell(str){
    switch(str){
      case "oaks":
      case "trees":
      case "tree": write("A sickly sweet odor exudes from the trees.\n"); break;
      case "room":
      case "forest":
      case "sky":
      default:
      if(!str){
        write("An oppressive lingering scent of decay fills the air.\n");break;
      }
      else{
         write("you don't smell anything from the "+str+".\n");break;
    }
}
    return 1;
}
cmd_listen(str){
  switch(str){
    case "sky": write("Crashing thunder can be heard overhead.\n");break;
    case "forest" :write("Save for the wind, the forest has grown quiet here.\n");break;
    case "oak":
    case "tree":
    case "trees":write("Wind rustles through the trees.\n");break;
    case "room":
    default:
    if(!str){
       write("The slight rush of the wind surrounds you.\n");break;
     }
     else {
       write("The "+str+" doesn't make a sound.\n");
     }
   }
  return 1;
}  

  
 
