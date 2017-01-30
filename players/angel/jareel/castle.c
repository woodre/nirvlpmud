#define NAME "Jareel"
#include "/players/jareel/define.h"
#define DEST "room/lanceroad4"
/*
 * This is just the facade to a castle. If you want to enable the
 * "enter" command, move the player to a hall or something (which
 * you have to design yourself).
 * The predefined string DEST is where a player should come when he
 * leaves the castle.
 *
 * This file is loaded automatically from "init_file". We have to move
 * ourself to where we are supposed to be.
 */

  reset(arg){ 
    if(arg)
    return;
  
  move_object(this_object(), DEST); 

  "/players/jareel/toys/telldevice2.c"->load_it();
  "/players/jareel/toys/telldevice.c"->load_it();
  "/players/jareel/GUILD/obj/loader.c"->load_it();
}

  id(str) { return str == "hall"; }


  long() {
    write("The pass leads north into a forest.");
}

init() {
  add_action("north", "north", 1);
  add_action("south", "south", 1);
  add_action("look_hall","look");
  add_action("look_hall","l");
  add_action("look_hall","exa");
}


north(){
  TP->move_player("leaves north#players/jareel/areas/entrance_area/grass_plain_1");
  return 1; }

south(){
  TP->move_player("leaves north#players/jareel/areas/south_entrance/jareelsworld/enter.c");
  return 1; }

is_castle(){ return 1; }

look_hall(arg){
  if(arg == "hall" || arg == "hall of legends"){
    write("A long dark hallway you can enter.\n");
  return 1; }
}

