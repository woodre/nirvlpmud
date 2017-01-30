inherit "/players/jenny/room";
#include "/players/jenny/define.h"
int inuse, door;
realm() { return "NT"; }
reset(arg) {
    if(arg) return;
    set_light(1);
set_search(BOLD+"You notice an elevator."+NORM);
long_desc=
"This is a narrow hallway which wraps around the upper section\n"+      
"of Joe Louis Arena.  A thin red carpet covers the cement floor,\n"+
"and the plain tile walls look very dirty.  This hallway, which\n"+
"is used to provide access to the various media booths, makes\n"+
"a sharp curve around the far end of the arena.  There is an\n"+
"elevator along the wall, and a button next to it.\n";

items = ({
"hallway","This hallway is used to provide access to the television and radio\n"+
                  "announcer's booths, as well as cameraman's booths, and the press box",
"carpet","This is cheap thin red carpet which is very worn.  It has many dark\n"+
               "stains from spilled food",
"stains","Many dark stains which are splattered on the carpet",
"button","A plastic red button.  You can push it to get the elevator",
"elevator","This is an elevator which can take you up to the suites, or\n"+
                 "down to the concourse or ice level.  You can enter the\n"+
                 "elevator",
"floor","A hard cement floor which is covered with cheap red carpet",
"walls","These walls are lined with plain white tile.  They could stand to\n"+
               "be washed a little more often",
"booths","Small booths that provide a view of the game, and a place for\n"+
               "the media to work",
});

dest_dir = ({
"/players/jenny/wings/rooms/pa","south",
"/players/jenny/wings/rooms/2h7","southwest",
"/players/jenny/wings/rooms/2h1","southeast",
});
}
short() {
return BOLD+WHT+"A hallway"+NORM; }
init() { 
    ::init(); 
   this_player()->set_fight_area();
   add_action("button","push");
   add_action("button","press");
   add_action("elevator","enter");
}
button(arg) {
if(!arg) { notify_fail("What do you want to push?\n"); }
if(arg == "button") {
if(inuse > 1) { write("The elevator is currently in use.  Try again in a few seconds.\n"); return 1;}
write("You push the button.\n");
call_out("button2",4);
inuse = 5;
call_other("/players/jenny/wings/rooms/i2.c","inuse");
call_other("/players/jenny/wings/rooms/c2.c","inuse");
call_other("/players/jenny/wings/rooms/s1.c","inuse");
call_other("/players/jenny/wings/rooms/elevator.c","setbusy");
tell_room("/players/jenny/wings/rooms/elevator.c","The elevator doors close and it starts to move.\n");
return 1; }} 
button2() {
   tell_room("/players/jenny/wings/rooms/elevator.c","The elevator doors open.\n");
   tell_room("/players/jenny/wings/rooms/2h8.c","The elevator doors open.\n");
   call_other("/players/jenny/wings/rooms/elevator.c","setfloor3");
call_other("/players/jenny/wings/rooms/i2.c","inuse2");
call_other("/players/jenny/wings/rooms/c2.c","inuse2");
call_other("/players/jenny/wings/rooms/s1.c","inuse2");
call_other("/players/jenny/wings/rooms/2h8.c","inuse2");
   door = 3;
   return 1; }
elevator() {
if(door < 1) {
write("The elevator doors are closed.\n");
return 1;}
TP->move_player("into the elevator#players/jenny/wings/rooms/elevator.c");
return 1; }
inuse() {
inuse = 5;
return 1; }
door() {
door = 0;
return 1;}
inuse2() {
inuse = 0;
return 1;}
