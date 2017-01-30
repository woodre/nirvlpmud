#define BEACH "/players/laera/balamb/beach/"

inherit "/players/laera/cforest/hroom.c";
#include "/players/laera/closed/ansi.h"
#include "/players/laera/closed/ldef.h"

reset(arg)
{
	if(arg) return;

	set_light(1);
	short_desc = CYN + "Balamb - On the Beach" + OFF;
	long_desc =
	"   Stucco walls surround the town of Balamb to the south.  The grass\n" +
	"has been trimmed this close to the city, an inviting welcome to its \n" +
	"many visitors.  A large forest looms to the west and to the north, a \n" +
	"a smaller forest is seen.  The beach lies to the east.\n";

	items =
	({
		"up","The sun shines in a clear blue sky",
		"sky","The sun shines in a clear blue sky",
		"down","A carpet of long grasses covers the ground",
		"ground","A carpet of long grasses covers the ground",
		"sand","The sand here is dark, moist and cool",
		"sun","A bright yellow sun shines above",
		"ocean","Clear and blue, the ocean spans far into the eastern horizon",
		"water","Clear and blue, the ocean spans far into the eastern horizon",
		"beach","A peaceful beach, unmarred by the ravages of civilization",
		"forest","Two forests, one to the north and the other to the west, can be seen\n" +
		"here",
		"forests","Two forests, one to the north and the other to the west, can be seen\n" +
		"here",
		"plains","A large plain can be seen in the distance",
		"grass","The short green grass is well maintained this close to the city",
		"balamb","The stucco walls surrounding the town of Balamb can be seen to the\n" +
		"south",
		"city","The stucco walls surrounding the town of Balamb can be seen to the\n" +
		"south",
		"walls","A stucco wall that surrounds three sides of Balamb.",
	});

	set_listen("Waves lap softly against the sand.");
	set_smell("You take a deep breath of salty air.");

	dest_dir =
	({
		 BEACH + "b11.c","north",
		 BEACH + "b01.c","southeast",
		 BEACH + "b02.c","northeast",
	});

}
