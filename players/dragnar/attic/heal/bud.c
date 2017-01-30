#include "std.h"
int drinks, price;

id(str) { return str == "bud"; }

reset(arg) {
	if (!arg) drinks = 12;
	price = drinks * 200;
}

long() {
	write("A 12 pack of Bud with "+drinks+" beers left.\n");
}

short() {
	return "A 12 pack of Bud";
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
if(!arg || arg != "bud"){
	return 0;
} else {
if(!tp->drink_alcohol(12)){
	return 1;
}else{
	if(arg == "bud"){
drinks=drinks - 1;
this_player()->heal_self(10);
	write("You feel the healing power in the beer as soon as you drink it.\n");
	write("There are "+drinks+" cans left.\n");
	say(capitalize(tp->query_name()) + " slams a can of bud.\n");
if(drinks == 0){
	destruct(this_object());
	write("You finish off the last can of bud.\n");
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
