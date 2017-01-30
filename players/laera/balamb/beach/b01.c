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
	"   Fine white sand lines the beach.  Small rocks have been washed\n" +
	"ashore, worn smooth by gentle ocean currents.  Looking eastward, \n" +
	"nothing can be seen but calm, clear ocean as far as the eye can see.\n" +
	"The beach stretches northward.\n";

	items =
	({
		"up","The sun shines in a clear blue sky",
		"sky","The sun shines in a clear blue sky",
		"down","Fine, white sand",
		"ground","Fine, white sand",
		"sand", "Fine, white sand",
		"rocks","Multicolored pebbles, worn smooth by the water",
		"ocean","Clear and blue, the ocean spans far into the eastern horizon",
		"beach","A peaceful beach, unmarred by the ravages of civilization",

	});

	set_listen("Waves lap softly against the sand.");
	set_smell("You take a deep breath of salty air.");

	dest_dir =
	({
		 BEACH + "b02.c","north",
		 BEACH + "b12.c","northwest",
		 "/players/laera/jump.c","out",
	});

}
