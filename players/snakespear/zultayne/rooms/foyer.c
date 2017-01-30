#include "/players/snakespear/closed/ansi.h"
inherit "room/room";

reset(arg) {
   if(!present("gargoyle")) {
     move_object(clone_object("/players/snakespear/zultayne/critters/kgar.c"),this_object());
   }
   if(!present("sign")) {
     move_object(clone_object("/players/snakespear/zultayne/zsign.c"),this_object()); 
   }
   if(!present("messenger")) {
     move_object(clone_object("/players/snakespear/zultayne/critters/msgfoyer.c"),this_object()); 
   }
   if(arg) return;   
set_light(1);
short_desc=(BOLD+"Foyer "+NORM+"of "+GRY+"Zultayne "+NORM);
long_desc=
 "  This is the entrance foyer to Zultayne, the Gargoyle Stronghold.\n"+
 "The torches on the walls cast a flickering light across the room.\n"+
 "The low light causes many shadows to arise from around the room.\n"+
 "Corridors lead in several directions, although they seem to be\n"+
 "filled with darkness.  Nothing seems to be on the ground, except\n"+
 "glimmering particles that give off enough light to allow sight.\n";
      
items=({
     "darkness", "Extreme nothingness....",
     "corridors", "Twin hallways leading in opposite directions into the next rooms",
     "walls", "Cold and damp, rising high above you",
     "shadows", "Creepy shadows move slowly around the walls",
     "ground", "A hard smooth surface, scattered with shining particles",
     "torches", "Small sconces burn with eternal flames",
     "room", "A chilling room with darkness all around",
     "particles", "Little glowing bits of kunzite",
     "hallways","Dark corridors going into the unknown",
     "particles","Small bits of kunzite",
     "flames","Bright light, lighting the area",
     "sconces","Small holders for the torches",
     "kunzite","Bright stone that gives off light",
});
      
dest_dir=({
     "/players/snakespear/zultayne/rooms/room1","west",
     "/players/snakespear/zultayne/rooms/room2","north",
     "/players/snakespear/zultayne/rooms/room3.c","east",
     "/players/snakespear/zultayne/rooms/room4.c","up",
});
}

realm() { return "NT"; }

init() {
   ::init();
   add_action("search_room","search");
   add_action("down","down");
   add_action("listen","listen");
   add_action("smell","smell");
}
search_room(str) {
   if(!str) {
            write("What do you want to search?\n");
            return 1; }
   if(str == "shadows") {
	    write("You search the shadows and find a door leading 'down'.\n");
	    return 1; }
	  else {
	    write("You search the "+str+" but find nothing.\n");
	    return 1; }  
}   
down() {
   call_other(this_player(),"move_player","into a hole#players/snakespear/zultayne/rooms/hole.c");
   return 1;
}
smell(str) {
    if(!str) {
            write("What do you want to smell?\n");
            return 1; }
   if(str == "air") {
	    write("You smell the musky air and gag!\n");
	    return 1; }
	  else {
	    write("You smell the "+str+" but notice nothing.\n");
	    return 1; }  
}   
listen(str) {
   if(!str) {
            write("What do you want to listen to?\n");
            return 1; }
   if(str == "echos") {
	    write("You hear the hollowed silence and shiver.\n");
	    return 1; }
	  else {
	    write("You listen to the "+str+" but hear nothing.\n");
	    return 1; }  
}   
