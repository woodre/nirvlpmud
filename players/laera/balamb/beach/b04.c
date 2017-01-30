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
	"   The beach continues to curve to the northeast, gently jutting into\n" +
	"into the ocean.  Sunlight glints off the sand, warming it.  The \n" +
	"outline of a forest can be seen in the plains to the northwest.  A\n" +
	"lone bird soars in the sky above the water\n";

	items =
	({
		"up","A bird is silhouetted against the sky",
		"sky","A bird is silhouetted against the sky",
		"down","Fine, white sand",
		"ground","Fine, white sand",
		"sand","Fine, white sand",
		"sun","A bright yellow sun shines above",
		"ocean","Clear and blue, the ocean spans far into the eastern horizon",
		"water","Clear and blue, the ocean spans far into the eastern horizon",
		"beach","A peaceful beach, unmarred by the ravages of civilization",
		"forest","A large forest can be glimpsed to the northwest",
		"plains","A large plain can be seen in the distance",
		"bird","Flying high above, a hawk searches the water's surface for food",
	});

	set_listen("Waves lap softly against the sand.");
	set_smell("You take a deep breath of salty air.");

	dest_dir =
	({
		 BEACH + "b05.c","northeast",
		 BEACH + "b09.c","northwest",
		 BEACH + "b03.c","southwest",
	});

}
