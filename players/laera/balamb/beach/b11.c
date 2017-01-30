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
	"   West of here, the road to Balamb Garden winds its way through the\n" +
	"plains.  The beach continues to the east, where waves wash over the\n" +
	"sand.  High grass sways gently as the beach meets the plains.  Forests\n" +
	"can be seen to the north and to the west.  The town of Balamb is to the\n" +
	"south.\n";

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
		"grass","Tall blades of grass sway in the breeze",
		"balamb garden","The sun glints off a large structure that sits in the middle of the\n" +
		"plains",
		"garden","The sun glints off a large structure that sits in the middle of the\n" +
		"plains",
		"balamb","The stucco walls surrounding the town of Balamb can be seen to the\n" +
		"south",
		"waves","Gentle waves lap softly up against the sand",
		"road","Paved and somewhat out of place, the road winds through the\n" +
		"plains toward Balamb Garden",
	});

	set_listen("Waves lap softly against the sand.");
	set_smell("You take a deep breath of salty air.");

	dest_dir =
	({
		 BEACH + "b10.c","north",
		 BEACH + "b12.c","south",
		 BEACH + "b02.c","southeast",
		 BEACH + "b03.c","northeast",
	});

}
