#include "std.h"
int drinks, price;

id(str) { return str == "firewater"; }

reset(arg) {
	if (!arg) drinks = 10;
	price = drinks * 200;
}

long() {
	write("A bottle of firewater with "+drinks+" shots left.\n");
}

short() {
	return "A bottle of firewater";
}

query_value()
{
    return price;
}

init() {
    add_action("use","drink");
}

use(arg){
object tp;
tp = this_player();
if(!arg || arg != "firewater"){
	return 0;
} else {
if(!tp->drink_alcohol(7)){
	return 1;
}else{
	if(arg == "firewater"){
drinks=drinks - 1;
this_player()->heal_self(50);
	write("The firewater makes you mouth BURN! There are "+drinks+" shots left.\n");
	say(capitalize(tp->query_name()) + " slams a shot of firewater.\n");
if(drinks == 0){
	destruct(this_object());
	write("You smash the bottle on the ground as you finish off the firewater.\n");
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
