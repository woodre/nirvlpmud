#include "std.h"
int x;
object peeker;
id(str) { return str == "pipe"; }
short() { return "A pipe sticking out of somewhere"; }
long() { 
write("This is a pipe, sticking out of nowhere in particular. When you\n"+
"stick your eyeball into it and peer into the other end, you see:\n\n"+
"	KDY Corporation Proudly Presents: (drum roll)\n"+
"	The New Super Neat 'Quick Score Peeper!' (cheer!)\n"+
"	What it does is Amazing! With a keystroke you get your Vital\n"+
"	Stats (hitpoints, spellpoints, gold, etc)...\n\n"+
"		In One Line! Just Like This! \n"+
"		No Messy Lag-Producing Scroll!\n"+
"	Just Think!! (You only want to know how much gold you have at the shop..\n"+
"		...or you're Not In A Guild and have to keep typing\n"+
"		'sc' 'sc' 'sc' ----> For the Low, Low Price of 50 coins\n"+
"		It Could Be Yours!! (Type 'squeeze pipe' to get one!)\n"+
"	Yes! 'squeeze pipe'! Only 50 coins! (Act Now! (Hurry!))\n");
	}
init() {
	add_action("squeeze","squeeze");
	}
squeeze(str) {
	if(!str) { write("Squeeze what? (The pipe)\n"); return 1; }
	if(str=="pipe") {
	x=(this_player()->query_money());
	if(x<50) { write("I'm sorry, you don't have enough gold...\n"); return 1; }
	call_other(this_player(), "add_money", 0-50);
	peeker=clone_object("players/mizan/etheriel/items/sc.c");
	move_object(peeker, this_player());
	write("You roll 50 coins down the pipe and squeeze it. \n"+
	"POP! A peeker shoots skywards and you deftly catch it!\n"+
	"Congrats! You are the Proud new owner of a Quick Score Peeker!\n");
	say((this_player()->query_name())+" drops some coins down the pipe, and it shoots something out!\n");
	return 1;
	}
	return 0;
}
