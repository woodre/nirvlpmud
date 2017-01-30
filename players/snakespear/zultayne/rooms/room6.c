inherit "room/room";
reset(arg){
   if(!present("gargoyle")) {
move_object(clone_object("/players/snakespear/zultayne/critters/zirgar.c"),this_object()); }
   if(!arg) {
set_light(0);
short_desc="Top of west tower";
long_desc=
 "  In the top of this tall, stone tower there is a window and a small\n"+
 "lookout.  The air here is very thin and makes it a little hard to\n"+
 "breath.  A small desk sits here facing the window.  This might be\n"+
 "a good spot to take a break and rest.  There is a staircase\n"+
 "leading back down the tower.\n";
      
items=({
    "window","A wide opening in the west wall.  You can see the dark\n"+
             "forest way beneath the tower and the small clouds hovering\n"+
             "just above the trees",
    "lookout","A smaller window.  Gazing out you see a nice view of the\n"+
              "stronghold and the dark forest around it",
    "desk","A little desk with some writing utensils on it.",
    "staircase","An old looking stone staircase leading down",
    "wall","A damp rock wall",
    "forest","Large pine trees fill up the forest",
    "tower","You are standing in it!",
    "stronghold","A strong looking castle that is run down",
    "utencils","A long feather and ink pot",
    "feather","A long feather that is used for writing",
    "ink","Dark fluid, it almost looks like old blood",
});

dest_dir=({
    "/players/snakespear/zultayne/rooms/room5.c","down",
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
   if(str == "desk") {
	    write("You see some old feathers and ink, but nothing useful.\n");
	    return 1; }
	  else {
	    write("You search the "+str+" but find nothing.\n");
	    return 1; }  
}
smell(str) {
      if(!str) {
            write("What do you want to smell?\n");
            return 1; }
   if(str == "ink") {
	    write("Man this stuff stinks!\n");
	    return 1; }
	  else {
	    write("You try to smell "+str+", but can't smell anything unusual.\n");
	    return 1; }  
}
listen(str) {
      if(!str) {
            write("What do you want to listen to?\n");
            return 1; }
   if(str == "air") {
	    write("It's carrying the pitiful sounds of a baby gargoyle.\n");
	    return 1; }
	  else {
	    write("You strain to hear the "+str+", but never hear a thing.\n");
	    return 1; }  
}
