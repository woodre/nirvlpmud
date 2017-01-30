#include "std.h"
int drinks, price;
id(str) { return str == "cow"; }
reset(arg) {        if (!arg) drinks = 12;
        price = drinks * 150; }
long() {
        write("This is a portable cow with "+drinks+" servings left.\n"+
	"Milk... it does a body good!\n");
}
short() { return "A portable cow"; }
query_save_flag() {return 1;}
query_value()
{ return price; }
/* Rump
init() { add_action("use"); add_verb("milk"); }
*/
init() { add_action("use", "milk"); }
use(arg){
object tp;
tp = this_player();
if(!tp) return 1;
if(!arg || arg != "cow"){
        return 0;
} else {
if(!tp->drink_soft(4)){
        return 1;
} else {
        if(arg == "cow"){
drinks=drinks - 1;
tp->heal_self(10);
        write("You noisily chug some milk. There are "+drinks+" servings left.\n");
        say(capitalize(tp->query_name()) + " milks a portable cow, and moos contentedly.\n");
if(drinks < 1){
        destruct(this_object());
        write("You realize that the cow is empty and you punt it clear across the mud.\n");
   say(tp->query_name()+" finishes off a portable cow.\n");
tp->add_weight(-2);
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
    return 2;
}
