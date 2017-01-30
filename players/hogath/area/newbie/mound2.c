/*
 *      File:                   mound2.c
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
     if(!present("shella"))
    {
     for(i=1;i<2;i++)  
     {
       move_object(clone_object("/players/hogath/area/mobs/newbie/shella"), this_object());
     }
     
    }     
    
if(!arg)
    {
     set_light(1);
     short_desc = "Kitchen";  /*room short description*/
     long_desc = 
"     You've entered a small kitchen.  It is neatly arranged with\n"+
"wood burning stove in one corner, a small table to work on, and\n"+
"an equally proportioned cupboard.  Pans hang above the table on a\n"+
"rack and pots are stacked on top of the cupboard.\n";
/*long description of room*/

dest_dir = ({
    "/players/hogath/area/newbie/mound1.c","east",  /*exits from room*/
    "/players/hogath/area/newbie/garden.c","south",});
    }
items =
     ({
       "rack","A rack for hanging pans has been installed here",
       "flour","White flour covers the table",
       "kitchen","This is where the cooking for the home is done",
       "table","A small three foot by three foot table that is covered with flour",
       "floor","A hard wooden floor covered with flour",
       "cupboard","A small oak cupboard, it is used to store bread",
       "stove","An iron cast wood burning stove",
       "pans","These are cast iron pans hung for ease of access",
       "pan","A large cast iron pan",
       "pots","These are neatly stacked pots on top of the cupboard",});
}

init()
{   ::init();
    add_action("search_me","search"); /*adds search option to room*/
    add_action("cmd_smell","smell");  /*adds smell command*/
    add_action("cmd_listen","listen");/*add listen command*/
}

cmd_smell(str) {
    switch(str){
      case "pan":
      case "pans": write("The pans smell sanitized.\n"); break;
      case "cupboard" :write("A pleasent sent of baked bread come from this cupboard.\n");break;
      case "stove":
      case "oven" : write("It smells like someone is baking bread in this oven.\n"); break;
      case "table" :
      if (present("shella"))
       {
         write("Shella won't let you smell the table.\n");
         break;
       }
       else write("Mmmmm, fresh bread.\n"); break;
      case "kitchen":
      case "room":
      default : 
      if (!str){
         write("The kitchen smells like fresh baked bread.\n"); break;
       }
      else {
        write("You don't detect any smell from "+str+".\n"); break;
       }
  }
  return 1;
}

cmd_listen(str) {
    switch(str){
      case "stove": write("Water boils on the stove.\n");break;
      case "oven" : write("A strong fire seems to be going in the oven.\n");break;
      case "pan" :
      case "pans" : write("The pans clank overhead.\n"); break;
      case "table":
      if (present("shella"))
       {
         write("Shella hums over the table.\n");
         break;
       }
       else write("No more humming!\n"); break;
      case "cupboard": write("The sounds of the kitchen drown out all other noise\n"); break;
      default :
      if (!str){
          write("Water boils, while bread bakes in the oven.\n"); break;
       }
      else {
        write("You don't detect any sound from the "+str+".\n"); break;
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
    
    write("You furiously search the "+str+" but find nothing.\n");
    return 1;
}



