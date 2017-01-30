#include "std.h"
int drinks, price;

id(str) { return str == "turkey"; }

reset(arg) 
{
    if (!arg) drinks = 100;
    price = drinks * 150; 
}

long() 
{
        write("This is a tremendously large Thanksgiving turkey with all\n"+
              "the hardcore trimmings. There are "+drinks+" bites left.\n"+
	          "Remember what this day is for. Being thankful for being alive.\n");
}
short() { return "A gigantic turkey (" + drinks + " bites left)"; }
query_save_flag() {return 1;}
query_value()
{ return price; }
init() { add_action("use", "eat");
use(arg){
object tp;
tp = this_player();
if(!tp) return 1;
if(!arg || arg != "turkey"){
        return 0;
} else {
if(!tp->eat_food(4)){
        return 1;
} else {
        if(arg == "turkey"){
drinks=drinks - 1;
tp->heal_self(40);
        write("You hold the turkey to your face and gnaw off a chunk of it.\n"+
              "There are " +drinks+" bites left.\n");
        say(capitalize(tp->query_name()) + " gnaws off a chunk of turkey and swallows it without chewing.\n");
if(drinks < 1){
        destruct(this_object());
        write("You realize that the turkey is down to nothing more than bones now.\n");
   say(tp->query_name()+" finishes off a WHOLE turkey!\n");
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
