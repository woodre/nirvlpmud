/*
*      Function:
*      Change History:
*/
#include <ansi.h>
inherit "/room/room";

int found;

reset(arg)
{
::reset(arg);

if(arg) return;

set_light(1);

found = 0;

short_desc = ""+HIB+"A men's room"+NORM+"";

long_desc =
	"You have entered a living hell. The entire bathroom is completely\n"+
	"coated with fresh, dripping "+RED+"blood"+NORM+". There are over a dozen bodies\n"+
	"on the floor, also fresh...and in pieces. The stalls have been\n"+
	"piled high with bodyparts, even fingers and other small parts\n"+
	"in the urinals and one of the sinks.\n";
	
move_object(clone_object("/players/chip/mobs/movies/customer.c"));
move_object(clone_object("/players/chip/mobs/movies/customer.c"));

add_smell("air", "The smell of blood is overwhelming.");

items =
({
	"blood",
	"It is fresh, wet, and all over everything. This makes it\n"+
	"slightly more difficult to walk properly",
	"bodies",
	"There must be over a dozen, and they have all been mutilated\n"+
	"beyond recognition",
	"stalls",
	"They are each piled up with many bodyparts, so much you cannot\n"+
	"see the toilets. You feel sick to your stomach suddenly",
	"bodyparts",
	"There are some scattered about on the floor, though the\n"+
	"majority are all crammed into the stalls",
	"fingers",
	"Amongst other parts, these fingers help fill the urinals and\n"+
	"one of the two sinks. There is very strangely no blood or\n"+
	"anything on the mirror on the right",
	"urinals",
	"Just your average urinal, with the optional blood and gore\n"+
	"of small severed appendages",
	"sinks",
	"This is where costomers are given the opportunity to clean\n"+
	"their hands after using the bathroom. No point in trying to\n"+
	"now as you'd only end up getting more blood on you",
	"right mirror",
	"It is still very clean even in all of this bloody mess",
	});

dest_dir =
({
	"/players/chip/room/movies/room7.c",     "southwest",
	});
		
}
void init(){::init();add_action("cmd_search", "search");}
status cmd_search(string str){
if(!str){
write("Can your stomach really handle doing that?\n");
return 1;
}
if(str == "sink" && found){
write("It looks like someone was already digging in it. Surely there's no point now.\n");
return 1;
}
if(str == "sink" && !found){
write("You start to dig in the mess of severed appendages...and find a "+HIY+"gold"+NORM+" ring.\n");
move_object(clone_object("/players/chip/items/movies/gold_ring.c"), this_object());
found = 1;
return 1;
}
}
