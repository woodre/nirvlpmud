inherit "room/room";

reset(arg){ 
   if(!present("gargoyle")) {
     move_object(clone_object("/players/snakespear/zultayne/critters/jasgar.c"),this_object());
   }
if(arg) return;
set_light(1);
short_desc="Circle Room";
long_desc=
    "  This is the Circle Room.  The Gargoyles have their meetings here.\n"+
    "The room's name comes from the large round table that takes up the\n"+
    "majority of this chamber.  There is nothing on the walls except a\n"+
    "few little paintings of Gargoyles in battle.  A strong feeling is\n"+
    "is felt throughout this room.  There is also a loud humming.\n";

items=({
    "table","A stone table that is round and looks very old",
    "walls","Plain stone walls with very few abnormalities",
    "paintings","Paintings of old Gargoyles that were strong in battle",
});

dest_dir=({
    "/players/snakespear/zultayne/rooms/room2.c","west",
});
}

realm() { return "NT"; }

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
      if(str == "paintings") {
	    write("After making a mess, you find nothing.\n");
	    return 1; }
      else {
	    write("You search the "+str+" but find nothing.\n");
	    return 1; }  
}
smell(str) {
      if(!str) {
            write("What do you want to smell?\n");
            return 1; }
      if(str == "table") {
	    write("After smelling the table, you think you might be going insane.\n");
	    return 1; }
      else {
	    write("You try to smell "+str+", but can't smell anything unusual.\n");
	    return 1; }  
}
listen(str) {
      if(!str) {
            write("What do you want to listen to?\n");
            return 1; }
      if(str == "humming") {
	    write("It sounds like a war chant..\n");
	    return 1; }
      else {
	    write("You strain to hear the "+str+", but never hear a thing.\n");
	    return 1; }  
}
feel(str) {
      if(!str) {
        write("What are you trying to feel?\n");
        return 1; }
      if(str == "feeling") {
        write("A frigid sense of power overcomes you!\n");
        return 1; }
      else {
        write("You feel "+str+" and are completely uninspired\n");
        return 1; }
}
