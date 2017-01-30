inherit "room/room";
reset(arg){
   if(!arg){
set_light(0);
short_desc="East corridor";
long_desc=
 "  This is a long, dark corridor leading east from the foyer.  The\n"+
 "ceiling is very low and the walls are slender.  Darkness enshrouds\n"+
 "everything.  The room is very cold and dark.  Sounds seem to come\n"+
 "from the east.\n";

items=({
 "ceiling","You struggle to view the ceiling, but the darkness is too thick",
 "walls","Your hands reach out and feel the smooth walls",
 "darkness","It's pitch black and very dense",
 "corridor","A slender hallway with steep sides.",
 "walls","Tall, dark and moldy stone walls",
 "hallway","A very dark corridor",
});

dest_dir=({
   "/players/snakespear/zultayne/rooms/foyer.c","west",
   "/players/snakespear/zultayne/rooms/room8.c","east",
});

}  }

realm() { return "NT"; }

init() {
  ::init();
  add_action("smell","smell");
  add_action("search_room","search");
  add_action("listen","listen");
}

search_room(str) {
      if(!str) {
            write("What do you want to search?\n");
            return 1; }
   if(str == "room") {
	    write("You fumble around in the darkness and find nothing.\n");
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
	    write("You take a deep breath and smell mold.\n");
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
	    write("You can hear soft whimpering and crying to the east.\n");
	    return 1; }
	  else {
	    write("You strain to hear the "+str+", but never hear a thing.\n");
	    return 1; }  
}