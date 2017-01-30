inherit "/players/stark/room";
#include "/players/stark/defs.h"
object ob;
object ob2;
int floorlvl = 1;
int dooropen = 1;
int moving = 0;

reset(arg){
    if(arg) return;
    set_light(1);
    set_listen("The cables groan ever so slightly from the stress.");
    set_smell("The poorly circulated air leaves it smelling a bit dank.");
    set_search("You find a set of buttons to push.");
    short_desc="An Elevator";
    long_desc=
"   The elevator is an intricate steel cage.  There is a cable \n"+
"connected at the top of the cage.  The walls of the shaft grip the \n"+
"cage smoothly.  There is a sliding door made of interlocking metal \n"+
"bars.  There are some buttons by the door.\n";

items=({"cage","You are capsulated in a steel cage",
"cable","The cable looks strong and secure",
"walls","A pattern of roses climbs the walls",
"shaft","The shaft made to hold this elevator",
"door","The door must be closed to operate the elevator",
"buttons","There are three buttons to choose: 1, 2, and 3"
});

}

init() {
::init();
add_action("open","open");
add_action("close","close");
add_action("out","out");
add_action("push","push");
ob = "/players/stark/utena/room/elevator2.c";
}

query_floorlvl() { return floorlvl; }
query_dooropen() { return dooropen; }
query_moving() { return moving; }
set_floorlvl(arg) { floorlvl = arg; }
set_dooropen(arg) { dooropen = arg; }
set_moving(arg) { moving = arg; }

open(arg) {
if(!arg) {
write("Open what?\n");
return 1;
 }
if(arg == "door") {
if(dooropen == 1) {
write("The door is already open.\n");
return 1;
 }
if(moving == 1) {
write("You must wait until the elevator stops.\n");
return 1;
 }
write("You pull open the door.\n");
dooropen = 1;
return 1;
 }
}

close(arg) {
if(!arg) {
write("Close what?\n");
return 1;
 }
if(arg == "door") {
if(dooropen == 0) {
write("The door is already closed.\n");
return 1;
 }
write("You pull the door closed.\n");
dooropen = 0;
return 1;
 }
}

door_open_msg(){
tell_room(ob2, "The light goes off and the door opens.\n");
return 1; }

door_close_check() {
if(dooropen == 0) {
return 1;
}
tell_room(ob, "The door closes.\n");
dooropen = 0;
tell_room(ob2, "The door closes.\n");
return 1;
}

out(){
if(dooropen == 0) {
write("You walk straight into the closed door!\n");
return 1;
 }
if(floorlvl == 1) {
TP->move_player("out#/players/stark/utena/room/school3.c");
return 1;
 }
if(floorlvl == 2) {
TP->move_player("out#/players/stark/utena/room/council.c");
return 1;
 }
if(floorlvl == 3) {
TP->move_player("out#/players/stark/utena/room/planet.c");
return 1;
 }
}

push(arg) {
if(!arg) {
write("Push what?\n");
return 1;
 }
if(dooropen == 1) {
write("You first must close the door.\n");
return 1;
}
if(moving == 1) {
write("You must wait for the elevator to stop.\n");
return 1;
 }
if(arg == "1") {
if(floorlvl == 1) {
write("You are already at the first level.\n");
return 1;
  }
moving = 1;
tell_room(this_object(), "The elevator quickly jolts to the first level.\n");
call_out("move_1_1",2);
return 1;
 }
if(arg == "2") {
if(floorlvl == 2) {
write("You are already at the second level.\n");
return 1;
  }
moving = 1;
tell_room(this_object(), "The elevator quickly jolts to the second level.\n");
call_out("move_2_1",2);
return 1;
 }
if(arg == "3") {
if(floorlvl == 3) {
write("You are already at the third level.\n");
return 1;
  }
moving = 1;
tell_room(this_object(), "The elevator quickly jolts to the third level.\n");
call_out("move_3_1",2);
return 1;
 }
}

move_1_1(){
tell_room(this_object(), "moving...  moving...\n");
call_out("move_1_2",2);
}
move_1_2(){
tell_room(this_object(), "moving... moving...\n");
call_out("move_1_3",2);
}
move_1_3(){
tell_room(this_object(), "The elevator slows down.\n");
call_out("move_1_4",2);
}
move_1_4(){
tell_room(this_object(), "The elevator stops and opens up.\n");
floorlvl = 1;
moving = 0;
dooropen = 1;
ob2 = "/players/stark/utena/room/school3.c";
door_open_msg();
call_out("door_close_check",30);
return 1;
}

move_2_1(){
tell_room(this_object(), "moving...  moving...\n");
call_out("move_2_2",2);
}
move_2_2(){
tell_room(this_object(), "moving... moving...\n");
call_out("move_2_3",2);
}
move_2_3(){
tell_room(this_object(), "The elevator slows down.\n");
call_out("move_2_4",2);
}
move_2_4(){
tell_room(this_object(), "The elevator stops and opens up.\n");
floorlvl = 2;
moving = 0;
dooropen = 1;
ob2 = "/players/stark/utena/room/council.c";
door_open_msg();
call_out("door_close_check",20);
return 1;
}

move_3_1(){
tell_room(this_object(), "moving...  moving...\n");
call_out("move_3_2",2);
}
move_3_2(){
tell_room(this_object(), "moving... moving...\n");
call_out("move_3_3",2);
}
move_3_3(){
tell_room(this_object(), "The elevator slows down.\n");
call_out("move_3_4",2);
}
move_3_4(){
tell_room(this_object(), "The elevator stops and opens up.\n");
floorlvl = 3;
moving = 0;
dooropen = 1;
ob2 = "/players/stark/utena/room/planet.c";
door_open_msg();
call_out("door_close_check",30);
return 1;
}
