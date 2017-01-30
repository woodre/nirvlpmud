inherit "/players/jenny/room";
#include "/players/jenny/define.h"
int door, inuse;
realm() { return "NT"; }
reset(arg) {
if(!present("lewis"))  {
if(random(100) < 44) {
MOCO("/players/jenny/wings/mobs/staff/lewis.c"),TO); }}
    if(arg) return;
    set_light(1);
     set_search(BOLD+"You notice some nice pictures on the wall."+NORM);
long_desc=
"The hallway on the executive level is wider, and looks classier,\n"+      
"than the other hallways throughout the arena.  The floor is\n"+
"covered with a plush red carpet.  The cream colored walls are\n"+
"decorated with plenty of pictures.  One side of the hall has a\n"+
"door leading to the stairwell, an elevator, with a button next\n"+
"to it, is on the other side.\n";
items = ({
"door","This is a door leading to a stairwell.  You could enter the door\n"+
             "and use the stairs",
"floor","The floor is covered with thick red carpet",
"carpet","The carpet is thick and dark red",
"button","A red plastic button, you can push it to get the elevator",
"walls","The cream colored walls are decorated with lots of pictures",
"elevator","This is an elevator which can take you down to the media\n"+
               "area, concourse, and ice level.  You can enter the elevator",
"pictures","Here you see pictures of James and Bruce Norris, Mike Ilitch,\n"+
                 "and Jack Adams",

});

dest_dir = ({
"/players/jenny/wings/rooms/s4","north",
"/players/jenny/wings/rooms/s2","east",
});
}
short() {
return BOLD+WHT+"A Hallway"+NORM; }
init() { 
    ::init(); 
   this_player()->set_fight_area();
add_action("stairwell","enter");
add_action("button","push");
add_action("button","press");
add_action("elevator","enter");
}
stairwell(arg) {
if(!arg) {return 0;}
if(arg == "stairwell" || arg == "door" || arg == "the door") {
TP->move_player("through the door#players/jenny/wings/rooms/stairs3.c");
return 1; }}
button(arg) {
if(!arg) { notify_fail("What do you want to push?\n"); }
if(arg == "button") {
if(inuse > 1) { write("The elevator is currently in use.  Try again in a few seconds.\n"); return 1;}
write("You push the button.\n");
call_out("button2",4);
inuse = 5;
call_other("/players/jenny/wings/rooms/i2.c","inuse");
call_other("/players/jenny/wings/rooms/2h8.c","inuse");
call_other("/players/jenny/wings/rooms/c2.c","inuse");
call_other("/players/jenny/wings/rooms/elevator.c","setbusy");
tell_room("/players/jenny/wings/rooms/elevator.c","The elevator doors close and it starts to move.\n");
return 1; }} 
button2() {
   tell_room("/players/jenny/wings/rooms/elevator.c","The elevator doors open.\n");
   tell_room("/players/jenny/wings/rooms/s1.c","The elevator doors open.\n");
   call_other("/players/jenny/wings/rooms/elevator.c","setfloor4");
call_other("/players/jenny/wings/rooms/i2.c","inuse2");
call_other("/players/jenny/wings/rooms/c2.c","inuse2");
call_other("/players/jenny/wings/rooms/s1.c","inuse2");
call_other("/players/jenny/wings/rooms/2h8.c","inuse2");
   door = 3;
   return 1; }
elevator(arg) {
if(!arg) {return 0;}
if(arg == "elevator" || arg == "the elevator") {
if(door < 1) {
write("The elevator doors are closed.\n");
return 1;}
TP->move_player("into the elevator#players/jenny/wings/rooms/elevator.c");
return 1; }}
inuse() {
inuse = 5;
return 1; }
door() {
door = 0;
return 1;}
inuse2() {
inuse = 0;
return 1;}
