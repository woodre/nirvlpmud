#include "std.h"
int drinks, price;

id(str) { return str=="can" || str=="beer" || str=="bud"; }

reset(arg) {
	if (!arg) drinks = 1;
	price = drinks * 200;
}

long() {
	write("A can of bud ice.  It looks very inviting.\n");
}

short() {
	return "A can of Bud";
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
if(!tp->drink_alcohol(14)){
	return 1;
}else{
	if(arg == "bud"){
drinks=drinks - 1;
this_player()->heal_self(10);
	write("You feel the healing power in the beer as soon as you drink it.\n");
	say(capitalize(tp->query_name()) + " slams a can of beer.\n");
if(drinks == 0){
	destruct(this_object());
	write("You crush the can and throw it on the ground.\n");
		}
return 1;
		}
	}
}
}

get() {
    return 1;
}

query_save_flag(){return 1;}
query_weight() {
    return 2;
}
