#include "std.h"
#include "/players/hippo/bs.h"
id(str) {return str == "cp"; }
long() {
   write("A bit of creatine phosphate, will probably make you any stronger."+BS);
}
short() {
   return "A bit of CP";
}
query_value()
{
   return 420;
}
init() {
   add_action("eat","eat");
}
eat(arg){
   if(arg!="cp") {
   notify_fail("You don't have that, man! You should wish you had that."+BS);
		return 0;
		}
this_player()-> add_hit_points(7);
   say(this_player()->query_name()+" eats some strange cp... whatever that may be."+BS);
   write("Oeps.. that is a strange taste.. but you feel you are stronger than before"+BS);
	        destruct(this_object());
	return 1;
        }
get() {
    return 1;
}
query_weight() {
   return 1;
}
