/*
 *  File:   /players/mosobp/areas/VEGETA/rooms/vegeta1.c
 *  Function:  room
 *  Author(s):  Mosobp@Nirvana
 *  Copyright: copyright (c) 2013 Mosobp
 *             all rights reserved 
 *                                       
 *                                       
 *  Source:  03/26/2013
 *  Notes:  
 *  
 *   
 *  Change History:              
 */
 
#include "/sys/lib.h"
#include "/obj/ansi.h"

inherit "room/room";
reset(arg) {
  ::reset(arg);
  if( !present("gine",this_object()) )
  move_object(clone_object("/players/mosobp/areas/VEGETA/NPC/gine.c"), this_object());
  if(arg) return;

short_desc = RED+"Planet Vegeta"+NORM;
long_desc = 
  "This is the crater created by the spaceship landing site. The spaceship\n"+
  "which brought you is behind, and the Castle is looming in the distance.\n"+
  "There are bushes on the ground around, and trees giving\n"+
  "shade overhead.\n"+
  "You can type 'ship' to head back to the "+HIK+"Spaceship"+NORM+".\n";
  items = ({
  "road",
  "A road from the ship to the castle",
  "spaceship",
  "The ship you arrived on",
  "ship",
  "The ship you arrived on",
  "castle",
  "The Saiyan castle of King Vegeta looms in the distance",
  "bushes",
  "Green leafy bushes planted beside the road to the castle",
  "trees",
  "Trees planted to give shade over the road to the castle",
});
set_light(1);
dest_dir = ({
"players/mosobp/areas/VEGETA/rooms/vegeta1.c","up",
});
}

init(){
  ::init();
  add_action("cmd_ship", "ship");
}

cmd_ship(str) {
  object ship;
  if(str) return 0;
  write("\n\n\tYou head back to the ship.\n\n");
  ship = clone_object("/players/mosobp/areas/VEGETA/rooms/ship_fran");
  ship->set_location("/players/mosobp/areas/VEGETA/rooms/vegeta0");
  move_object(this_player(), ship);
  command("look", this_player());
  return 1;
}