#include "/players/hippo/bs.h"
id(str) {return str == "enzymes"; }
long() {
   write("These enzymes might give you a lot of activity."+BS);
}
short() {
   return "Activation enzymes";
}
query_value()
{
   return 420;
}
init() {
   add_action("eat","eat");
}
eat(arg){
   if(arg!="enzymes") {
   notify_fail("You don't have that, man! You should wish you had that."+BS);
		return 0;
		}
this_player()->add_spell_points(7);
   say(this_player()->query_name()+" absorbs some enzymes"+BS);
   write("Aaaaahh.. you liked that! You feel the energy in your life comes back!"+BS);
	        destruct(this_object());
	return 1;
        }
get() {
    return 1;
}
query_weight() {
   return 1;
}
