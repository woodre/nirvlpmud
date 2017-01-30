#include "std.h"
int drinks, price;

id(str) { return str == "goo" || str == "bottle" || str == "neutromuck"; }

reset(arg) {
	if (!arg) drinks = 20;
	price = drinks * 300;
}

long() {
	write("This is a bottle of Neutromuck. It serves to eliminate the effects\n"+
	"of alcohol on a person's mind. To use it, type 'drink goo'.\n"+
	"There are ["+drinks+"] servings left in the bottle.\n");
}

short() {
	return "A bottle of Neutromuck"; 
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
if(!arg || arg != "goo"){
	return 0;
} else {
if(!tp->drink_alcohol(-10)){
	return 1;
}else{
	if(arg == "goo"){
drinks=drinks - 1;
	write("You slurp some thick purple goo from the bottle.\n"+
	"There are ["+drinks+"] servings remaining.\n");
	say(capitalize(tp->query_name()) + " downs some odd-looking purple stuff.\n");
if(drinks == 0){
	destruct(this_object());
	write("You finish off the bottle and chuck it away.\n");
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
