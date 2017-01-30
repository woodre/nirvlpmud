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
	"   Moving further from the ocean, the high grass of the plains\n" +
	"grows thicker.  The trees of a forest can be seen to the north,\n" +
	"and beyond that, a high mountain range.  The crisp scent of the\n" +
	"ocean to the east fills the air.\n" ;

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
		"trees","A large forest can be glimpsed to the northwest",
		"plains","A large plain can be seen in the distance",
		"grass","Tall blades of grass sway in the breeze",
		"peninsula","A small piece of the island juts gently into the ocean",
		"mountains","Tall, snow-capped mountains can be seen in the distance",
		"mountain range","Tall, snow-capped mountains can be seen in the distance",
	});

	set_listen("Waves lap softly against the sand.");
	set_smell("You take a deep breath of salty air.");

	dest_dir =
	({
		 BEACH + "b07.c","northeast",
		 BEACH + "b05.c","southeast",
		 BEACH + "b09.c","southwest",
	});

}
