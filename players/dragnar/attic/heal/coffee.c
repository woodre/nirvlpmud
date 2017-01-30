#include "std.h"
int drinks, price;

id(str) { return str == "coffee"; }

reset(arg) {
	if (!arg) drinks = 3;
	price = drinks * 250;
}

long() {
	write("A thermos of coffee.  It looks good for a hangover.\n"+
"There are "+drinks+" cups left.\n");
}

short() {
     return "A thermos of coffee";
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
if(!arg || arg != "coffee"){
	return 0;
} else {
if(!tp->drink_alcohol(-8))  
return 1;
	if(arg == "coffee"){
drinks=drinks-1;
tp->heal_self(1);
	write("The coffee seems to make you feel better from all of that alcohol.\n");
	say(capitalize(tp->query_name()) + " Drinks a cup of coffee from a thermos.\n");
	write("There are "+drinks+" cups left.\n");
if(drinks == 0) {
	write("You notice your thermos is empty.\n");
	destruct(this_object());
	this_player()->add_weight(-1);
		}
return 1;
		}

}
}
get() {
    return 1;
	}

query_weight() {
return 1;
}
query_save_flag() { return 1; }
