#include "/players/snakespear/closed/ansi.h"
inherit "room/room";

reset(arg) {
   if(arg) return;   
set_light(2);
short_desc=(RED+"Inferno"+NORM);
long_desc=RED+
 "  Tunnels lead three ways from this central feeling location.  Each tunnel\n"+
 "appears very dark and quite warm.  Sounds echo from every direction. There\n"+
 "are several rock formations lining the room.  The ceiling is high, but not\n"+
 "too very far above, leaving little headroom.\n"+NORM;
       
items=({
     "tunnels", "Dark passageways leading into every direction",
     "formations", "Stalagmites and stalagtites have formed over the years",
     "ceiling", "Just another wall to the cave, just happens to be above you",
});
      
dest_dir=({
     "/players/snakespear/areas/Inferno/Rooms/room1_2","west",
     "/players/snakespear/areas/Inferno/Rooms/room1_4","east",
     "/players/snakespear/areas/Inferno/Rooms/Ientry.c","south",
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
   if(str == "room") {
	    write("Nothing important or valueable seems to be here.\n");
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
	    write("Thick, musky air that carries death in it's wings.\n");
	    return 1; }
	  else {
	    write("You try to smell "+str+", but can't smell anything unusual.\n");
	    return 1; }  
}
listen(str) {
      if(!str) {
            write("What do you want to listen to?\n");
            return 1; }
   if(str == "sounds") {
	    write("Agonizing screams and moans of someone in alot of pain.\n");
	    return 1; }
	  else {
	    write("You strain to hear the "+str+", but don't hear a thing.\n");
	    return 1; }  
}

