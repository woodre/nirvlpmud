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
	"   To the east, the ocean gently meets a white sand beach.  A gentle\n" +
	"breeze can be felt as it blows over the plains.  A forest can be\n" +
	"glimpsed to the northwest.  Balamb Garden can be made out to the\n" +
	"west and to the south, in the distance, is the town of Balamb.\n";

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
		"forest","A large forest can be glimpsed to the northwest",
		"plains","A large plain can be seen in the distance",
		"grass","Tall blades of grass sway in the breeze",
		"balamb garden","The sun glints off a large structure that sits in the middle of the\n" +
		"plains",
		"garden","The sun glints off a large structure that sits in the middle of the\n" +
		"plains",
		"balamb","The stucco walls surrounding the town of Balamb can be seen to the\n" +
		"south",
		"town","The small harbour town of Balamb",
	});

	set_listen("Waves lap softly against the sand.");
	set_smell("You take a deep breath of salty air.");

	dest_dir =
	({
		 BEACH + "b09.c","northeast",
		 BEACH + "b03.c","southeast",
		 BEACH + "b11.c","south",
	});

}
