#include "std.h"
int drinks, price;

id(str) { return str == "pan" || str == "crispies" || str =="rice crispy" || str == "treat"; }

reset(arg) {
	if (!arg) drinks = 5;
	price = drinks * 150;
}

long() {
write("This is a cookie pan filled with delicious Rice Crispies Treats.\n"+
	"each one is made of marshmallows, margerine, and cookied rice crispies.\n"+
	"There are ["+drinks+"] treats left.\n");
	write("Type 'eat treat' to eat one.\n");
}

short() {
	return "A pan of Rice Crispies treats. (warm)";
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
if(!arg || arg != "treat"){
	return 0;
} else {
if(!tp->eat_food(13)){
	return 1;
}else{
	if(arg == "treat"){
drinks=drinks - 1;
tp->heal_self(30);
	write("You scoop your hands into the pan, and devour a treat whole in two bites.\n"+
	"["+tp->query_hp()+"]hp ["+tp->query_sp()+"]sp ["+
	drinks+"] treats left.\n");
	say(capitalize(tp->query_name()) + " wolfs down a Rice Crispies treat and grins evilly.\n");
if(drinks == 0){
	destruct(this_object());
	write("You finish the pan and toss it away.\n");
	tp->add_weight(-3);
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
    return 3;
}
