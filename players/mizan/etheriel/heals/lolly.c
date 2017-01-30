
#include "std.h"
int drinks, price;

id(str) { return str == "lolly" || str == "lollipop"; }

reset(arg) {
        if (!arg) drinks = 18;
        price = drinks * 150;
}

long() {
        write("This is a wonderfully sweet and tasty candy on a stick.\n"+
	"It seems to posess some kind of healing qualities...\n"+
        "Maybe you could 'lick' the lolly to get something out of it.\n"+
	"There are ["+drinks+"] licks left.\n");
}

short() {
     return "A multicolored lollipop [" + drinks + "]";
}

query_save_flag() { return 1; }
query_value() { return price; }

init() {
add_action("use", "lick");
}

use(arg){
object tp;
tp = this_player();
if(!arg) return 0;
if(arg == "lollipop" || arg == "lolly"){
if(!tp->eat_food(4)){
        return 1;
}else{
        if(arg == "lolly" || arg == "lollipop"){
drinks=drinks - 1;
tp->heal_self(13);
        write("You lick the lollipop and feel like dancing... *Yay*\n"+
        "There are ["+drinks+"] licks left.\n");
        say(capitalize(tp->query_name()) + " licks a multicolored lollipop.\n");
if(drinks == 0){
        destruct(this_object());
        write("You finish off the lolly and eat the stick by accident.\n");
        tp->add_weight(-1);
                }
return 1;
                }
        }
 }
}

get() { return 1; }

query_weight() { return 1; }
