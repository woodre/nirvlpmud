#include "std.h"

int drinks, price;

 

id(str) { return str == "squeezins" || str == "squeezin" || str == "bottle"; }

 

reset(arg) {

        if (!arg) drinks = 5;

        price = drinks * 150;

}

 

long() {

        write("This is a bottle filled with a questionable liquid.\n\n"+

	"Ingredients: Fermented saguaro cactus, snake essence, water.\n"+

	"Type 'drink squeezins' to drink, (but you're not sure if you should..)\n"+
	"There are ["+drinks+"] servings left.\n");

}

 

short() {

     return "A bottle of Snake Squeezins";

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

if(!arg || arg != "squeezins"){

        return 0;

} else {

if(!tp->drink_alcohol(12)){

        return 1;

}else{

        if(arg == "squeezins"){

drinks=drinks - 1;

tp->heal_self(random(5)+30);

        write("Whoa! Real stong stuff! There are ["+drinks+"] servings left.\n");

        say(capitalize(tp->query_name()) + " chugs some thick, green liquid.\n");

if(drinks == 0){

        destruct(this_object());

        write("You drink the last serving toss the empty bottle away.\n");

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
