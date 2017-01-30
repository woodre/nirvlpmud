#include <ansi.h>
inherit "room/room";

reset(arg){ 
  if(!arg){
set_light(0);
short_desc="A small storage room";
long_desc=
 "  This looks like some sort of a storage area.  There are many large\n"+
 "holes dug into the steep walls.  Beside the doorway, there is a line\n"+
 "of cabinets with shelves.  A chest sits in one corner and the others\n"+
 "have stuff piled up into them.  There is a ladder that leads up to a\n"+
 "strange light shining from above.\n";

items=({
    "holes","Large holes that used to store the food for the stronghold.",
    "walls","Hard rock walls that almost seem brittle to the touch",
    "doorway","A high arching doorway with a slime wood edge",
    "cabinets","Large cabinets that could hold large amounts of food",
    "shelves","Wooden shelves put in place to organize the food",
    "chest","A small chest that probably used to keep some treasure in it",
    "stuff","Looks like different kinds of rags used for clothing",
    "ladder","A old wooden ladder that extends through the ceiling",
    "light","A faint glow coming from above",
    "ceiling","A very strong looking structure that has a small opening in it",
    "rags","Old rags that are pieced together for clothing",
});

dest_dir=({
     "/players/snakespear/zultayne/rooms/room8.c","south",
     "/players/snakespear/zultayne/rooms/room10.c","up",
});
}  }

realm() { return "NT"; }

init() {
  ::init();
  add_action("search_room","search");
  add_action("smell","smell");
  add_action("listen","listen");
}

search_room(str) {
      if(!str) {
            write("What do you want to search?\n");
            return 1; }
   if(str == "cabinets") {
	    write("You rummage around in the cabinets and find nothing.\n");
	    return 1; }
	  else {
	    write("You search the "+str+" but find nothing.\n");
	    return 1; }  
}
smell(str) {
      if(!str) {
            write("What do you want to smell?\n");
            return 1; }
   if(str == "chest") {
	    write("Ahh.. the sweet smell of money, although there is none.\n");
	    return 1; }
	  else {
	    write("You try to smell "+str+", but can't smell anything unusual.\n");
	    return 1; }  
}
listen(str) {
      if(!str) {
            write("What do you want to listen to?\n");
            return 1; }
   if(str == "above") {
	    write("Oh my, that sounds like a angered Gargoyle!\n");
	    return 1; }
	  else {
	    write("You strain to hear the "+str+", but never hear a thing.\n");
	    return 1; }  
}

