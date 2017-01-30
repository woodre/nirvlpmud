/*  10/08/06 - Rumplemintz: removed tailing ; from #include  */
#include "std.h"
int drinks, price;

id(str) { return str == "hotdog"; }

reset(arg) {
	if (!arg) drinks = 10;
	price = drinks * 150;
}

long() {
	write("A juicy Texas Hot hotdog with "+drinks+" bites left.\n");
}

short() {
	return "Texas Hot hotdog";
}

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
if(!arg || arg != "hotdog"){
	return 0;
} else {
if(!tp->eat_food(17)){
	return 1;
}else{
	if(arg == "hotdog"){
drinks=drinks - 1;
tp->heal_self(35);
	write("You stuff a huge bite into your mouth.\n"+
"There are "+drinks+" bites left.\n");
	say(capitalize(tp->query_name()) + " takes a bite of a hotdog.\n");
if(drinks == 0){
	destruct(this_object());
	write("You finish your Texas Hot.\n");
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
query_save_flag() { return 1; }
