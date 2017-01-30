#include "std.h"
#include "/players/hippo/bs.h"
int drinks, price;
string tdm;
 id(str) { return str == tdm; }

reset(arg) {
   if (!arg) drinks = 1;
   price = drinks * 1000;
   if (drinks == 3) tdm = "atp";
   if (drinks == 2) tdm = "adp";
   if (drinks == 1) tdm = "amp";
}
long() {
   write("Yes, this is adenosine tri/di/mono phosphate. (Choose yourself)"+BS+
         "Try to use it, when you are hurt."+BS);
}
short() {
   return "Some "+tdm;
}
query_value()
{
    return price;
}
init() {
   add_action("use","use");
}
use(arg){
	if(arg!=tdm) {
   notify_fail("I don't think you got that right now.. check your inventory!"+BS);
		return 0;
		}
	drinks=drinks-1;
	this_player()->heal_self(20);
        this_player()->drink_alcohol(7);
	write("You use an "+tdm+". You feel stronger now."+BS);
	say(this_player()->query_name() +" uses an "+tdm+" and looks stronger now."+BS);
	if (drinks == 2) tdm = "adp";
	if (drinks == 1) tdm = "amp";
	if(drinks == 0){
		write("As you finished your AMP, you have to get new heals. (or you got some?)"+BS);
	        destruct(this_object());
                }
	return 1;
        }

get() {
    return 1;
}

query_weight() {
   return 1;
}
