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

inherit "room/room";  /*inherits room obj*/

int i;

reset(arg){
     
    
if(!arg)
    {
     set_light(1);
     short_desc = "Bed Room";  /*room short description*/
     long_desc = 
"     This is a small bedroom off of the living room.  Along\n"+
"the north wall is a spacious gnome bed.  There is a dresser\n"+
"along the wall next to it and at the foot of the bed rests \n"+
"a wooden trunk.\n";
/*long description of room*/

dest_dir = ({
    "/players/hogath/area/newbie/mound1.c","west",  /*exits from room*/
    });
    }
items =
     ({
       "room","This is a small bedroom",
       "bedroom","This is where the gnomes sleep",
       "living room","A living room can be seen to the west",
       "bed","A small bed, it looks perfect for a gnome couple",
       "dresser","A well made gnome dresser, there is a vase on top of it",
       "trunk","A large wooden chest which is used to store clothes",
       "vase","A blue vase which has some flowers in it",
       "flowers","These are daisy's and blackeyed Susans",});
}

init()
{   ::init();
    add_action("search_me","search"); /*adds search option to room*/
    add_action("cmd_smell","smell");  /*adds smell command*/
    add_action("cmd_listen","listen");/*add listen command*/
}

cmd_smell(str) {
    switch(str){
      case "vase":
      case "flowers" : write("The daisy's and blackeyed susans have a pleasing aroma.\n");break;
      case "trunk" : write("The trunk smells like moth balls.\n"); break;
      case "dresser" : write("A slight lingering scent of moth balls wafts up from the dresser.\n"); break;
      case "living room": write("The breeze carries the scent of cinnamon from the living room.\n");break;
      case "bed": write("Whew! Time to change those sheets.\n");break;
      case "room":
      case "bedroom":
      default:
      if (!str){
         write("The scent of fresh flowers permeates the room.\n");break;
       }
      else {
        write("You don't detect any smell from "+str+".\n"); break;
       } 
    }
    return 1;
}

cmd_listen(str) {
    switch(str){
      case "vase":
      case "flowers": write("A slight buzzing sound can be heard from the flowers.\n");
      case "trunk": write("It creaks as it is opened.\n");break;
      case "living room": write("A crackling fireplace can be heard in the living room.\n");break;
      case "bed": write("The bed's springs creak as you press down on it.\n");break;
      case "room":
      case "dresser" : write("Thd dresser's drawers squeek as they are examined.\n"); break;
      case "bedroom":
      default :
      if (!str){
          write("The room is quiet and peaceful.\n");break;
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







