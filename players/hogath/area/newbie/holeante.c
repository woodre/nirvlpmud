/*
 *      File:                   holeante.c
 *      Function:               
 *      Author(s):              Hogath@Nirvana
 *      Copyright:              Copyright (c) 2004 Hogath
 *                                      All Rights Reserved.
 *      Source:                 05/13/2004
 *      Notes:                  
 *      Change History:         06/05/04
 */

#include <ansi.h>
#include <security.h>

inherit "room/room";  /*inherits room obj*/

int i;

reset(arg){
    if(!present("rabbit"))
    {
     for (i=0;i<random(3);i++)
      {
     switch (random(2)){
     case 0: move_object(clone_object("/players/hogath/area/mobs/newbie/rabbit3.c"),this_object()); break;
     case 1: move_object(clone_object("/players/hogath/area/mobs/newbie/rabbit2.c"),this_object()); break;
     default: move_object(clone_object("/players/hogath/area/mobs/newbie/rabbit3.c"),this_object()); break;
      }
      }
     }/*monster call*/
     
    
if(!arg)
    {
     set_light(0);
     short_desc = "Rabbit Anteroom";  /*room short description*/
     long_desc = 
"A large open space, this room appears to be used as a waiting\n"+
"room for those rabbits who are waiting to speak to the Rabbit King.\n"+
"Judging by the odors of the room it is obvious that the rabbits have\n"+
"poor hygienic habits.\n";
/*long description of room*/

dest_dir = ({
    "/players/hogath/area/newbie/hole1","north",  /*exits from room*/
    "/players/hogath/area/newbie/holethrone.c","south",
    });
    }
items =
     ({"room","Craggy walls and large stalagmites characterize this otherwise bare room",
       "stalagmites","Large rock formations protruding from the floor of the room",
       "walls","Rough and uneven, these walls have have an unfinished feel to them",
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
      case "walls": write("The walls have absorbed the scent of rabbit droppings.\n"); break;
      case "stalagmites" : write("Stalagmites smell like the walls ya freak!\n"); break;
      case "room" : write("You are assulted by the odor of rabbit dropings!.\n"); break;
      default : 
      if (!str){
         write("It smells like rabbit POOP!\n"); break;
       }
      else {
        write("You don't detect any smell from "+str+".\n"); break;
       }
    }
    return 1;
}

cmd_listen(str) {/*listen function*/
    switch(str){
      case "stalagmites" : write("drip drip drip...\n"); break;
      case "room" :
        if (present("rabbit"))
        write("Rabbits talk...how strange!\n");
        else write("An errie silence pervades the room...\n");
        break;
      default : 
      if(!str){
        write("Bunny noises!.\n"); break;
      }
      else{
      write("You don't hear anything from "+str+".\n");break;
    }
  }return 1;
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



