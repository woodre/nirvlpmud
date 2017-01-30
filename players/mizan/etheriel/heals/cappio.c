#include "std.h"

int drinks, price;

id(str) { return str == "cappio" || str == "bottle" || str =="cappuccino"; }

reset(arg) {        if (!arg) drinks = 9;

        price = drinks * 150; }

long() {

        write("A bottle of Cappio [tm] iced cappucino drink with "+drinks+" sips left.\n");

	write("This stuff looks like it sobers you up a bit too, aside from\n"+

	"healing you a tad... and so hip too!\n");}

short() {

     return "A bottle of Cappio"; }

query_save_flag() {return 1;}

query_value()

{ return price; }

/* Rump
init() { add_action("use"); add_verb("drink"); }
*/
init() { add_action("use", "drink"); }

use(arg){

object tp;

tp = this_player();

if(!arg || arg != "cappio"){

        return 0;

} else {

if(!tp->drink_alcohol(-5)){

        return 1;

}else{

        if(arg == "cappio"){

drinks=drinks - 1;

tp->heal_self(random(7));

        write("You take a sip of Cappio! How fashionable! There are "+drinks+" sips left.\n");

        say(capitalize(tp->query_name()) + " looks so chic sipping some Cappio [tm] iced cappuccino.\n");

if(drinks == 0){

        destruct(this_object());

        write("You gracefully toss away the empty bottle.\n");

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
