inherit "/players/jareel/room";
#include "/players/jareel/define.h"

     reset(arg) {

     if(!present("vandar"))  {
       MOCO("/players/jareel/monsters/chaos/vandar.c"),this_object()); 
     }
     
     if(!present("guard"))  {
       MOCO("/players/jareel/monsters/chaos/yelmalian_elite_guard.c"),this_object()); 
     }
 
     if(arg) return;
    
     set_light(0);
     short_desc=(BLK+BOLD+"A Dark Cavern"+NORM);
     long_desc=
       "      The hole is a rough circular shape carved into the stone.  The\n"+
       "cave floor is uneven and covered with small jagged rocks.  The walls\n"+
       "are covered in slimy green mucus ridden moss.  The only obvious way out\n"+
       "is the exit you came in.\n";
     items = ({
       "exit","it's the way out, it's the '"+BOLD+"exit"+NORM+"'",
       "slime","A slicky mucus drips off the moss",
       "cave","The walls of the cavern are covererd in a slimy green moss",
       "walls","The walls are mucus covererd",
       "rocks","The floor has hundreds of small sharp rocks covering it",
       "floor","The hard floor is made of a gray stone",
       "wall","The small cave seems to be chewed by some creatures teeth",
       "stones","Small chunks of granite lie around the room",
       "stone","The walls seem to be carved with some sort of animal teeth",
       "hole","The way you entererd this room perhaps you could 'exit' back into the wood",
       "moss","The moss squishes as you press your hand into it",
       "mucus","A greenish slime, that sticks you, when you touch it",
 
});
}

     init() {
       ::init();
         add_action("Search","search");
         add_action("OUT","out");
         add_action("cave","exit");
      /*   add_action("MOSS","enter"); */
     }

     MOSS(){
       TP->move_player("pushes past the moss.#players/jareel/areas/chaos/cave/grid1/hall10");
     return 1; }

     cave(){
       TP->move_player("leaves the cavern.#players/jareel/areas/chaos/forest9");
     return 1; }

     OUT(){
       TP->move_player("leaves the cavern.#players/jareel/areas/chaos/forest9");
     return 1; }

     Search(str) {
       if(!str) { write("Search what?\n"); return 1; }
       write("You search the "+str+" but find nothing special.\n");
       say(this_player()->query_name()+" searches around for something.\n");
     return 1;
}
