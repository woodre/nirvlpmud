#include "std.h"
int drinks, price;

id(str) { return str == "pretzels"; }

reset(arg) {
	if (!arg) drinks = 5;
	price = drinks * 250;
}

long() {
	write("A bag of pretzels.  They look like they would make you thirsty.\n" +
"There are "+drinks+" handfuls left.\n");
}

short() {
     return "A bag of pretzels";
}

query_value()
{
    return price;
}

init() {
    add_action("use"); add_verb("eat");
}

use(arg){
object tp;
tp = this_player();
if(!arg || arg != "pretzels"){
	return 0;
} else {
if(!tp->drink_soft(-10))  
return 1;
	if(arg == "pretzels"){
drinks=drinks-1;
	write("The pretzels makes you feel thristy again.\n");
	write("There are "+drinks+" handfulls left.\n");
	say(capitalize(tp->query_name()) + " munches a handful of pretzels.\n");
if(drinks == 0) {
	write("You finish off the bag.\n");
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
