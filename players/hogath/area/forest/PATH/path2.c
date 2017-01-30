/*
 *      File:                   path2.c
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

inherit "room/room";
int searched;
reset(arg) {
  searched = 0;
  if(!arg){
    set_light(1);
    short_desc = YEL+"Dirt Path"+NORM;
    long_desc = YEL+"Large trees to the east and west bunch up blocking progression\n"+
                    "into the forest depths here.  A large slightly bubbling puddle\n"+
                    "of mud has been formed by continuing rains in the path's center.\n"+NORM;
    /*exits!*/                  
    dest_dir = ({"/players/hogath/area/forest/PATH/path1.c","south",
                 "/players/hogath/area/forest/PATH/path3.c","north",
                 });
  }
  
  items = 
      ({"trees","Gigantic trees infused by magic line the sides of the path",
        "path","This well worn dirt path has the footprints of many travelers on it",
        "puddle","It looks as though water has settled into a low grade portion of the path",
        "forest","A dark forbodeing forest surrounds this path",
        "mud","The mud seems to bubble and ooze in this puddle",
        });
}     
  init(){
    ::init();
    add_action("search_me","search");
    add_action("cmd_smell","smell");
    add_action("cmd_listen","listen");
    }
  
  search_me(str){
    if(!str)
    {
     notify_fail("What do you want to search?\n");
     return 0;
    }
  
  if (str == "puddle" || str == "mud")
  {
    if (searched == 0)
    {
      write(YEL+"The searching disturbs something.\n"+NORM);
      write(YEL+"An earth elemental rises from the mud.\n"+NORM);
      move_object(clone_object("/players/hogath/area/mobs/forest/elemental/eele.c"), this_object());
      searched = 1;
      return 1;
    }
    else write(YEL+"You search the muddy puddle but it is empty.\n"+NORM);
    return 1;
    }
write("You search the "+str+" and find nothing.\n");
  return 1;
}
    
  cmd_smell(str){
    switch(str){
      case "trees":
      case "tree": write("A sickly sweet odor exudes from the trees.\n"); break;
      case "path": write("It smells like well....dirt.\n");break;
      case "puddle":
      case "mud": write("A noxious odor oozes from the "+str+".\n");break;
      case "room":
      case "forest":
      default:
      if(!str){
        write("A cool breeze from the north carries fresh air to your lungs.\n");break;
      }
      else{
         write("you don't smell anything from the "+str+".\n");break;
    }
    return 1;
  }
}

cmd_listen(str){
  switch(str){
    case "forest" :write("Screams echo beyond the trees.\n");break;
    case "tree":
    case "trees":write("The moan in the wind.\n");break;
    case "mud":
    case "puddle":write("The "+str+" bubbles strangely.\n");break;
    case "path": write("Leaves crunch underfoot.\n");break;
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
