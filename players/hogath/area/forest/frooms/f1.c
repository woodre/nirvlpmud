/*
 *      File:                   f1.c
 *      Function:               
 *      Author(s):              Hogath@Nirvana
 *      Copyright:              Copyright (c) 2004 Hogath
 *                                      All Rights Reserved.
 *      Source:                 06/15/2004
 *      Notes:                  Black forest for my area
 *      Change History:
 */
#include <ansi.h>
#include <security.h>
#include "/players/hogath/tools/def.h"
inherit "room/room";  /*inherits room obj*/

reset(arg){
    if(!arg)
    {
     set_light(1);
     short_desc =HIK+"Black forest"+NORM;  /*room short description*/
     long_desc = HIK+"The forest is thick here with a slight fog covering\n"+
                     "listing slightly along the ground.  A strange sense\n"+
                     "of dread hangs heavy in the air.\n"+NORM;/*long description of room*/
              
dest_dir = ({"/players/hogath/area/forest/frooms/f2.c","east",
             "/players/hogath/area/forest/frooms/f4.c","south",
             });
            
    }
items = 
     ({"trees","Twisted in horror, these gigantice oaks tower over you",
       "fog","This fog hugs the ground closely obscuring the ground",
       "floor","The floor of the forest can't be seen through the dense fog",
       "forest","All around you it's stench can barely be contained",});
       }              

init()
{
    ::init();
    add_action("search_me","search"); /*adds search option to room*/
    add_action("cmd_smell","smell");
    add_action("cmd_listen","listen");
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

move_me(str){
  if(str =="leave"){
    write("You leave the forest.\n");
    move_object(this_player(),"/players/hogath/area/forest/frooms/f0.c");
    command("look", this_player());
    return 1;
    }
  else {
    if (tp->query_attrib("wil") > random(35)){   /*add a little bit of a random aspect to the area*/
    write("You travel "+str+".\n");
    say(tpn+" travels "+str+".\n");
    switch (str){
      case "west": move_object(this_player(),"/playes/hogath/area/forest/frooms/f2.c");break;
      case "south": move_object(this_player(),"/players/hogath/area/forest/frooms/f.4");break;
      /*default :write("You slam into the trees when you try to travel "+str+".\n");break;*/
    }
    }
    else {
    write(BOLD+"You are confused as you travel the forest.\n"+NORM);
    move_object(this_player(),"/players/hogath/area/forest/frooms/f"+random(12)+".c");
    command("look", this_player());
    return 1;
  }
}
}
cmd_smell(str){
    switch(str){
      case "floor":write("An overpowering stench rises from the forest floor.\n");break;
      case "fog": write("The fog bears the scent of decay.\n");break;
      case "oaks":
      case "trees":
      case "tree": write("A sickly sweet odor exudes from the trees.\n"); break;
      case "room":
      case "forest":
      default:
      if(!str){
        write("An oppressive lingering scent of decay fills the air.\n");break;
      }
      else{
         write("you don't smell anything from the "+str+".\n");break;
    }
}
    return 1;
}
cmd_listen(str){
  switch(str){
    case "fog": write("The fog carries the sound of dead and dying on it.\n");break;
    case "floor": write("Dead underbrush crunches on the forest floor.\n");break;
    case "forest" :write("The trees moan around you.\n");break;
    case "oak":
    case "tree":
    case "trees":write("The trees hunger for your death.\n");break;
    case "room":
    default:
    if(!str){
       write("Sounds of pain and horror are all around you.\n");break;
     }
     else {
       write("The "+str+" doesn't make a sound.\n");
     }
   }
  return 1;
}  

