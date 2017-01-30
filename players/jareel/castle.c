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
/*
  "/players/jareel/GUILD/obj/loader.c"->load_it();
*/
}

  id(str) { return str == "hall"; }


short() {
return "A small wood sign pointing north";
}  

  long() {
    write("The pass leads north into a forest.");
}

init() {
  add_action("north", "north", 1);
  add_action("south", "south", 1);
  add_action("look_sign","look");
  add_action("look_sign","l");
  add_action("look_sign","exa");
}


north(){
  TP->move_player("leaves north#players/jareel/areas/entrance/road1");
  return 1; }

south(){
  TP->move_player("leaves north#players/jareel/areas/south_entrance/jareelsworld/enter.c");
  return 1; }

is_castle(){ return 1; }

look_sign(arg){
  if(arg == "sign" || arg == "wood sign"){
    write("Jareel's area resides to the north. ["+HIR+"PARTS UNDER CONSTRUCTION"+NORM+"]\n");
  return 1; }
}

