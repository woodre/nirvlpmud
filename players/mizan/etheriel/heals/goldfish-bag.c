
#include "std.h"
int drinks, price;

id(str) { return str == "bag" || str == "goldfish"; }

reset(arg) {
        if (!arg) drinks = 12;
        price = drinks * 60;
}

long() {
        write("This is clear plastic bag filled with goldfish. Fish are high\n"+
	"in protein. Fish are healthy, expecially when eaten raw. the command\n"+
	"'swallow fish' or 'eat fish' will work in either case.\n"+
	"There are ["+drinks+"] fish left.\n");
}

short() {
     return "A plastic bag filled with goldfish";
}

query_save_flag() { return 1; }
query_value() { return price; }

init() {
add_action("use", "eat");
}

use(arg){
object tp;
tp = this_player();
if(!arg || arg != "fish"){
        return 0;
} else {
if(!tp->eat_food(2)){
        return 1;
}else{
        if(arg == "fish"){
drinks=drinks - 1;
tp->heal_self(8);
        write("You swallow a goldfish whole! Yum. There are ["+drinks+"] fish left.\n");
        say(capitalize(tp->query_name()) + " swallows a live goldfish.\n");
if(drinks == 0){
        destruct(this_object());
        write("You finish off the bag and drink up the water.\n");
        tp->add_weight(-1);
                }
return 1;
                }
        }
}
}

get() { return 1; }

query_weight() { return 1; }
