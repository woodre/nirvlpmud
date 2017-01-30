#include "std.h"
#include "/players/hippo/bs.h"
int drinks, price;
string level;

id(str) { return str == "lymphe";}

reset(arg) {
   if(!arg) drinks =5;
   price = drinks * 560;
}
long() {
   write("You got "+drinks+" sips of lymphe left."+BS);
}
short() {
   return "LYMPHE";
}
query_value()
{
    return price;
}
init() {
   add_action("drink","drink");
}
drink(arg) {
object tp;
tp = this_player();
if(arg!="lymphe"){
   notify_fail("You'd better check your stuff, fellow.. \n"+
      "You don't have that.\n");
	return 0;
}
drinks=drinks - 1;
this_player()->heal_self(45);
write("You feel a lot better.. a lot! \n"+
   "And you don't feel intox at all ??!!?? \n");
   say(capitalize(tp->query_name()) + " drinks some LYMPHE."+BS);
if(drinks == 0){
	destruct(this_object());
   write ("You just sipped the last lymphe.\n");
		}
return 1;
		}

get() {
    return 1;
}
query_weight() {
   return 1;
}
