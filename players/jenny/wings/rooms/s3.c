inherit "/players/jenny/room";
#include "/players/jenny/define.h"
realm() { return "NT"; }
int door;
reset(arg) {
door = 1;
    if(arg) return;
    set_light(1);
     set_search(BOLD+"You notice some nice pictures on the wall."+NORM);
long_desc=
"The hallway on the executive level is wider, and looks classier,\n"+      
"than the other hallways throughout the arena.  The floor is\n"+
"covered with a plush red carpet, and the cream colored walls are\n"+
"decorated with plenty of pictures.  There is a set of double doors\n"+
"to the north and an office to the south.\n";
items = ({
"office","The office of the senior vice president is to the south",
"doors","A set of wooden doors with elaborate carvings and a golden\n"+
              "plaque.  You could enter them",
"plaque","A golden plaque with the words 'ALUMNI ROOM' printed on it",
"carvings","Many beautiful designs are carved into the wood",
"floor","The floor is covered with thick red carpet",
"door","A set of wooden doors with elaborate carvings and a golden\n"+
              "plaque.  You could enter them",
"carpet","The carpet is thick and dark red",
"walls","The cream colored walls are decorated with lots of pictures",
"pictures","Here you see pictures of Larry Aurie, Ebenezer Goodfellow, Syd\n"+
                 "Howe, and Jack Stewart",	
});

dest_dir = ({
"/players/jenny/wings/rooms/vp","south",
"/players/jenny/wings/rooms/s2","west",
});
}
short() {
return BOLD+WHT+"A Hallway"+NORM; }
init() { 
    ::init(); 
   this_player()->set_fight_area();
add_action("door","enter");
add_action("open","open");
add_action("close","close");
}
door(arg) { 
if(!arg) { return 0; }
if(arg == "door" | arg == "the door" || arg == "doors" || arg == "the doors")  {
if(door == 1) {write("You must open the door first.\n");
return 1;}
else {
TP->move_player("through the door#players/jenny/wings/rooms/alumni1.c");
return 1; }}}
open(arg) { 
if(!arg) { return 0; }
if(arg == "door" | arg == "the door" || arg == "doors" || arg == "the doors")  {
write("You open the door.\n");
say(TPN+" opens the door.\n");
door = 2;
return 1; }}
close(arg) { 
if(!arg) { return 0; }
if(arg == "door" | arg == "the door" || arg == "doors" || arg == "the doors")  {
write("You close the door.\n");
say(TPN+" closes the door.\n");
door = 1;
return 1; }}
