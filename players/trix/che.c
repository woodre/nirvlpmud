id(str) { return str=="chest"; }
object user;
int x, y;
reset(arg) {
	if(!arg) x=1;
y=1;
}
short() {
	return "A Chest";
}
long() {
	write("It has strange symbols all over it that you have never seen before.\n"+
"Most of the lettering is black and in some type of language that you have never\n"+
"seen before.  You can make out some of the writing and as you read it a chill\n"+
"runs up your spine....'The one who opens this chest will face the wrath of Lucifer'\n");
}
init() {
	add_action("unlock","unlock");
	add_action("open","open");
	add_action("blah","blah");
	add_action("cv","cv");
	add_action("demon","demon");
}
unlock(str) {
	if(str=="chest") {
	if(!present("cultkey", this_player())) {
	write("You do not have the key.\n");
	return 1;
	}
	if(present("cultkey", this_player())) {
	x=x+10;
	write("You put the key in the lock and you hear a click.\n");
	say(capitalize(this_player()->query_real_name())+" unlocks the chest.\n");
	return 1;
	}
	}
}
open(str) {
	if(str=="chest") {
	if( y > 2) {
	write("The chest is already open.\n");
	return 1;
	}
	if(x < 2) {
	write("The chest is locked.\n");
	return 1;
	}
	if(x > 2) {
	y=y+10;
	write("The chest cover opens with a load creak.\n");
	user=this_player();
	return 1;
	}
	}
	call_out("blah", 2);
}
blah() {
	tell_object(user, "The chest begins to shake.  The room turns very hot.\n");
	return 1;
}
cv() {
	write("Flames shoot out from the top of the chest!\n");
	return 1;
}
demon() {
	object mons;
	write("A demon crawls out of hell through the chest to stand before you.\n");
	mons=clone_object("/players/dragnar/mons/demon.c");
	move_object(mons, this_object());
	return 1;
}
