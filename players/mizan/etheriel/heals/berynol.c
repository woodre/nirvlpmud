
#include "std.h"
int drinks, price;

id(str) { return str == "flask" || str == "berynol"; }

reset(arg) {
        if (!arg) drinks = 4;
        price = drinks * 150;
}

long() {
  write("This is a small polycarbonate flask filled with a light blue liquid\n"+
	"that you figure is normally used to clean combs. However, there is a\n"+
	"label on the side that reads: 'Berynol [196] proof'.\n"+
	"There appear to be ["+drinks+"] drinks left.\n");
}

short() {
     return "A flask of Berynol";
}

query_save_flag() { return 1; }
query_value() { return price; }

init() {
/* Rump
add_action("use", "drink");
*/
  add_action("use", "drink");
}

use(arg){
object tp;
tp = this_player();
  if(!arg || arg != "berynol") {
        return 0;
} else {
if(!tp->drink_alcohol(29)){
        return 1;
}else{
    if(arg == "berynol") {
drinks=drinks - 1;
tp->heal_self(40);
        write("You take a sip and *UGH!* *GAG* Damn this stuff is strong!!\n"+
	"There appear to be ["+drinks+"] sips left.\n");
        say(capitalize(tp->query_name()) + " nearly chokes to death on some Berynol.\n");
if(drinks == 0){
        destruct(this_object());
        write("You finish off flask and punt it to oblivion.\n");
        tp->add_weight(-1);
                }
return 1;
                }
        }
}
}

get() { return 1; }

query_weight() { return 1; }
