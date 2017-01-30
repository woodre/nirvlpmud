/* ***********************************************
 * room8.c
 *
 * Creator - Data
 * 
 * Date of File Completion - 10/30/05 
 * 
 *
 * **********************************************/
#include "ansi.h"

inherit "/room/room";
reset(arg) {
  object monster;
  if(arg) 
    return ;    
  set_light(0); 
short_desc = HIK+"Outer Boundary"+NORM;
  long_desc  = "Dead bushes line the sides of this massive crater. Towards the bottom\n"+
               "there appears to be an opening into some old under water cave.\n";
			   
items=({
 "bushes", "The bushes line the crater as though there used to be a waterway here",
 "crater", "The crater looks long and wide, gazing into it you see bones of long dead animals and an opening",
 "opening", "The opening is small in size, and appears to be close to collapse as the mud seals it",
 "bones", "Bones of birds, fish, as well as many other creatures litter the floor",
});

 add_listen("main", "What do you want to listen to?");
 add_listen("bushes", "You listen to the bushes, and hear nothing");
 add_listen("crater", "You listen to the crater, and hear something comming from the opening");
 add_listen("opening", "You listen to the opening and shiver, SOMETHING IS IN THERE");
 
 add_taste("main", "What do you wish to taste?");
 add_taste("bushes", "You taste the bushes foolishly");
 add_taste("crater", "You taste the crater and spit");
 add_taste("opening", "You refuse to taste the opening");
 
 add_smell("main", "What do you wish to smell?"); 
 add_smell("bushes", "You smell the bushes and step away");
 add_smell("crater", "The smell of the crater is filled with death and decay");
 add_smell("opening", "A rotten stench imminates from the crater, perhaps there are fresh corpses in it");

  dest_dir =
  ({ /* needed to signify an array */
  "players/data/OUTERB/ROOMS/room16", "cave",
  "players/data/OUTERB/ROOMS/room7", "west",
  });

}
