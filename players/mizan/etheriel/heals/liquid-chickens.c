#include "std.h"
int drinks, price;
id(str) { return str == "chickens" || str == "liquid chickens" || str == "chicken" || str == "carton"; }
reset(arg) {
  if (!arg) drinks = 12;
  price = drinks * 50; }
long() {
        write("This is styrofoam carton filled with liquid chickens.\n"+
	"They appear to be normal Grade AA eggs, but NO! They're liquid\n"+
	"chickens as long as you are in Mizan's domain. To ingest one simply\n"+
	"type 'swallow egg'.\n"+
	"There are ["+drinks+"] liquid chickens left.\n");
}
short() { return "A carton of liquid chickens"; }
query_save_flag() {return 1;}
query_value()
{ return price; }
init() { add_action("use", "swallow");
use(arg){
object tp;
tp = this_player();
if(!arg || arg != "egg"){
        return 0;
} else {
if(!tp->eat_food(2)){
        return 1;
} else {
        if(arg == "egg"){
drinks=drinks - 1;
tp->heal_self(10);
        write("You crack open an egg and slurp its contents. Yum!\n");
        say(capitalize(tp->query_name()) + " slurps up a liquid chicken.\n");
if(drinks == 0){
        destruct(this_object());
        write("You swallowed the last chicken and smash the styrofoam carton into pieces.\n");
        say(capitalize(tp->query_name()) + " finishes off a carton of liquid chickens.\n");
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
