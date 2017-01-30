#include "std.h"
int drinks, price;

id(str) { return str=="speed" || str=="pills"; }

reset(arg) {
	if (!arg) drinks = 7;
	price = drinks * 250;
}

long() {
	write("A pack of 10 speed pills.  They look like they would make you very hungry.\n" +
"There are "+drinks+" pills left.\n");
}

short() {
     return "A pack of speed pills";
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
if(!arg || arg != "speed"){
	return 0;
} else {
if(!tp->eat_food(-5))  
return 1;
	if(arg == "speed"){
drinks=drinks-1;
	write("The speed makes you feel hungry again.\n");
	write("There are "+drinks+" pills left.\n");
	say(capitalize(tp->query_name()) + " pops a speed pill.\n");
if(drinks == 0) {
	write("You use up the last of your pills.\n");
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
