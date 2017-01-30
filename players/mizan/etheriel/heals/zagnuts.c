#include "std.h"
int drinks, price;
id(str) { return str == "bar" || str =="zagnuts" || str == "candy"; }
reset(arg) {        if (!arg) drinks = 6;
        price = drinks * 150; }
long() {
        write("This is a bar of Zagnuts candy. It's crispy, crunchy, and made\n"+
	"with real chocolate and fruit flies.\n"+
	"There are  ["+drinks+"] bites left.\n");
}
short() { return "A Zagnuts candy bar"; }
query_save_flag() {return 1;}
query_value()
{ return price; }
init() { add_action("use", "eat"); }
use(arg){
object tp;
tp = this_player();
  if(!arg || arg != "bar") {
        return 0;
} else {
if(!tp->eat_food(6)){
        return 1;
} else {
    if(arg == "bar") {
drinks=drinks - 1;
tp->heal_self(8);
        write("You take a bite of the candy bar. Mmmmmmm. It tastes good except for\n"+
	"The little 'specular' things in it. There are ["+drinks+"] bites left.\n");
        say(capitalize(tp->query_name()) + " takes a bite of a Zagnuts candy bar.\n");
if(drinks < 1){
        write("You finish off the bar, but not before reading the ingredients list...\n"+
	"Chocolate, peanuts, rice crisps, and Mediterranean fruit flies.\n");
        say(capitalize(tp->query_name()) + " tosses an empty wrapper away. Litterbug!\n");
tp->add_weight(-1);
        destruct(this_object());
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
