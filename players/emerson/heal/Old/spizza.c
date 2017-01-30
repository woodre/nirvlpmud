#include "std.h"
int drinks, price;

id(str) { return str == "pizza"; }

reset(arg) {
	if (!arg) drinks = 3;
/* drinks changed from 8 to 3 because of boltar's ruling of max healing of 175 points - arrina (8-17-96) */
	price = drinks * 150;
}

long() {
write("A large Stuffed Crust Pizza with "+drinks+" slices left.\n");
}

short() {
 return "A Large Stuffed Crust Pizza";
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
    add_action("use"); add_verb("eat");
}

use(arg){
object tp;
tp = this_player();
if(!arg || arg != "pizza"){
	return 0;
} else {
if(!tp->eat_food(45)){
	return 1;
}else{
	if(arg == "pizza"){
drinks=drinks - 1;
tp->heal_self(45);
	write("You stuff a huge slice into your mouth.  There are "+drinks+" slices left.\n");
	say(capitalize(tp->query_name()) + " eats a slice of pizza.\n");
if(drinks == 0){
	destruct(this_object());
	write("You finish your Pizza Hut Pizza.\n");
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