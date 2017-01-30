inherit "/players/jenny/room";
#include "/players/jenny/define.h"
int floor, busy;
realm() { return "NT"; }
reset(arg) {
    if(arg) return;
    set_light(1);
set_listen(BOLD+"Bland elevator music is coming out of the speakers."+NORM);
set_smell(BOLD+"The elevator has a slightly unpleasant odor."+NORM);
long_desc=
"This is a pretty large elevator, about 6x10 feet.  The floor is grey\n"+      
"tile, and the walls are wood paneling, with a hand rail going all the\n"+
"way around.  Next to the door is a panel with several buttons on\n"+
"it.\n";
items = ({
"panel","A metal panel with several plastic buttons on it",
"buttons","There is a button for each floor.  You can push 1,2,3,or 4",
"walls","The walls of the elevator are made out of wood paneling",
"paneling","This is just cheap wood paneling",
"floor","The floor is made up of soft grey tile.  It is dirty and stained",
"tile","The elevator floor is made up of soft grey tile",
"rail","A brass hand rail goes all the way around the elevator",     
"door","A silver metal door that opens in the middle",
});
/* will be overridden by the add_action */
dest_dir = ({
"/players/jenny/wings/rooms/i2","out",
});
}
short() {
return BOLD+"Elevator"+NORM; }
init() { 
    ::init(); 
   this_player()->set_fight_area();
   add_action("getout","push");
   add_action("byebye","out");
   add_action("getout","press");
}
getout(arg) {
if(!arg) { notify_fail("Push a button, 1-4.\n"); }
if(busy > 1) { write("You push the button, but nothing happens.\n"); return 1; }
if(arg == "1") {
if(floor == 1) {write("You are already on the first floor.\n"); return 1; }
write("You push the button for the first floor.\n");
busy = 2;
floor = 1;
moving();
return 1;}
if(arg == "2") {
if(floor == 2) {write("You are already on the second floor.\n"); return 1; }
write("You push the button for the second floor.\n");
busy = 2;
floor = 2;
moving();
return 1;}
if(arg == "3") {
if(floor == 3) {write("You are already on the third floor.\n"); return 1; }
write("You push the button for the third floor.\n");
busy = 2;
floor = 3;
moving();
return 1;}
if(arg == "4") {
if(floor == 4) {write("You are already on the fourth floor.\n"); return 1; }
write("You push the button for the fourth floor.\n");
busy = 2;
floor = 4;
moving();
return 1;}}
moving() { 
whydidimakeadamnelevator();
call_out("moving2",3);
call_out("moving3",8);
call_out("moving4",11);
   return 1; }
moving2() {
   tell_room("/players/jenny/wings/rooms/elevator.c","The elevator doors close and it starts to move.\n");
   return 1; }
moving3() {
   tell_room("/players/jenny/wings/rooms/elevator.c","The elevator comes to a stop.\n");
   return 1; }
moving4() {
   tell_room("/players/jenny/wings/rooms/elevator.c","The elevator doors open.\n");
   busy = 0;
call_other("/players/jenny/wings/rooms/i2.c","inuse2");
call_other("/players/jenny/wings/rooms/c2.c","inuse2");
call_other("/players/jenny/wings/rooms/s1.c","inuse2");
call_other("/players/jenny/wings/rooms/2h8.c","inuse2");
   return 1; }
setfloor1() {
floor = 1;
busy = 0;
return 1;}
setfloor2() {
floor = 2;
busy = 0;
return 1;}
setfloor3() {
floor = 3;
busy = 0;
return 1;}
setfloor4() {
floor = 4;
busy = 0;
return 1; }
byebye() {
if(busy > 1) { write("You are not at your floor yet.\n"); return 1; }
/* floor should never = 0, but just in case */
if(floor == 0) {
TP->move_player("out#players/jenny/wings/rooms/i2.c");
write_file("/players/jenny/logs/wingselevator", ""+TPRN+" caused an error on "+ctime()+"\n");
return 1; }
if(floor == 1) {
TP->move_player("out#players/jenny/wings/rooms/i2.c");
return 1; }
if(floor == 2) {
TP->move_player("out#players/jenny/wings/rooms/c2.c");
return 1; }
if(floor == 3) {
TP->move_player("out#players/jenny/wings/rooms/2h8.c");
return 1; }
if(floor == 4) {
TP->move_player("out#players/jenny/wings/rooms/s1.c");
return 1; }}
setbusy() {
busy = 2;
return 1; }
whydidimakeadamnelevator() {
call_other("/players/jenny/wings/rooms/i2.c","door");
call_other("/players/jenny/wings/rooms/c2.c","door");
call_other("/players/jenny/wings/rooms/s1.c","door");
call_other("/players/jenny/wings/rooms/2h8.c","door");
return 1;}
