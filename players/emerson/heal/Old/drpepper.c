#include "std.h"
int drinks, price;

id(str) { return str == "pepsi"; }

reset(arg) {
	if (!arg) drinks = 3;
/*drinks changed from 4 to 3 to conform to Boltar's ruling of max healing of 175 points - arrina (8-17-96) */
	price = drinks * 150;
}

long() {
	write("A bottle of Pepsi that looks refreshing.\n" +
"There are "+drinks+" left.\n");
}

short() {
return "A two liter bottle of Pepsi";
}

query_save_flag()
{
return 1;
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
if(!arg || arg != "pepsi"){
	return 0;
} else {
if(!tp->drink_soft(50)){
	return 1;
}else{
	if(arg == "pepsi"){
drinks=drinks - 1;
tp->heal_self(50);
	write("You take a big swig of pepsi.\n");
	say(capitalize(tp->query_name()) + " takes a big swig of pepsi.\n");
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
