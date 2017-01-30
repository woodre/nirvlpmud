#include "std.h"
int drinks, price;

id(str) { return str=="beast"; }

reset(arg) {
	if (!arg) drinks = 12;
	price = drinks * 250;
}

long() {
	write("A case of Milwaukie's Best with "+drinks+" cans left.\n");
}

short() {
	return "A 12 pack of beast";
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
if(!arg || arg != "beast"){
	return 0;
} else {
if(!tp->drink_alcohol(14)){
	return 1;
}else{
	if(arg == "beast"){
drinks=drinks - 1;
this_player()->heal_self(10+random(5));
	write("The taste makes you feel sick, but stronger.\n" +
"There are "+drinks+" cans left.\n");
	say(capitalize(tp->query_name()) + " chugs a can of beast.\n");
if(drinks == 0){
	destruct(this_object());
	write("You finish off the last can.\n");
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
