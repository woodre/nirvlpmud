#include "std.h"
int drinks, price;

id(str) { return str == "tank" || str == "juice"; }

reset(arg) {
        if (!arg) drinks = 20;
        price = drinks * 150;
}

long() {
  write("This is a big plastic tank filled with a thick blue juice. \n"+
	"It smells pretty good, and should if taste as good as it smells,\n"+
	"that would make your day. It looks very heavy.\n");
    write("There are [" + drinks + "] servings left.\n");
}

short() {
     return "A tank of Squishberry juice ["+drinks+"]";
}

query_save_flag() { return 1; }
query_value() { return price; }

init() {
    add_action("use","drink");
}

use(arg){
object tp;
tp = this_player();
  if(!arg) return 0;
  if(arg != "juice") return 0;
if(!tp->drink_soft(10)){
        return 1;
}else{
if(arg == "juice") {
drinks=drinks - 1;
tp->heal_self(31);
        write("You put the tank to your mouth and chug... Ahh!\n"+
	"There are ["+drinks+"] servings left.\n");
        say(capitalize(tp->query_name()) + " raises a HUGE tank and slurps some stuff from it.\n");
if(drinks == 0){
        destruct(this_object());
        write("You finish off the tank and toss it away.\n");
        tp->add_weight(-4);
                }
return 1;
                }
        }
}

get() { return 1; }

query_weight() { return 4; }
