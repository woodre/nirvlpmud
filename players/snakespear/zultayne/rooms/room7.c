#include "/players/snakespear/closed/ansi.h"
inherit "room/room";
reset(arg) {
  if(!present("gargoyle")) {
   move_object(clone_object("/players/snakespear/zultayne/critters/malgar1.c"),this_object()); }
  if(arg) return;
set_light(1);
short_desc=GRY+"Zultayne Dungeon"+NORM;
long_desc=
 "  This is the dungeon of Zultayne.  The walls have chains attached\n"+
 "and braces that are connected to the chains.  There is water covering\n"+
 "the floor and a pile of bones in the corner.  A small cell is on one\n"+
 "wall and there is a bench on the adjacent wall.  Voices seem to echo\n"+
 "around this lost place.\n";

items=({
     "walls","Large rock walls that look very thick",
     "chains","Iron chains that hang loosely from the walls",
     "braces","Thick hand-cuff style braces used for holding prisoners",
     "water","Though it looks like water, it appears to be urine and sweat",
     "floor","A urine covered floor that spans the entire dungeon",
     "pile","A large pile of bones. Some of the bones still have flesh on them",
     "bones","Decaying bones from those that have died in this horrid place",
     "cell","A small retaining cell for holding prisoners before execution",
     "bench","A bulky wooden bench where the guards rest",
     "urine","What do you expect here?",
     "flesh","Decaying flesh that is ripped and torn",
});

dest_dir=({
     "/players/snakespear/zultayne/rooms/room5.c","up",
});
}

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
   if(str == "floor") {
	    write("You splash around in the fluid and get disgusted.\n");
	    return 1; }
	  else {
	    write("You search the "+str+" but find nothing.\n");
	    return 1; }  
}
smell(str) {
      if(!str) {
            write("What do you want to smell?\n");
            return 1; }
   if(str == "water") {
	    write("Ewww YUCK! It's a mixture of urine, feces and sweat!\n");
	    return 1; }
	  else {
	    write("You try to smell "+str+", but can't smell anything unusual.\n");
	    return 1; }  
}
listen(str) {
      if(!str) {
            write("What do you want to listen to?\n");
            return 1; }
   if(str == "voices") {
	    write("Crying from dissidents that have long since past on to the afterlife.\n");
	    return 1; }
	  else {
	    write("You strain to hear the "+str+", but never hear a thing.\n");
	    return 1; }  
}
