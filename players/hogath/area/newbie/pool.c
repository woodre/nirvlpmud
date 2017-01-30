/*
 *      File:                   pool.c
 *      Function:               
 *      Author(s):              Hogath@Nirvana
 *      Copyright:              Copyright (c) 2004 Hogath
 *                                      All Rights Reserved.
 *      Source:                 05/13/2004
 *      Notes:                  
 *      Change History:         06/10/04
 */
#include <ansi.h>

inherit "room/room";  /*inherits room obj*/

int i;

reset(arg){
        if(!present("trout"))  {
          for(i=1;i<4;i++)
           {move_object(clone_object("/players/hogath/area/mobs/newbie/trout"), this_object());
        }
     }/*calls monster to room*/
  
    if(!arg)
    {
     set_light(1);
     short_desc = "Shallow Pool";  /*room short description*/
     long_desc = 
"     This is a pool formed by the flow of the river.  The\n"+
"water is cool, and something seems to be swimming in it.\n";  /*long description of room*/

dest_dir = ({
    "/players/hogath/area/newbie/rbank","wade",  /*exits from room*/
    });
    }
  items = 
      ({
        "water","The"+BLU+" water "+NORM+"is calm, except for a few ripples.\n",
        "pool","You can see the ripples made by your movements.\n",
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
    if (!str){
         write("The air here is clean and fresh.\n");
       }
      else {
        write("You don't detect any smell from "+str+".\n");
       } 
    return 1;
}

cmd_listen(str) {/*listen function*/
    if (!str){
      if (present("trout"))
    {
      write("You hear the fish leaping in and out of the"+BLU+" water"+NORM+".\n");
    return 1;}
  }
    else {
      write("You don't hear a sound from the "+str+".\n");
     return 1;
  }
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



