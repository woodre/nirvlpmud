/*
 *      File:                   holethrone.c
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


reset(arg){
    if(!present("rabbit"))
    {
     move_object(clone_object("/players/hogath/area/mobs/newbie/rabbitking.c"),this_object()); 
      }/*monster call*/
    
       
    
if(!arg)
    {
     set_light(0);
     short_desc = "Throne Room";  /*room short description*/
     long_desc = 
"This spacious room is the throne room for the rabbit king.\n"+
"Inter-spaced around the room are large stalagmites, with a\n"+
"large central one carved into the shape of a throne.\n";
/*long description of room*/

dest_dir = ({
    "/players/hogath/area/newbie/holeante","north",  /*exits from room*/
    });
    }
items =
     ({
       "stalagmites","These large rocky protrusion's abound throughout the room",
       "stalagmite","These are large rocky protrusion's formed by dripping water",
       "throne","Carved out of a large stalagmite, this throne has been lined with\n"+
                "owl feathers of various sizes and seems to be covered with rabbit\n"+
                "fur from the king",
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
      case "stalagmite" :
      case "stalagmites" : write("The rocks around you have no detectable odor.\n"); break;
      case "room" :
      case "throne room" : write("The stench of rabbit droppings is over powering.\n"); break;
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
      case "throne" : write("Not a sound comes from the throne.\n"); break;
      case "room":
      case "throne room":
      default :
      if (!str){
        if (present("rabbit"))
          {write("The king thunders on his throne!\n");break;}
         if(!present("rabbit")){write("The room is quiet...\n"); break;}
      else {write("You don't hear anything from "+str+".\n");break;}
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



