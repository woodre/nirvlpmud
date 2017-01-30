#include "std.h"
int drinks, price;

id(str) { return str == "breadstick"; }

reset(arg) {
	if (!arg) drinks = 5;
	price = drinks * 150;
}

long() {
write("A bag of Pizza Hut Breadsticks with "+drinks+" breadsticks left.\n");
}

short() {
return "A Bag of Breadsticks";
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
    add_action("use","eat");
}

use(arg){
object tp;
tp = this_player();
if(!arg || arg != "breadstick"){
	return 0;
} else {
if(!tp->eat_food(20)){
	return 1;
}else{
	if(arg == "breadstick"){
drinks=drinks - 1;
tp->heal_self(20);
	write("You stuff a breadstick into your mouth.  There are "+drinks+" breadsticks left.\n");
	say(capitalize(tp->query_name()) + " eats a breadstick from a bag.\n");
if(drinks == 0){
	destruct(this_object());
	write("You finish your Breadsticks.\n");
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
