inherit "room/room";

reset(arg){
if(!arg){

set_light(0);
short_desc="Training Room";
long_desc=
    "  This plain looking room is where the gargoyles of Zultayne come\n"+
    "to get training for flight, weapon handling, and combat maneuvers.\n"+
    "The walls are lined with many weapons, although the gargoyles are\n"+
    "better known for their excellent hand to hand combat skills.  There\n"+
    "is a tunnel leading to another room and corridors leading in each\n"+
    "direction to more rooms of the stronghold.\n";

items=({
    "walls", "They are covered with swords, maces and polearms",
    "room", "It's too dark",
    "weapons", "Heavily decorated swords, maces and polearms gleam from loving care",
    "tunnel", "A dark corridor leading into blackness",
    "corridors", "Emtpy looking hallways guiding to connecting rooms",
    "swords","A good variety of long bladed weapons",
    "maces","A good variety of short staffs with blades on the end",
    "polearms","A good variety of long staffs with blades on the ends",
    "blackness","Who knows.. maybe you should check to see??",
    "rooms","Rooms that are very dark",
});

dest_dir=({
    "/players/snakespear/zultayne/rooms/room11.c","west",
    "/players/snakespear/zultayne/rooms/room12.c","east",
    "/players/snakespear/zultayne/rooms/portal.c","tunnel",
    "/players/snakespear/zultayne/rooms/foyer.c","south",
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
   if(str == "walls") {
	    write("You feel around the walls and find nothing of interest.\n");
	    return 1; }
	  else {
	    write("You search the "+str+" but find nothing.\n");
	    return 1; }  
}
smell(str) {
      if(!str) {
            write("What do you want to smell?\n");
            return 1; }
   if(str == "room") {
	    write("You smell sweat and dirt.   YUCK!!\n");
	    return 1; }
	  else {
	    write("You try to smell "+str+", but can't smell anything unusual.\n");
	    return 1; }  
}
listen(str) {
      if(!str) {
            write("What do you want to listen to?\n");
            return 1; }
   if(str == "tunnel") {
	    write("You can hear alot of noise, but can't decipher any of it.\n");
	    return 1; }
	  else {
	    write("You strain to hear the "+str+", but never hear a thing.\n");
	    return 1; }  
}
