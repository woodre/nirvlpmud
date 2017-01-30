/*
 *      File:                   path0.c
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
     short_desc =BOLD+"Forest Entrance"+NORM;  /*room short description*/
     long_desc = BOLD+"This is the southern entrance to the Black Forest.  A dirt\n"+
                      "path, lined by tall trees runs into and through the forest.\n"+
                      "Surrounded thickly on both sides by tall trees casting deep\n"+
                      "furious shadows on the it.\n"+NORM;/*long description of room*/
              
dest_dir = ({"/players/hogath/area/entrance1.c","south",
             "/players/hogath/area/forest/PATH/path1.c","north",
              });
            
    }
items = 
     ({"trees","Unnatural, magically twisted trees line both sides of the path",
       "path","A simple dirt path it leads into the forest to the north",
       "entrance","This is the entrance to the vast Black Forest",
       "tree","This tree has been twisted into something unnatural",
       "shadows","The trees cast dark shadows across the path",
       "forest","The forest is dark and thick",
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
cmd_smell(str){/*smell function*/
  switch(str){
    case "trees":
    case "tree": write("The trees give off a sickly sweet odor.\n");break;
    case "path" : write("The path smells like....dirt.\n");break;
    case "shadows": write("You try to smell the shadows, then realize you CAN'T!\n");break;
    case "entrance":
    case "room":
    case "forest":
    default :
    if(!str){
      write("The forest around here gives off a noxious odor.\n"); break;
      }
      else {
        write("The "+str+" gives off no odor.\n");break;
      }
    }
  return 1;
}
cmd_listen(str){/*listen function*/
  switch(str){
    case "forest": write("The wind carries soft screams of terror on it.\n");break;
    case "trees":
    case "tree":write("The wind rustles through the trees.\n"); break;
    case "shadows": write("The shadows seem to cry out in pain.\n");break;
    case "path": write("Leaves crunch on the path as it is trode upon.\n");break;
    case "room": 
    default :
    if(!str){
       write("The wind blows silently along the path.\n");break;
      }
      else {
        write("The "+str+" doesn't make a sound.\n");break;
      }
    }
  return 1;
}

