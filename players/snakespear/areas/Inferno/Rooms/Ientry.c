#include "/players/snakespear/closed/ansi.h"
inherit "room/room";

reset(arg) {
   if(!present("messenger")) {
     move_object(clone_object("/players/snakespear/areas/Inferno/Critters/msgent.c"),this_object()); 
   }
   if(arg) return;   
set_light(2);
short_desc=RED+"Inferno"+NORM;
long_desc=RED+
 "  The opening of this large cave is dark and moist.  Heat nips at your feet\n"+
 "seemingly coming from deeper inside the cave.  Water dribbles slowly down\n"+
 "the inside of the cold walls.  Sorrowful moans can be heard deeper inside.\n"+
 "Strange dragmarks coming out of the cave are filled with blood.\n"+NORM;
       
items=({
     "cave", "The mouth of a large cave, leading into darkness",
     "opening", "A large cave leading somewhere with much warmth",
     "water", "Cold, trickling water slides down the sides of the cave",
     "walls", "Smoothly cut walls, most likely a natural creation",
     "dragmarks","Blood filled grooves from quickly escaping prisoners",
     "blood","Bright redish colored blood that looks very fresh",
});
      
dest_dir=({
     "/players/snakespear/tools/hub.c","leave",
     "/players/snakespear/areas/Inferno/Rooms/room1_1","enter",
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
   if(str == "blood") {
	    write("Are you crazy! Messing with blood without gloves is dangerous!\n");
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
   if(str == "moans") {
	    write("Agonizing screams and moans of someone in alot of pain.\n");
	    return 1; }
	  else {
	    write("You strain to hear the "+str+", but don't hear a thing.\n");
	    return 1; }  
}

