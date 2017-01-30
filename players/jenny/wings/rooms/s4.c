inherit "/players/jenny/room";
#include "/players/jenny/define.h"
int door;
realm() { return "NT"; }
reset(arg) {
door = 1;
    if(arg) return;
    set_light(1);
     set_search(BOLD+"You notice some nice pictures on the wall."+NORM);
     set_listen(BOLD+"You hear chattering behind the doors"+NORM);
long_desc=
"The hallway on the executive level is wider, and looks classier,\n"+      
"than the other hallways throughout the arena.  The floor is\n"+
"covered with a plush red carpet, and the cream colored walls are\n"+
"decorated with plenty of pictures.  There is a door to the west\n"+
"with a golden plaque on it.\n";
items = ({
"door","A set of wooden double doors with a golden plaque on them.  You\n"+
            "can enter the doors if you wish",
"doors","A set of wooden double doors with a golden plaque on them.  You\n"+
            "can enter the doors if you wish",
"floor","The floor is covered with thick red carpet",
"carpet","The carpet is thick and dark red",
"walls","The cream colored walls are decorated with lots of pictures",
"plaque","A golden plaque with the words 'OWNERS SUITE' printed\n"+
               "on it",
"pictures","Here you see pictures of Gordie Howe, Ted Lindsay, and\n"+
                 "Sid Abel, along with a picture of old Olympia Stadium",	
});

dest_dir = ({
"/players/jenny/wings/rooms/s1","south",
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
TP->move_player("through the door#players/jenny/wings/rooms/osuite.c");
return 1; }}}
open(arg) { 
if(!arg) { return 0; }
if(arg == "door" | arg == "the door")  {
write("You open the door.\n");
say(TPN+" opens the door.\n");
door = 2;
return 1; }}
close(arg) { 
if(!arg) { return 0; }
if(arg == "door" | arg == "the door")  {
write("You close the door.\n");
say(TPN+" closes the door.\n");
door = 1;
return 1; }}
