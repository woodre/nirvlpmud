#include "std.h"
int drinks, price;

id(str) { return str == "bar"; }

reset(arg) {
	if (!arg) drinks = 5;
	price = drinks * 50;
}

long() {
	write("This is a Snickers candy bar. There are ["+drinks+"] bites left.\n");
}

short() {
	return "A Snickers bar";
}

query_save_flag() {return 1;}
query_value()
{
    return price;
}

init() {
add_action("use", "eat");
}

use(arg){
object tp;
tp = this_player();
if(!arg || arg != "bar"){
	return 0;
} else {
if(!tp->eat_food(5)){
	return 1;
}else{
	if(arg == "bar"){
drinks=drinks - 1;
tp->heal_self(10);
	write("Chunks of peanuts and chocolate let loose when you chomp some of the bar.\n"+
	"["+tp->query_hp()+"]hp ["+tp->query_sp()+"]sp ["+
	drinks+"] bites left.\n");
	say(capitalize(tp->query_name()) + " viciously chews off a chunk of a candy bar.\n");
if(drinks == 0){
	destruct(this_object());
	write("Ahh! Snickers satisfies you! crumple up the wrapper and toss it away.\n");
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
