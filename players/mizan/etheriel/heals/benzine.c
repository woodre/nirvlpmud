#include "std.h"
int drinks, price;

id(str) { return str == "benzine"; }

reset(arg) {
	if (!arg) drinks = 6;
	price = drinks * 150;
}

long() {
	write("This is a flask with benzine in it. There are ["+drinks+"] drinks left.\n");
}

short() {
     return "A flask of benzine";
}

  query_save_flag() {return 1;}
query_value()
{
    return price;
}

init() {
/* Rump
add_action("use", "drink");
*/
    add_action("use", "drink");
}

use(arg){
object tp;
tp = this_player();
if(!arg || arg != "benzine"){
	return 0;
} else {
if(!tp->drink_alcohol(15)){
	return 1;
}else{
	if(arg == "benzine"){
drinks=drinks - 1;
tp->heal_self(30);
	write("You open the flask and take a swig of benzine.\n"+
	"["+tp->query_hp()+"]hp ["+tp->query_sp()+"]sp ["+
	drinks+"] drinks left.\n");
	say(capitalize(tp->query_name()) + " slurps down some benzine.\n");
if(drinks == 0){
	destruct(this_object());
	write("You finish off the flask and chuck it away.\n");
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
