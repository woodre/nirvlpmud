inherit "room/room";

reset(arg){
   
   if(!arg){
      
set_light(0);
short_desc="A dark corridor";
long_desc=
"  This is a long, dark corridor leading away from the foyer.\n"+
"The walls glisten with a moist substance.  There are several\n"+
"nicks in the high arching walls.  Looking foward down the\n"+
"corridor, nothing can be seen, but more darkness.  There are\n"+
"echos, bouncing around throughout.\n";
      
items=({
     "walls", "Nicked from battle, the walls are high arching and seem endless",
     "substance", "A dark crimson fluid, possibly blood from past battles",
     "darkness", "It's too dark",
     "nicks", "These marks must have come from weapons hitting the walls in battle",
     "blood","Thick, dried blood spread across the walls",
     "marks","Battle nicks from past wars",
});
      
dest_dir=({
     "/players/snakespear/zultayne/rooms/room5.c","west",
     "/players/snakespear/zultayne/rooms/foyer.c","east",
});
      
}  }

realm() { return "NT"; }

init()  {
   ::init();
   add_action("search_room","search");
   add_action("smell","smell");
   add_action("listen","listen");
}

search_room(str) {
      if(!str) {
            write("What do you want to search?\n");
            return 1; }
   if(str == "darkness") {
	    write("You fumble around in the darkness and come up empty.\n");
	    return 1; }
	  else {
	    write("You search the "+str+" but find nothing.\n");
	    return 1; }  
}
smell(str) {
      if(!str) {
            write("What do you want to smell?\n");
            return 1; }
   if(str == "blood") {
	    write("You smell the blood and gag from the stench!\n");
	    return 1; }
	  else {
	    write("You try to smell "+str+", but can't smell anything unusual.\n");
	    return 1; }  
}
listen(str) {
      if(!str) {
            write("What do you want to listen to?\n");
            return 1; }
   if(str == "echos") {
	    write("You can hear movement from the corridor.\n");
	    return 1; }
	  else {
	    write("You strain to hear the "+str+", but never hear a thing.\n");
	    return 1; }  
}
