inherit "/players/stark/room";
#include "/players/stark/defs.h"
object ob;
reset(arg){
    if(arg) return;
    set_light(1);
    set_listen("The sounds of the school have been muted.");
    set_smell("Small deposits of mildew harken to cavernous terrain.");
    set_search("You search along the rug and walls and find nothing.\n");
    short_desc="Halls of Ohtori Academy.";
    long_desc=
"   A small brick hallway leads toward a gilded door.  A plush red rug \n"+
"cushions every step down this passage.  The crumbling brick is lit up \n"+
"by electric candelabras.\n";

items=({
"brick","Solid brick walls this small hallway",
"door","An elevator door with a button at the side",
"elevator","An elevator is at the end of this hallway",
"rug","A plush red rug",
"passage","This secret passage leads from the Student Council room into darkness",
"candelabras","Old style light fixtures.",
"button","A small button marked '1'"
});

dest_dir=({
"/players/stark/utena/room/school2.c","south"
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
if((ob->query_floorlvl()) == 1) {
if((ob->query_dooropen()) == 1) {
write("The door is open.\n");
return 1; }
write("The elevator is allready at your level.\n");
return 1; }
ob->push("1");
write("You push the button and it glows.\n");
say(TPN+" pushes the button beside the door and it glows.\n");
return 1;
}
}

enter(){
if((ob->query_dooropen()) == 0) {
write("The door is closed.\n");
return 1; }
if((ob->query_floorlvl()) == 1) {
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
