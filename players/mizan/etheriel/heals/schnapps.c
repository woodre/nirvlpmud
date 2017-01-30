#include "std.h"
int drinks, price;

id(str) { return str == "schnapps"; }

reset(arg) {
	if (!arg) drinks = 10;
	price = drinks * 50;
}

long() {
	write("This is a bottle of orange schnapps. There are ["+drinks+"] drinks left.\n");
}

short() {
     return "A bottle of orange schnapps";
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
if(!arg || arg != "schnapps"){
	return 0;
} else {
if(!tp->drink_alcohol(5)){
	return 1;
}else{
	if(arg == "schnapps"){
drinks=drinks - 1;
tp->heal_self(10);
	write("You feel giddy, and happy, and merry, and chortle gleefully!\n"+
	"["+tp->query_hp()+"]hp ["+tp->query_sp()+"]sp ["+
	drinks+"] drinks left.\n");
	say(capitalize(tp->query_name()) + " slurps down some schnapps.\n");
if(drinks == 0){
	destruct(this_object());
	write("You finish off the bottle and break it into a billion pieces.\n");
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
