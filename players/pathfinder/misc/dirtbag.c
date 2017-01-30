#include "std.h"
int drinks, price;

id(str) { return str == "dirt" || str == "bag"; }

reset(arg) {
        if (!arg) drinks = 10;
        price = drinks * 150;
}

long() {
        write("This is a bag of dirt. For some unexplainable reason,\n"+
	"you have the urge to eat it...\n"+
	"There are ["+drinks+"] scoops left.\n");
}

short() {
     return "A bag of dirt";
}

query_save_flag() { return 1; }
query_value() { return price; }

init() {
    add_action("use","eat");
}

use(arg){
object tp;
tp = this_player();
if(!arg || arg != "dirt"){
        return 0;
} else {
if(!tp->eat_food(9)){
        return 1;
}else{
        if(arg == "dirt"){
drinks=drinks - 1;
tp->heal_self(31);
        write("You chomp on some dirt. Yum. There are ["+drinks+"] scoops left.\n");
        say(capitalize(tp->query_name()) + " chomps on some dirt.\n");
if(drinks == 0){
        destruct(this_object());
        write("You finish off the bag and toss it away.\n");
        tp->add_weight(-3);
                }
return 1;
                }
        }
}
}

get() { return 1; }

query_weight() { return 3; }
