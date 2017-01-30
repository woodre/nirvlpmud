
#include "std.h"

int drinks, price;

id(str) { return str == "bottle" || str == "pill" || str == "pills"; }

reset(arg) {

        if (!arg) drinks = 8;

        price = drinks * 150; }

long() {

        write("This is a small, greenish bottle that holds "+drinks+" large,\n"+

	"yellow pills that smell like curry powder. They react with the\n"+

	"food in you're stomach, effectively making you hungrier. They were\n"+

	"not a hit when sold at homeless shelters, for obvious reasons.\n");

}

short() { return "A bottle of Bunupuradah's Fastacid Super-Curry pills"; }

query_save_flag() {return 1;}

query_value() { return price; }

init() {

/* Rump
    add_action("use"); add_verb("eat");

  add_action("use"); add_verb("swallow"); }
*/
  add_action("use", "eat");
  add_action("use", "swallow");
}

use(arg){

object tp;

tp = this_player();

if(!arg || arg != "pill"){

        return 0;

} else {

if(!tp->eat_food(-13)){

        return 1;

}else{

        if(arg == "pill"){

drinks=drinks - 1;

        write("You swallow a pill.. it's HOT!!! Somehow, you feel hungry...\n"+

	"There are"+drinks+" drinks left.\n");

        say(capitalize(tp->query_name()) + " pops a large yellow pill and belches flame.\n");

if(drinks == 0){

        destruct(this_object());

        write("You finish off the bottle, and huck it away.\n");

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

