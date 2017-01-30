#include "std.h"
int pills, price;

id(str) { return str == "x-lax"; }

reset(arg) {
	if (!arg) pills = 10;
	price = pills * 100;
}

long() {
write("A box of X-lax with "+pills+" x-laxs left.\n");
}

short() {
return "A Box of X-lax";
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
if(!arg || arg != "x-lax"){
	return 0;
} else {
/*-20 way too high, changed. -Bp*/
if(!tp->eat_food(-6)){
	return 1;
}else{
	if(arg == "x-lax"){
pills=pills - 1;
tp->heal_self(0);
	write("You stuff a x-lax into your mouth.  There are "+pills+" x-lax pills left.\n");
	say(capitalize(tp->query_name()) + " eats a x-lax from a box.\n");
if(pills == 0){
	destruct(this_object());
	write("You finish your X-lax.\n");
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
