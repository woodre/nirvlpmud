inherit "/players/stark/room";
#include "/players/stark/defs.h"
object ob;
reset(arg){

if(!present("akio"))  {
MOCO("/players/stark/utena/mon/akio.c"),this_object());  }


    if(arg) return;
    set_light(1);
    set_listen("A light whirring from the main system");
    set_smell("Akio's musk gives life to the air itself.");
    set_search("There is nothing out of the ordinary for now.");
    short_desc="The Planetarium";
    long_desc=
"   The heavens are illuminated on the domed ceiling above.  A large \n"+
"projector is situated at the very center of this large room.  Near the \n"+
"door, a pair of couches face each other.  This is so Akio and a few of \n"+
"his guests can come to view the stars.  An elevator door is to the \n"+
"south\n";

items=({
"heavens","The stars are projected on to the ceiling high",
"dome","This domed ceiling is dark but for the heavenly bodies shown",
"ceiling","This domed ceiling is dark but for the heavenly bodies shown",
"projector","This shines the telescoped view of the heavens onto the ceiling.",
"couches","A pair of couches, cushy and comfortable",
"door","An elevator door with a button at the side"
});
}

init(){
::init();
add_action("enter","enter");
add_action("push","push");
add_action("open","open");
add_action("close","close");
ob = "/players/stark/utena/room/elevator2.c";
}

push(arg) {
if(!arg) {
write("Push what?\n");
return 1; }
if(arg == "button") {
if((ob->query_moving()) == 1) {
write("You must wait for the elevator to stop moving\n");
return 1; }
if((ob->query_floorlvl()) == 3) {
if((ob->query_dooropen()) == 1) {
write("The door is open.\n");
return 1; }
write("The elevator is allready at your level.\n");
return 1; }
ob->push("3");
write("You push the button and it glows.\n");
say(TPN+" pushes the button beside the door and it glows.\n");
return 1;
}
}

enter(){
if((ob->query_dooropen()) == 0) {
write("The door is closed.\n");
return 1; }
if((ob->query_floorlvl()) == 3) {
write("You enter the Elevator.\n");
TP->move_player("north#/players/stark/utena/room/elevator2.c");
return 1; }
write("The elevator is not at this floor.\n");
return 1; }


open(arg) {
if(!arg) {
write("Open what?\n");
return 1;
 }
if(arg == "door") {
if((ob->query_dooropen()) == 1) {
write("The door is already open.\n");
return 1;
}
if((ob->query_moving()) == 1) {
write("You must wait for the elevator to stop.\n");
return 1;
 }
write("You pull open the door.\n");
ob->set_dooropen(1);
return 1;
}
}

close(arg) {
if(!arg) {
write("Close what?\n");
return 1;
 }
if(arg == "door") {
if((ob->query_dooropen()) == 0) {
write("The door is already closed.\n");
return 1;
 }
if((ob->query_moving()) == 1) {
write("You must wait for the elevator to stop.\n");
return 1;
 }
write("You pull the door close.\n");
ob->set_dooropen(0);
return 1;
}
}
