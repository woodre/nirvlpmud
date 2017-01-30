#include "std.h"
int drinks, price;
id(str) { return str == "bottle" || str == "wine"; }
reset(arg) {
        if (!arg) drinks = 10;
        price = drinks * 100; }
long() {
        write("This is a bottle of cheap red wine.\n"+
	"There are ["+drinks+"] servings left.\n");
}
short() { return "A bottle of cheap wine"; }
query_save_flag() {return 1;}
query_value() { return price; }
init() {
add_action("use", "drink");
}
use(arg){
object tp;
tp = this_player();
if(!arg || arg != "wine"){
        return 0;
} else {
if(!tp->eat_food(-8)){
        return 1;
}else{
        if(arg == "wine"){
drinks=drinks - 1;
this_player()->heal_self(19);
        write("You drink some wine. *Bleech!* It tastes like vinegar!\n"+
	"There are ["+drinks+"] servings left.\n");
        say(capitalize(tp->query_name()) + " guzzles some wine.\n");
if(drinks == 0){
        destruct(this_object());
        write("You finish off the bottle, and smash it to bits.\n");
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
