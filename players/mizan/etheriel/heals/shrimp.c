#include "std.h"

int drinks, price;

 

id(str) { return str == "chips" || str == "chip" || str == "bag" || str == "shrimp chips"; }

 

reset(arg) {

        if (!arg) drinks = 21;

        price = drinks * 150;

}

 

long() {

        write("This is a bag of shrimp chips. It is very nutritious stuff,\n"+

	"since it is cooked in vegetable oil and not too much is used.\n"+

	"There are ["+drinks+"] chips left.\n");

}

 

short() {

     return "A bag of shrimp chips";

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

if(!arg || arg != "chip"){

        return 0;

} else {

if(!tp->eat_food(9)){

        return 1;

}else{

        if(arg == "chip"){

drinks=drinks - 1;

tp->heal_self(random(20)+6);

        write("You open the bag and swallow up a shrimp chip. There are ["+drinks+"] cheesenubs left.\n");

        say(capitalize(tp->query_name()) + " eats a shrimp chip.\n");

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
