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
	"   The beach stretches north toward the tip of the island.  Seashells\n" +
	"are scattered along the sand.  The sun shines brightly in the sky, \n" +
	"warming the water to the east.  Plains can be seen to the west and a\n" +
	"forest looms to the northwest.\n";

	items =
	({
		"up","The sun shines in a clear blue sky",
		"sky","The sun shines in a clear blue sky",
		"down","Fine, white sand",
		"ground","Fine, white sand",
		"sand","Fine, white sand",
		"seashells","Several shells, bleached white by the sun and worn smooth by the sand",
		"sun","A bright yellow sun shines above",
		"ocean","Clear and blue, the ocean spans far into the eastern horizon",
		"water","Clear and blue, the ocean spans far into the eastern horizon",
		"beach","A peaceful beach, unmarred by the ravages of civilization",
		"plains","A large plain can be seen in the distance",
		"forest","A large forest can be glimpsed to the northwest",

	});

	set_listen("Waves lap softly against the sand.");
	set_smell("You take a deep breath of salty air.");

	dest_dir =
	({
		 BEACH + "b03.c","north",
		 BEACH + "b01.c","south",
		 BEACH + "b11.c","northwest",
		 BEACH + "b12.c","southwest",
	});

}
