/*
 *      File:                   mounddr.c
 *      Function:               
 *      Author(s):              Hogath@Nirvana
 *      Copyright:              Copyright (c) 2004 Hogath
 *                                      All Rights Reserved.
 *      Source:                 05/13/2004
 *      Notes:                  
 *      Change History:         06/05/04
 */
#include <ansi.h>

inherit "room/room";  /*inherits room obj*/

int i;

reset(arg){
        if(!present("lizard"))  {
          for(i=1;i<(2+(random(3)));i++)
           {move_object(clone_object("/players/hogath/area/mobs/newbie/lizard"), this_object());
        }
     }
  
    if(!arg)
    {
     set_light(1);
     short_desc = "Stony Field";  /*room short description*/
     long_desc = 
"     This part of the field you is filled with several rocks\n"+
"of various size.  It seems that this is a favorite gathering \n"+
"place for lizards.\n";  /*long description of room*/

dest_dir = ({
    "/players/hogath/area/newbie/field","east",  /*exits from room*/
    });
    }
  items = 
      ({
        "rocks","Large grey rocks, they look like a good place to catch some sun.\n",
        "field","A large field lies to the east",
        "rock","A large grey stone, looks like a lizard might catch some sun on it",
         });
}
init()
{
    ::init();
    add_action("search_me","search"); /*adds search option to room*/
    add_action("cmd_smell","smell");  /*adds smell command*/
    add_action("cmd_listen","listen");/*add listen command*/
}

cmd_smell(str) {/*smell function*/
    switch(str){
      case "rocks" :
      case "rock" : write("The over turned rock smells like dirt.\n"); break;
      case "field" :
      case "room" :
      default :
      if (!str){
         write("The stony field smells fresh and airy.\n"); break;
       }
      else {
        write("You don't detect any smell from "+str+".\n"); break;
       } 
  }
  return 1;
}

cmd_listen(str) {/*listen function*/
    switch(str){
      case "rock" :
      case "rocks" : write("The rock are silent.\n");
      case "field":
      case "room":
      default:
      if (!str){
        if (present("lizard")){
        write("You hear lizards hissing.\n");
        break;
      }
      else {
        write("The wind whistles through the stony field.\n");
        break;
      }
    }else {write("You don't hear a sound from the "+str+".\n");break;}
  }
  return 1;
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



