/*
 *      File:                   hole.c
 *      Function:               
 *      Author(s):              Hogath@Nirvana
 *      Copyright:              Copyright (c) 2004 Hogath
 *                                      All Rights Reserved.
 *      Source:                 05/09/2004
 *      Notes:                  
 *      Change History:         06/05/04
 */

#include <ansi.h>
#include <security.h>

inherit "room/room";  /*inherits room obj*/

int i;

reset(arg){
    
     
    
if(!arg)
    {
     set_light(0);
     short_desc = "Rabbit Hole";  /*room short description*/
     long_desc = 
"This is the entrance to the rabbit colony that is assaulting\n"+
"the garden above.  It appears that there might be some rather\n"+
"large rabbits about!\n";
/*long description of room*/

dest_dir = ({
    "/players/hogath/area/newbie/garden.c","out",  /*exits from room*/
    "/players/hogath/area/newbie/hole1.c","south",
    });
    }
items =
     ({
       "entrance","A large hole serves as the entrance to the rabbit domain.\n",
       "garden","A pleasant looking garden can be seen just outside the entrance.\n",
       });
}/*stuff to look at*/

init()
{   ::init();
    add_action("search_me","search"); /*adds search option to room*/
    add_action("cmd_smell","smell");  /*adds smell command*/
    add_action("cmd_listen","listen");/*add listen command*/
}

cmd_smell(str) {/*smell function*/
    switch(str){
      case "room" : write("You are assaulted by the odor of rabbit droppings!.\n"); break;
      case "entrance" : write("Fresh air drifts in from the outside.\n"); break;
      case "garden" : write("The garden is too far away to give off a scent.\n"); break;
      default : 
      if(!str){
        write("Odious odors overcome your sense of smell.\n"); break;
       }
       else{
        write("You don't detect any smell from "+str+".\n");break;}
    }
    return 1;
}

cmd_listen(str) {/*listen function*/
    switch(str){
      case "room" : write("Sounds of construction flow from the south.\n"); break ;
      case "entrance" : write("Wind rustles through the entrance.\n"); break;
      case "garden" : write("The garden is too far away to be heard.\n"); break;
      default :
      if(!str)
      { write("Bunny noises!  Yeah, that's right FREAKING BUNNY NOISES!\n"); break;
    }
      else {write("You don't hear anything from the "+str+".\n"); break;
    }
  }
      return 1;
}


search_me(str)   /*search function*/
{
    if(!str)
    {
     notify_fail("What are you trying to search\n");
     return 0;
    }
    
    write("You furiously search the "+str+" find nothing and are disappointed as usual!\n");
    return 1;
}



