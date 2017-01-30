#define BEACH "/players/laera/balamb/beach/"

inherit "/players/laera/cforest/hroom.c";
#include "/players/laera/closed/ansi.h"
#include "/players/laera/closed/ldef.h"

reset(arg)
{
	if(!present("fastiticalon"))
	move_object(clone_object("/players/laera/balamb/beach/npc/fast.c"),this_object());
	if(!present("fastiticalon-F"))
	move_object(clone_object("/players/laera/balamb/beach/npc/fastf.c"),this_object());
	if(arg) return;

	set_light(1);
	short_desc = CYN + "Balamb - On the Beach" + OFF;
	long_desc =
	"   As the beach begins to meet the plains, small bunches of grass dot\n" +
	"the firm, moist sand.  The forest to the northwest can be seen quite\n" +
	"clearly from here, separated by a small stretch of plains.  Toward\n" +
	"the northeast, the ocean disappears around a small peninsula.\n";

	items =
	({
		"up","The sun shines in a clear blue sky",
		"sky","The sun shines in a clear blue sky",
		"down","The sand here is dark, moist and cool",
		"ground","The sand here is dark, moist and cool",
		"sand","The sand here is dark, moist and cool",
		"sun","A bright yellow sun shines above",
		"ocean","Clear and blue, the ocean spans far into the eastern horizon",
		"water","Clear and blue, the ocean spans far into the eastern horizon",
		"beach","A peaceful beach, unmarred by the ravages of civilization",
		"forest","A large forest can be glimpsed to the northwest",
		"plains","A large plain can be seen in the distance",
		"grass","Tall blades of grass grows in bunches in the sand",
		"peninsula","A small piece of the island juts gently into the ocean",
	});

	set_listen("Waves lap softly against the sand.");
	set_smell("You take a deep breath of salty air.");

	dest_dir =
	({
		 BEACH + "b06.c","northeast",
		 BEACH + "b08.c","northwest",
		 BEACH + "b04.c","southwest",
	});

}
