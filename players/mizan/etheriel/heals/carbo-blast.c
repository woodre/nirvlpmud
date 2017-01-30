#include "std.h"
int drinks, price;

id(str) { return str == "bottle" || str == "blast"; }

reset(arg) {
	if (!arg) drinks = 5;
	price = drinks * 50;
}

long() {
	write("This is a bottle of Carbo Blast. There are ["+drinks+"] drinks left.\n");
	write("Type 'drink bottle' to use.\n");
}

short() {
     return "A bottle of Carbo Blast";
}

query_save_flag() {return 1;}
query_value()
{
    return price;
}

init() {
/* Rump
    add_action("use"); add_verb("drink");
*/
  add_action("use", "drink");
}

use(arg){
object tp;
tp = this_player();
if(!arg || arg != "bottle"){
	return 0;
} else {
if(!tp->drink_alcohol(5)){
	return 1;
}else{
	if(arg == "bottle"){
drinks=drinks - 1;
tp->heal_self(10);
	write("You stick the bottle in your mouth and squeeze..... Ahhh!\n"+
	"["+tp->query_hp()+"]hp ["+tp->query_sp()+"]sp ["+
	drinks+"] drinks left.\n");
	say(capitalize(tp->query_name()) + " chugs down some Carbo Blast.\n");
if(drinks == 0){
	destruct(this_object());
	write("You finish off the bottle and heave it into oblivion.\n");
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
