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
    if(!present("chowder")){
    for(i=1;i<2;i++) {
      move_object(clone_object("/players/hogath/area/mobs/newbie/chowder"), this_object());
    }
}/*monster call*/
    if(!arg)
    {
     set_light(1);
     short_desc = "Doorway";  /*room short description*/
     long_desc = 
"     This is the doorway to a cute little gnome home.  It is quite\n"+
"compact owning to the size of it's owners.  There is a dog lazing \n"+
"around here.\n";  /*long description of room*/

dest_dir = ({
    "/players/hogath/area/newbie/field.c","out",  /*exits from room*/
    "/players/hogath/area/newbie/mound1.c","south",});
    }
items =
     ({
       "grass","Bits of grass have grown out of the walls",
       "walls","Dirt walls with grass and roots poking out of them",
       "doorway","A simple doorway into the rest of the mound",
       "dirt","It's been packed into a hard floor here",
       "door","A small wooden door",
       "floor","A packed dirt floor",
       "wall","They are just dirt with some roots poking out",
       "roots","These are roots from the grass that grows on the mound",
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
    switch (str){
      case "grass" : write("The grass has a definitive earthy smell to it.\n"); break;
      case "wall" :
      case "walls" : write("A grassy odor oozes from the walls.\n"); break;
      case "dirt" : 
      case "floor" : 
      default :
      if (!str){
         write("The room has an earthy smell to it.\n");break;
       }
      else {
        write("You don't detect any smell from "+str+".\n"); break;
       } 
    } 
  return 1;
  }
  


cmd_listen(str) {/*listen functon*/
    switch(str){
      case "door" : write("The wind can be heard blowing outside");break;
      default :
      if (!str){
        if (present("chowder"))
          {
            write("The dog is growling.\n");break;
            }
         if(!present("chowder"))
         {
           write("A crackling fire can be heard to the south.\n");break;
           }
      else {
        write("You don't hear anything from "+str+".\n");break;
        }
       }
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



