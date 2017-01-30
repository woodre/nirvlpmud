#include "/players/snakespear/closed/ansi.h"
inherit "room/room";

reset(arg) {
   if(arg) return;   
set_light(2);
short_desc=(RED+"Inferno"+NORM);
long_desc=RED+
 "  This passage leads leads east and west.  The walls are dark and hot, with\n"+
 "a small amount of steam coming off of them.  The floor is made of bits of \n"+
 "stone and rock mixed in with a little sand.  A light coming from the west is\n"+
 "almost acting as a beacon to those who travel through these passages.\n"+NORM;
       
items=({
     "passage", "A small are with plenty of room to walk",
     "walls", "The walls are very warm to the touch",
     "steam", "Just a little water evaporating from the water on the walls",
     "floor", "A well walked path from those who've traveled here in the past",
     "light", "A glowing light coming from the west end of the passage",
     "beacon", "A glowing light coming from the west end of the passage",
     "stone", "Pieces of stone makeup the walkway",
     "rock", "Small pieces of rock roll under your feet",
     "sand", "The main substance under your feet, making the floor look comfortable",
});
      
dest_dir=({
     "/players/snakespear/areas/Inferno/Rooms/room1_1","east",
     "/players/snakespear/areas/Inferno/Rooms/room1_3","west",
});
}

realm() { return "NT"; }

init() {
   ::init();
   add_action("search_room","search");
   add_action("listen","listen");
   add_action("smell","smell");
   add_action("feel","feel");
   this_player()->set_fight_area();
}

search_room(str) {
      if(!str) {
            write("What do you want to search?\n");
            return 1; }
   if(str == "sand") {
	    write("The sand sifts through your hands and you find nothing.\n");
	    return 1; }
	  else {
	    write("You search the "+str+" but find nothing.\n");
	    return 1; }  
}
smell(str) {
      if(!str) {
            write("What do you want to smell?\n");
            return 1; }
   if(str == "air") {
	    write("Thick, musky air that carries death in it's rapture.\n");
	    return 1; }
	  else {
	    write("You try to smell "+str+", but can't smell anything unusual.\n");
	    return 1; }  
}
listen(str) {
      if(!str) {
            write("What do you want to listen to?\n");
            return 1; }
   if(str == "noises") {
	    write("Agonizing screams and moans of someone in alot of pain.\n");
	    return 1; }
	  else {
	    write("You strain to hear the "+str+", but don't hear a thing.\n");
	    return 1; }  
}

