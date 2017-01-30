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
	"   A small strip of plains separates the beach from the forest to\n" +
	"the north.  To the east, a calm and gentle ocean laps up against\n" +
	"white sand.  Mountains, seen further north provide a backdrop for\n" +
	"the forest.\n" ;

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
		"peninsula","A small piece of the island juts gently into the ocean",
		"mountains","Tall, snow-capped mountains can be seen in the distance",
		"mountain range","Tall, snow-capped mountains can be seen in the distance",
	});

	set_listen("Waves lap softly against the sand.");
	set_smell("You take a deep breath of salty air.");

	dest_dir =
	({
		 BEACH + "b08.c","northeast",
		 BEACH + "b04.c","southeast",
		 BEACH + "b10.c","southwest",
	});

}
