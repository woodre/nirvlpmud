
#include "std.h"
int drinks, price;

id(str) { return str == "bottle"; }

reset(arg) {
        if (!arg) drinks = 7;
        price = drinks * 150;
}

long() {
  write("You have absolutely NO idea what this stuff is. If you're from\n"+
	"the United States or Europe, this stuff is in most of what you eat.\n"+
	"Not yet proven to be carcinogenic in laboratory animals, give it a\n"+
	"few years before the TRUTH is released. Ah heck, you only live once\n"+
	"anyway. You hope this stuff is spiked, at least...\n"+
	"There appear to be ["+drinks+"] sips left.\n");
}

short() {
     return "A bottle of partially hydrogenated soybean oil ["+drinks+"]";
}

query_save_flag() { return 1; }
query_value() { return price; }

init() {
#ifndef __LDMUD__ /* Rumplemintz */
    add_action("use"); add_verb("drink");
#else
  add_action("use", "drink");
#endif
}

use(arg){
object tp;
tp = this_player();
if(!arg || arg != "oil") {
        return 0;
} else {
if(!tp->eat_food(4)){
        return 1;
}else{
        if(arg == "oil") {
drinks=drinks - 1;
tp->heal_self(13);
        write("You take a gulp of some partially hydrogenated soybean oil. *JOY*\n"+
	"There appear to be ["+drinks+"] sips left.\n");
        say(capitalize(tp->query_name()) + " drinks some partially hydrogenated soybean oil.\n");
if(drinks == 0){
        destruct(this_object());
        write("You finish off bottle and chuck as far as you can throw...\n");
        tp->add_weight(-1);
                }
return 1;
                }
        }
}
}

get() { return 1; }

query_weight() { return 1; }
