/* ***********************************************
 * room6.c
 *
 * Creator - Data
 * 
 * Date of File Completion - 10/30/2005
 * 
 *
 * **********************************************/
#include "ansi.h"

inherit "room/room";
reset(arg) {
  object monster;
  if(arg) 
    return ;    
  set_light(0); 
  short_desc = HIK+"Outer Boundary"+NORM; 
  long_desc  =
 "There is a stream in this part of the forest, but still no signs of\n"+
 "life. Then some kind of slow moving creatures emerge from all around.\n";

items=({
 "water", "As you gaze into the water you see nothing, as the water is poluted by death",
 "creatures", "You can't tell what they are from this distance",

});

 add_listen("main", "What do you want to listen to?");
 add_listen("water", "The water sounds thick with sludge");
 add_listen("creatures", "You hear a clicking sound coming from the west, and from the south");
 
 add_taste("main", "What do you wish to taste?");
 add_taste("water", "You get close down to the water for a taste, but think better of it");
 add_taste("creatures", "You're too far away...");

 add_smell("main", "What do you wish to smell?"); 
 add_smell("water", "You can't smell much here since the stench of death is so strong");
 add_smell("creatures", "You can't smell much here since the stench of death is so strong");
 
  dest_dir =
  ({ /* needed to signify an array */
  "players/data/OUTERB/ROOMS/room1.c", "south",
  "players/data/OUTERB/ROOMS/room5.c","west"
  });

}