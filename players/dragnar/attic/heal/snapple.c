#include "std.h"
int drinks, price;

id(str) { return str == "snapple"; }

reset(arg) {
	if (!arg) drinks = 3;
	price = drinks * 150;
}

long() {
	write("A bottle of snapple that looks refreshing.\n" +
"There are "+drinks+" left.\n");
}

short() {
	return "Bottle of Peach Ice Tea Snapple";
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
if(!arg || arg != "snapple"){
	return 0;
} else {
if(!tp->drink_soft(20)){
	return 1;
}else{
	if(arg == "snapple"){
drinks=drinks - 1;
tp->heal_self(7);
	write("You take a big swig of snapple.\n");
	write("There are "+drinks+" drinks left.\n");
	say(capitalize(tp->query_name()) + " takes a big swig of snapple.\n");
if(drinks == 0){
	destruct(this_object());
	write("You finish the bottle.\n");
	tp->add_weight(-2);
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
