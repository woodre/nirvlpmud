#include "std.h"

int drinks, price;

 

id(str) { return str == "cookie" || str == "cookies" || str == "finger" || str == "bag" || str == "fingers"; }

 

reset(arg) {

        if (!arg) drinks = 30;

        price = drinks * 150;

}

 

long() {

        write("This is a bag of Vienna Fingers cookies. Each cookie is made\n"+

	"like a sandwich, biscuit sides and a creamy vanilla center.\n"+

	"There are ["+drinks+"] cookies left.\n");

}

 

short() {

     return "A bag of Vienna Fingers cookies";

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

if(!arg || arg != "cookie"){

        return 0;

} else {

if(!tp->eat_food(8)){

        return 1;

}else{

        if(arg == "cookie"){

drinks=drinks - 1;

tp->heal_self(random(5)+4);

        write("You gobble up a cookie in record time. There are ["+drinks+"] cookies left.\n");

        say(capitalize(tp->query_name()) + " eats a cookie.\n");

if(drinks == 0){

        destruct(this_object());

        write("You eat the last one and finish off the bag.\n");

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
