#include "std.h"
int drinks, price;

id(str) { return str == "fire water"; }

reset(arg) {
	if (!arg) drinks = 7;
	price = drinks * 200;
}

long() {
	write("In the middle ages, fear and magic ruled the land.  Against a backdrop of\n"+
"marauding barbarians, alchemists were on an endless quest to find the Elixer\n"+
"of Life.  According to the legend, this potion would cure all ailments and\n"+
"lengthen life.\n"+
"Their powerful magic drink is said to have caused water to burn and man to\n"+
"breath fire.  Although no one knows whether life was lengthened, many claimed\n"+
"to have seen visions like dragons breathing flames.  They called their potion\n"+
"Fire Water.  There are "+drinks+" shots left.\n");
}

short() {
	return "A bottle of Fire Water";
}

query_value()
{
    return price;
}

init() {
    add_action("use"); add_verb("drink");
}

use(arg){
object tp;
tp = this_player();
if(!arg || arg != "fire water"){
	return 0;
} else {
if(!tp->drink_alcohol(12)){
	return 1;
}else{
	if(arg == "fire water"){
drinks=drinks - 1;
this_player()->heal_self(random(16));
	write("You see a vision of a dragon breathing flames.\n"+
"There are "+drinks+" shots left.\n");
	say("You have sudden fears of dragons breathing flames as "+capitalize(tp->query_name())+ "\n"+
"slams a shot of Fire Water.\n");
if(drinks == 0){
	destruct(this_object());
	write("You smash the bottle on the ground as you finish off the firewater.\n");
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
query_save_flag() { return 1; }
