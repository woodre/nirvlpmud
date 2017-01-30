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

short_desc = ""+HIB+"A ladies room"+NORM+"";

long_desc =
	"You've entered a surprisingly clean women's room in "+HIC+"Nirvana Cinemas"+NORM+".\n"+
	"There are four stalls here, as well as three sinks, each having a\n"+
	"mirror placed above it. For some reason, there are no soap or paper\n"+
	"towel dispensers in this restroom, even though there's a sign on the\n"+
	"wall by the sinks that states the ''proper'' handwashing procedures.\n";
	
add_smell("air", "It smells freshly cleaned.");
items =
({
	"stalls",
	"They are all empty, and the toilets look pretty clean for a\n"+
	"public restroom",
	"sinks",
	"Nearly spotless, these sinks are made for the handwashing\n"+
	"convenience of the customers who come here",
	"mirrors",
	"Each one you gaze into reveals some horridly hideous person",
	"sign",
	""+BLU+"PROPER HANDWASHING PROCEDURES"+NORM+"\n"+
	"1. "+HIB+"Wet hands"+NORM+"\n"+
	"2. "+HIB+"Rub on soap"+NORM+"\n"+
	"3. "+HIB+"Rinse soap off"+NORM+"\n"+
	"4. "+HIB+"Dry hands with a paper towel"+NORM+"",
	"toilets",
	"They look to be fairly clean and flushed, but you never know..",
	});

dest_dir =
({
	"/players/chip/room/movies/room7.c",     "west",
	});
		
}
void init(){::init();add_action("cmd_search", "search");}
status cmd_search(string str){
if(!str){
write("Well, there's only a few places that something could be hidden.\n");
return 1;
}
if(str == "toilet" && found){
write("Nothing more than a dog chain with nothing hooked to.\n");
return 1;
}
if(str == "toilet" && !found){
write("You fish around in the first toilet you see....and find a used tampon. Eww...\n");
move_object(clone_object("/players/chip/items/movies/tampon.c"), this_object());
dead = 1;
return 1;
}
}
