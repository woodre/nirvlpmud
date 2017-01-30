#include "/players/dragnar/closed/color.h"
inherit "room/room";
realm() { return "NT"; }
int x;
init() {
	::init();
	this_player()->set_fight_area();
	add_action("break","break");
	add_action("push","push");
}
reset(arg) {
	if(arg) return;
	if(!arg) x=1;
set_light(1);
short_desc=("Wastelands Quest");
long_desc=
"This room seems to be a high security room.  A scientist is passed out\n"+
"on the floor, he seems to be sweating very badly.  As you take a closer look\n"+
"at him, you realize it is his picture on your autorization card.  Around\n"+
"you are many control pannels and monitors.  One pannel catches you eye because\n"+
"it is labled 'Launch Sequence'.\n",
items=
({
"launch sequence pannel","The numbers are flashing very rapidy.  They seem to be moveing faster\n"+
"and faster as time moves on.  The pannel is covered with glass and a button\n"+
"is next to the launch sequence numbers",
});
dest_dir=
({
"players/dragnar/WasteLands/rooms/past/town6.c","south",
});
}
break(str) {
	if(str=="glass"){
	if(!present("timer", this_player())){
	write("You hand bounces off the glass and does no damage.\n");
	return 1;
	}
	x=x+10;
	write("You make a fist and shatter the glass in one blow!\n");
	say(capitalize(this_player()->query_real_name())+" makes a fist and breaks the glass on the pannel.\n");
	return 1;
	}
}
push(str) {
	object finished;
	if(str=="button"){
	if(x > 2) {
	destruct(present("timer", this_player()));
	finished=clone_object("/players/dragnar/quest.c");
	move_object(finished, this_object());
	return 1;
	}
	if(x < 2) {
	write("It is covered by the glass.\n");
	return 1;
	}
	}
}
