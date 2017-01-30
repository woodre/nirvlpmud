/*
 *      File:                   hole1.c
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
     for (i=0;i<(1+random(4));i++)
      {
       move_object(clone_object("/players/hogath/area/mobs/newbie/rabbit2.c"), this_object());
      }
     }/*monster call*/
     
    
if(!arg)
    {
     set_light(0);
     short_desc = "Rabbit Cavern";  /*room short description*/
     long_desc = 
"This rabbit cavern seems to be the connecting point for the\n"+
"rabbit hole's inhabitants.  Currently they seem to be digging to\n"+
"other rooms to the east and west.  There is an anteroom to the\n"+
"south.\n";
/*long description of room*/

dest_dir = ({
    "/players/hogath/area/newbie/hole","north",  /*exits from room*/
    "/players/hogath/area/newbie/holeante.c","south",
});
    }
items =
     ({"cavern","Large and spacious, it marks the beginning of the rabbits territory",
       "anteroom","A large waiting room sits to the south",
       "rooms","Several rooms are being excavated off of this cavern",
       "room","A large room to the south of the cavern",
       });
}/*stuff to look at*/

init()
{   ::init();
    add_action("search_me","search"); /*adds search option to room*/
    add_action("cmd_smell","smell");  /*adds smell command*/
    add_action("cmd_listen","listen");/*add listen command*/
}

cmd_smell(str) {/*smell function*/
    switch (str){
      case "anteroom":
      case "room" : write("A musky odor comes from the room.\n"); break;
      case "cavern" : write("Various odors of animals and earth circulate through the cavern.\n"); break;
      case "rooms" : write("The smell of churned dirt and broken rock circulate's from these rooms.\n"); break;
      default :
      if(!str){
         write("The odor of rabbit droppings surrounds this area.\n"); break;
       }
       else{
        write("You don't detect any smell from "+str+".\n");break;}
        }
  return 1;
}

cmd_listen(str) {/*listen function*/
    switch(str){
      case "cavern" : write("The sounds of endless construction reverb through the cavern.\n"); break;
      case "room" : 
      case "anteroom" : write("Sounds of discussion come from a large anteroom to the south.\n"); break;
      case "rooms" : write("Sounds of continuous construction resound from these rooms.\n"); break;
      default :
      if(!str)
      { write("Bunny noises!\n"); break;
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



