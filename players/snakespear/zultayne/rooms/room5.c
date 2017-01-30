inherit "room/room";
reset(arg){ 
   if(!arg) {
      
set_light(0);
short_desc="Corridor's end";
long_desc=
  "  This is where the corridor ends.  Banners are draped along the\n"+
  "walls.  There is a rock staircase on the northern side of the room\n"+
  "that leads up.  On the southern wall, there is a a ramp leading\n"+
  "down.  A strange green hue emits from the ramp.  Muffled sounds\n"+
  "are coming from below.\n";
      
items=({
     "banners", "Pictorial banners showing great battles with past foes",
     "walls", "Very dark, cold walls made from strong rocks",
     "staircase", "A crumbling stone staircase that winds upwards",
     "ramp", "Although very steep, the ramp looks negotiable",
     "hue", "Glowing green light comes from where the ramp leads",
     "rocks","Hard igneous rocks form a wall",
     "light","A faint glowing essence that is fading in and out",
});

dest_dir=({
     "/players/snakespear/zultayne/rooms/room6.c","up",
     "/players/snakespear/zultayne/rooms/room7.c","down",
     "/players/snakespear/zultayne/rooms/room1.c","east",
});

}  }

realm() { return "NT"; }

init() {
   ::init();
   add_action("search_room","search");
   add_action("listen","listen");
   add_action("smell","smell");
}
search_room(str) {
      if(!str) {
            write("What do you want to search?\n");
            return 1; }
   if(str == "staircase") {
	    write("You carefully search around the staircase, but find nothing.\n");
	    return 1; }
	  else {
	    write("You search the "+str+" but find nothing.\n");
	    return 1; }  
}
smell(str) {
      if(!str) {
            write("What do you want to smell?\n");
            return 1; }
   if(str == "walls") {
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
	    write("It sounds like an angered gargoyle below you.\n");
	    return 1; }
	  else {
	    write("You strain to hear the "+str+", but never hear a thing.\n");
	    return 1; }  
}
