#include "/obj/clean.c"
int drinks, price;

id(str) { return str == "pepsi"; }

reset(arg) {
	if (!arg) drinks = 1;
	price = drinks * 150;
}

long() {
	write("A can of Pepsi that looks refreshing.\n" +
"The can contains "+drinks+" serving of Pepsi.\n");
}

short() {
return "A can of Pepsi";
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
if(!tp->drink_soft(35)){
	return 1;
}else{
	if(arg == "pepsi"){
drinks=drinks - 1;
tp->heal_self(10);
	write("You slam down a whole can of pepsi.\n");
	say(capitalize(tp->query_name()) + " slams down a can of pepsi.\n");
if(drinks == 0){
	destruct(this_object());
	write("You finish the can.\n");
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
