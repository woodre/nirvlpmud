/*
 *      File:                   f3.c
 *      Function:               
 *      Author(s):              Hogath@Nirvana
 *      Copyright:              Copyright (c) 2004 Hogath
 *                                      All Rights Reserved.
 *      Source:                 10/2004
 *      Notes:                  Black forest for my area
 *      Change History:
 */

#include <ansi.h>
#include <security.h>
#include "/players/hogath/tools/def.h"
inherit "room/room";
int moved;

reset(arg) {
  if(!arg){
    moved = 0;
    set_light(1);
    short_desc = BOLD+"A field"+NORM;
    long_desc = BOLD+"The forest opens up into a large field before a rocky cliff.\n"+
                     "The stone face of the cliff towers before you shadeing tall grass\n"+
                     "giving an oppressive feeling which even a brightly shining sun.\n"+
                     "cannot dispel.\n"+NORM;
   dest_dir = ({
             "/players/hogath/area/forest/frooms/f7.c","south",
             "/players/hogath/area/forest/frooms/f4.c","east",
              });
  }
  
  items = 
      ({
        "field","A large grassy field sits before the cliff",
        "trees","Twisted and morose, the trees seem to not grow well here",
        "forest","The dark forest surrounds this cliff side area",
        "cliff","Cracks and crags run along the face of this rocky cliff",
        "cave","A large cave has been dug into the cliff face",
        "face","The rock face is craggy and cracked",
        "boulder","A large boulder blocking the cave entrance, it could\n"+
                  "be moved aside",
        "grass","Grass has grown tall in this field.\n",
        });
 }   
  init(){
    ::init();
    add_action("search_me","search");
    add_action("enter_cave","enter");
    add_action("cmd_smell","smell");
    add_action("cmd_listen","listen");
    add_action("move_boulder","move");
    add_action("enter_cave","enter");
    }
  
search_me(str){
    if(!str)
    {
     notify_fail("What do you want to search?\n");
     return 0;
    }
  write("You search the "+str+" and find nothing.\n");
  return 1;
}
    
move_boulder(str){
  if(!str)
    {
     notify_fail("What do you want to move?\n");
     return 0;
    }
    if (str == "boulder" || str == "Boulder" && tp->query_attrib("str") > random(40)){
    write("You move the boulder aside\n");
    say(tpn+" moves aside a large boulder\n");
    moved = 1;
    return 1;}
   else {
     write("Your muscles strain as you fail to move the boulder.\n");
     say(tpn+" strains but fails to move the boulder.\n");
     return 1;
   }
 }
 
enter_cave(str){
  if (!str){
    notify_fail("Enter what?\n");
    return 0;
  }
  if (str == "cave" && moved < 1){
    write("A large boulder blocks the cave mouth.\n");
    return 1;
  }
  if (str == "cave" && moved > 0){
    write("You enter the cave.\n");
    say(tpn+" enters a cave.\n");
    move_object(this_player(),"/players/hogath/area/forest/cave/c0.c");
    command("look", this_player());
    return 1; }
}
cmd_smell(str){
    switch(str){
      case "grass": write("A sweet earthy odor comes off the grass.\n");break;
      case "cliff": write("The cliff puts off an odor of dirt and crushed rock.\n");break;
      case "field": write("A cool breeze carries fresh air to this field.\n");break;
      case "cave": write("A noxious odor sits at the entrance to the cave.\n");break;
      case "trees":
      case "tree": write("A sweet odor exudes from the trees.\n"); break;
      case "room":
      case "forest":
      default:
      if(!str){
        write("The air is fresh and clean here.\n");break;
      }
      else{
         write("you don't smell anything from the "+str+".\n");break;
    }
}
    return 1;
}
cmd_listen(str){
  switch(str){
    case "grass": write("Grass rustles as the wind passes through it.\n");break;
    case "cliff": write("Silence...\n");break;
    case "field": write("The wind loudly swirls around the room.\n");break;
    case "cave": write("A large boulder blocks the sound from this cave.\n");break;
    case "forest" :write("Wind stirs the leaves in the forest.\n");break;
    case "tree":
    case "trees":write("The trees hunger for your death.\n");break;
    case "room":
    default:
    if(!str){
       write("The wind whistles around the field.\n");break;
     }
     else {
       write("The "+str+" doesn't make a sound.\n");
     }
   }
  return 1;
}     
