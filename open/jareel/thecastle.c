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

   

}

     id(str) { return str == "north" || str == "n" || str == "path" || str == "road"; }

     short() {
       return ""+BOLD+"The Hall of Legends"+NORM+"\nA dirt road leads north";

}

     long() {
       write("The pass leads north into a forest.");
}

     init() {
       add_action("enter", "enter");
       add_action("north", "north", 1);
       add_action("look_hall","look");
       add_action("look_hall","l");
       add_action("look_hall","exa");
}

     enter(str) {
       if (!id(str))
         TP->move_player("leaves north#players/jareel/areas/statue/enter");
           return 1; }

     north(){
       TP->move_player("leaves north#players/jareel/areas/entrance_area/grass_plain_1");
         return 1; }

is_castle(){ return 1; }

     look_hall(arg){
       if(arg == "hall" || arg == "hall of legends"){
         write("A long dark hallway you can enter.\n");
           return 1; }
}
