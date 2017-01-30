/* entry.c */

#define tp this_player()->query_name()
#define ROOT "/players/daranath/bugs/"
#include <ansi.h>

inherit "room/room";

reset(int arg){
if(!arg){
	set_light(1);
	short_desc=(HIG+"The "+HIM+"Gypsy "+HIG+"Grasslands"+NORM);
	long_desc=
	"You feel strange after stepping thru the portal, something seems not  \n" +
   "quite right. You find youself in a rather large encampment. You are \n" +
	"standing on a dirt path between two tents. There is a strange forest off \n" +
   "in the distance to the north.\n";

	items=({
		"tent","A dark green tent is erected here, it looks to be of military style.",
		"forest","A strange forest looms in the distance, but the trees don't look quite right",
		"trees","The trees are too far away to make out clearly",
		"encampment","A small camp consisting of several dark green tents",
		"portal","The portal glows with a soft alluring light",
		"path","The path leads off to the north and is composed of a think dirt",
		"dirt","There is something odd about the dirt, but you can't quite figure \n"+
			   "it out",
			});
	
	dest_dir=({
		ROOT+"tent1a.c","west",
		ROOT+"tent2a.c","east",
		ROOT+"path1.c","north",
           "/room/deep_forest1.c","leave",
		
			});
		}
	}
	
	init(){
		::init();
	add_action("search","search");
		}

	search() {
write("You find nothing.\n");
		return 1;
		}
