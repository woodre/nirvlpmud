#include "/players/snakespear/closed/ansi.h"

inherit "room/room";
reset(arg){
 if(!present("gargoyle")) {
     move_object(clone_object("/players/snakespear/zultayne/critters/suggar.c"),this_object());
 }
 if(arg) return;
set_light(1);
short_desc=HIB+"Watch Tower"+NORM; 
long_desc=
 "  This is the highest tower in the stronghold.  The tower is erected\n"+
 "high above the foyer.  There is almost a full view of the surrounding\n"+
 "forest from the wide openings here.  The air is chilly and it flows\n"+
 "through the tower swiftly.  A small stool sits on the floor.  Sounds\n"+
 "can be heard coming from the forest.\n";

items=({
   "view","A wide angle glance of all the lands around the stronghold",
   "openings","Many large holes line the walls of the tower",
   "stool","A hard stool made from a petrified tree stump",
   "forest","A vast forest of pine trees and many animals",
   "holes","Window like openings along the walls",
   "stump","A stool like object",
   "tower","You are standing inside it, how do you expect to see it?",
   "lands","A variety of landscapes with much forestry surrounds Zultayne",
   "trees","Tall, old pines that sway with the winds",
});

dest_dir=({
   "/players/snakespear/zultayne/rooms/foyer.c","down",
});

}

init() {
  ::init();
  add_action("search_room","search");
  add_action("listen","listen");
  add_action("smell","smell");
  add_action("feel","feel");
}

search_room(str) {
      if(!str) {
            write("What do you want to search?\n");
            return 1; }
   if(str == "openings") {
	    write("You feel around the openings and can't find anything.\n");
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
	    write("You take a deep breath, inhaling the piney smell.\n");
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
	    write("You hear sounds of a sad baby gargoyle and small animals.\n");
	    return 1; }
	  else {
	    write("You strain to hear the "+str+", but never hear a thing.\n");
	    return 1; }  
}
feel(str) {
  if(!str) {
    write("What are you trying to feel?\n");
    return 1; }
  if(str == "air") { 
     write("Something taps you on the shoulder....\n\n"+
           "You turn quickly to find out what it was!!\n\n"+
           "You see something move....\n\n"+
           "You twist to see it!\n\n"+
           "Your body tenses and fear overcomes you!\n\n"+
           "All movement stops, all is calm....\n\n"+
           "You lost it....\n\n"+
           "It's gone.\n\n");
     return 1; }
  else {
     write("You attempt to feel "+str+", but nothing happens.\n");
     return 1; }
}
    