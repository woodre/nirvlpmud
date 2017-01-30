#include "std.h"
int drinks, price;

id(str) { return str == "vodka"; }

reset(arg) {
	if (!arg) drinks = 6;
	price = drinks * 200;
}

long() {
	write("A bottle of vodka with "+drinks+" shots left.\n");
}

short() {
	return "A bottle of vodka";
}

query_value()
{
    return price;
}

init() {
    add_action("use"); add_verb("drink");
}

use(arg){
object tp;
tp = this_player();
if(!arg || arg != "vodka"){
	return 0;
} else {
if(!tp->drink_alcohol(14)){
	return 1;
}else{
	if(arg == "vodka"){
drinks=drinks - 1;
/*
this_player()->heal_self(40);
This is Illegal and way too high. read /doc/build/RULES!!! -Bp
I believe I fixed this before. you remove one more of my fixes and your
ass is level 0, understand?
*/
this_player()->heal_self(15);
	write("The vodka hurts the back of your throat. There are "+drinks+" shots left.\n");
	say(capitalize(tp->query_name()) + " slams a shot of vodka.\n");
if(drinks == 0){
	destruct(this_object());
	write("You smash the bottle on the ground as you finish off the vodka.\n");
		}
return 1;
		}
	}
}
}

get() {
    return 1;
}

query_weight() {
    return 2;
}
query_save_flag() { return 1; }
