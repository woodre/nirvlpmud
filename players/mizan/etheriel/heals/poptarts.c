#include "std.h"
int drinks, price;

id(str) { return str == "pop tart" || str == "poptarts" || str == "pop tarts" || str == "tart" || str == "tarts"; }

reset(arg) {
	if (!arg) drinks = 15;
	price = drinks * 150;
}

long() {
	write("This is a box of cherry-flavored Pop Tarts. There are ["+drinks+"] tarts left.\n");
	write("Type 'eat tart' to eat one.\n");
}

short() {
	return "A box of Pop Tarts"; 
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
if(!arg || arg != "tart"){
	return 0;
} else {
if(!tp->eat_food(13)){
	return 1;
}else{
	if(arg == "tart"){
drinks=drinks - 1;
tp->heal_self(30);
	write("You break into the box, whip out a Pop Tart, and deftly munch it up in one bite.\n"+
	"["+tp->query_hp()+"]hp ["+tp->query_sp()+"]sp ["+
	drinks+"] tarts left.\n");
	say(capitalize(tp->query_name()) + " breaks open an individually wrapped Pop Tart and eats it.\n");
if(drinks == 0){
	destruct(this_object());
	write("You crumple the empty box beyond any acceptable definiton.\n");
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
