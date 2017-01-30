/*
    Changelog:
	Bal 1996-03-15:
	+ removed ; after #include
	+ moved inherit to top of file
*/

inherit "room/room";

#include "/players/dragnar/closed/color.h"
#define SAVE_PATH "players/dragnar/WasteLands/code/code"

realm() { return "NT"; }
int x,y,XYZ;
set_XYZ(ob) { XYZ=ob; }
init() {
	::init();
call_out("hb",10);
restore_code();
	add_action("restore_code","restore_code");
	this_player()->set_fight_area();
	add_action("swipe","swipe");
	add_action("north","north");
	add_action("enter","enter");
}
reset(arg) {
	if(arg) return;
	if(!arg) x=1;
y=1;
set_light(5);
short_desc=("Wastelands Town");
long_desc=
"You are in a long hallway.  Your footsteps echo off of the walls.  At\n"+
"the north end of the hall there is a security door.  Next to it is a keypad.\n",
items=
({
"door", "It looks like it is made of steal and is very thick",
"keypad","It must be the security access for the door.  It has a slot you could\n"+
"swipe a card in.  It also has a number keypad on it",
});
dest_dir=
({
"players/dragnar/WasteLands/rooms/past/town5.c","south",
});
}
swipe(){
	string code;
	if(!present("scicard", this_player())){
	write(RED+BLINK+"ERROR:"+NOSTYLE+WHI+"Please try again.\n");
	return 1;
	}
	if(y < 2) {
	x=x+10;
	write("You hear a voice from the keypad: Security card check ok.\n"+
"Please enter your authorization number now: ");
	input_to("enter");
	return 1;
	}
	else if(y < 2) {
	write("You hear a voice from inside of the keypad:  This area is\n"+
"restricted and security has been broken, please leave the building.\n");
	return 1;
	}
}
enter(str) {
	if(str==""+XYZ+""){
	if(x > 2) {
	y=y+6;
	write("You hear a voice within the keypad say: Welcome Dr. Kugler.\n"+
"A motor hums into life and the door opens allowing you to go north.\n");
	return 1;
	}
	}
	if(x < 2) {
	write("You hear a voice from within the keypad: Please swipe your\n"+
"autorization card first.\n");
	return 1;
	}
	else if(str) {
	write(RED+BLINK+"ERROR:"+NOSTYLE+WHI+" Please try again.\n");
	return 1;
	}
}
north() {
	if(y > 2) {
	y=y-6;
	call_other(this_player(),"move_player","north#/players/dragnar/WasteLands/rooms/past/quest.c");
write("\nThe door closes behind you.\n");
	return 1;
	}
	else if(y < 2) {
	write("The door is closed.\n");
	return 1;
	}
}
restore_code(){
	restore_object(SAVE_PATH);
	return 1;
}
hb(){
	restore_code();
call_out("hb",10);
}
