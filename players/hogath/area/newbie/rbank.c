/*
 *      File:                   rbank.c
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
          for(i=1;i<(2+random(5));i++)
           {move_object(clone_object("/players/hogath/area/mobs/newbie/lizard"), this_object());
        }
     }/*clones monster into room*/
  
    if(!arg)
    {
     set_light(1);
     short_desc = "River bank";  /*room short description*/
     long_desc = 
"     This is a river bank that borders the eastern portion \n"+
"of the field.  The river is rather calm, and there are flowers\n"+
"and several rocks all along the bank itself.\n";  /*long description of room*/

dest_dir = ({
    "/players/hogath/area/newbie/field","west",  /*exits from room*/
    "/players/hogath/area/newbie/pool","pool",
            });
             }

  items = 
      ({
        "field","A field can be seen to the west",
        "rock","A wet rock",
        "flower","A beautiful "+HIY+"Daisy"+NORM+"",
        "river bank","The river bank is quite muddy and filled with flowers",
        "bank","The river bank is quite muddy and filled with flowers",
        "rocks","Wet rocks on the river bank",
        "river","Strong water flows in the river preventing you from crossing.",
        "pool","A shallow pool has been formed by the current here.",   
        "flowers","These are "+HIY+"daisies"+NORM+" and "+HIK+"black"+HIY+"eyed"+NORM+" susans which line the bank.",
       });
}
init()
{
    ::init();
    add_action("search_me","search"); /*adds search option to room*/
    add_action("cmd_smell","smell");  /*adds smell command*/
    add_action("cmd_listen","listen"); /*add listen command*/
}


cmd_smell(str) {/*smell function*/
    switch(str){
      case "flowers":
      case "flower" :
      if (random(8) > 4)
       {
         write("The "+HIK+"black"+HIY+"eyed"+NORM+" susan smells wonderful.\n"); break;
       }
       else {
         write("The "+HIY+"daisy"+NORM+" smells nice.\n");break;
       }
      case "daisies":
      case "daisy": write("The "+HIY+"daisy"+NORM+" has a pleasant odor.\n");break;
      case "blackeyed susan":
      case "blackeyed susans": write("The "+HIK+"black"+HIY+"eyed"+NORM+" susans have a pleasant aroma.\n"); break;
      case "pool": write("Cool and clean, it has a refreshing odor.\n"); break;
      case "bank":
      case "river bank":
      default : 
      if (!str){
         write("Clean and crisp, the air here has a slight earthy tone to it.\n"); break;
       }
      else {
        write("You don't detect any smell from "+str+".\n"); break;
       } 
    }
      
  return 1;
}

cmd_listen(str) {/*listen function*/
    switch(str){
      case "flowers":
      case "flower": write("The flowers rustle in the wind.\n"); break;
      case "blackeyed susan":
      case "blackeyed susans":
      case "daisies":
      case "daisy" : write("Bees buzz around the flowers.\n"); break;
      case "river":
      case "river bank":
      case "bank":
      default :
      if (!str){
          write("The sound of raging water comes off the river bank.\n");break;
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
     notify_fail("What are you trying to search?\n");
     return 0;
    }
    
    write("You furiously search the "+str+" but find nothing.\n");
    return 1;
}




