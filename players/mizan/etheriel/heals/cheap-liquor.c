#include "std.h"
int drinks, price;

id(str) { return str == "wine"; }

reset(arg) {
	if (!arg) drinks = 10;
	price = drinks * 150;
}

long() {
	write("A bottle of wine with "+drinks+" drinks left.\n");
}

short() {
     return "A bottle of wine";
}

query_save_flag() {return 1;}
query_value()
{
    return price;
}

init() {
add_action("use", "drink");
}

use(arg){
object tp;
tp = this_player();
if(!arg || arg != "wine"){
	return 0;
} else {
if(!tp->drink_alcohol(15)){
	return 1;
}else{
	if(arg == "wine"){
drinks=drinks - 1;
tp->heal_self(30);
	write("You take a swig of wine.  There are "+drinks+" drinks left.\n");
	say(capitalize(tp->query_name()) + " takes a drink of wine.\n");
if(drinks == 0){
	destruct(this_object());
	write("You finish off the bottle.\n");
	tp->add_weight(-1);
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
    return 1;
}
