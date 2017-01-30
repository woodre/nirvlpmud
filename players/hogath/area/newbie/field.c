/*
 *      File:                   field.c
 *      Function:               
 *      Author(s):              Hogath@Nirvana
 *      Copyright:              Copyright (c) 2004 Hogath
 *                                      All Rights Reserved.
 *      Source:                 2/13/04
 *      Notes:                  Newbie area
 *      Change History:         Changed to Cedit template on 6/5/04  
 */

#include <ansi.h>
#include <security.h>

inherit "room/room";  /*inherits room obj*/

int i;/*counter variable*/

reset(arg){
        if(!present("butterfly"))  {
          for(i=1;i<(3+(random(7)));i++)
           {move_object(clone_object("/players/hogath/area/mobs/newbie/butterfly"), this_object());
        }
     }/*monster call*/
  
    if(!arg)
    {
     set_light(1);
     short_desc = "Grassy Field";  /*room short description*/
     long_desc = 
"This is a field south of the forest entrance.  It is a\n"+
"peaceful setting, with only a small trail of smoke coming\n"+
"from a large mound to disturb it.  To the west you can see\n"+
"a field full of stones, while to the east a river bank defines\n"+
"the border.\n";  /*long description of room*/

dest_dir = ({
    "/players/hogath/area/entrance1","north",  /*exits from room*/
    "/players/hogath/area/newbie/sfield","west",
    "/players/hogath/area/newbie/rbank","east",
    "/players/hogath/area/newbie/mounddr","mound",
           });
}
items = ({
          "smoke","Smoke trails off into the clouds",
          "mound","You see a small door on the side of the earthen mound",
          "large mound","A large mound rises up from the center of the field\n"+
                        "blocking passage to the south",
          "grass","This grass has been neatly cut by someone",
          "field","A large expanse of grassy land, which has been disected by a large mound",
          "forest","A forest can be seen to the north",
          "trail","A slight trail of smoke rising from the mound\n",
          "stone","A grey moss covered stone can be seen to the west",
          "stones","The field to the west is littered with stones",
          "river","A broad uncrossable river flows to the east",
          "bank","A muddy river bank can be seen to the east",
          "river bank","A muddy river bank can be seen to the east",
          "border","The river to the east serves as the border for this field",
           });/*items to look at*/
}

init()
{
    ::init();
    add_action("search_me","search"); /*adds search option to room*/
    add_action("cmd_smell","smell");  /*adds smell command*/
    add_action("cmd_listen","listen"); /* add listen command*/
}

cmd_smell(str) {/*smell function*/
    switch (str){
      case "field": write("The field smells like freshly cut grass.\n"); break;
      case "smoke": write("The acrid smell of burning wood fills the air.\n"); break;
      case "mound": write("The mound smells like grass.\n"); break;
      case "bank": write("It is too far away to catch a scent.\n"); break;
      case "river":
      case "river bank": write("It is too far away to be smelled.\n"); break;
      case "stone": write("The stone is too far away to be smelled.\n"); break;
      case "stones": write("The stones cannot be smelled from here.\n"); break;
      case "door" : write("There is a small door into the mound here\n"); break;
      default:
      if (!str){
         write("The smell of freshly cut grass surround the field.\n"); break;
       }
      else {
        write("You don't detect any smell from "+str+".\n"); break;
}
}
 return 1;}

cmd_listen(str) {/*listen function*/
    switch(str){
      case "mound":
      case "field": write("Chattering of crickets abounds.\n"); break;
      case "bank":
      case "river bank":
      case "river": write("Rushing water can be heard in the distance.\n"); break;
      default: 
      if(!str){
        write("The fluttering of wings on the wind\n"); break;
      }
      else{
      write("You don't hear anything from "+str+".\n");break;
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



