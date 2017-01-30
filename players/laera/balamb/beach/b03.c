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
	"   Curving gently to the northeast, the beach continues northward.\n" +
	"The ocean laps quietly along the eastern shore.  Pieces of seaweed \n" +
	"gather around a half-buried piece of driftwood brought in by the \n" +
	"tides.  A slight breeze blows in off the ocean, creating small \n" +
	"whitecaps that wash up against the sand.\n";

	items =
	({
		"up","A few small clouds drift into the sky",
		"sky","A few small clouds drift into the sky",
		"down","Fine, white sand",
		"ground","Fine, white sand",
		"sand","Fine, white sand",
		"sun","A bright yellow sun shines above",
		"ocean","Clear and blue, the ocean spans far into the eastern horizon",
		"water","Clear and blue, the ocean spans far into the eastern horizon",
		"beach","A peaceful beach, unmarred by the ravages of civilization",
		"shore", "Smooth, dark sand meets the gentle ocean",
		"seaweed","Small pieces of aquatic plants have washed ashore",
		"driftwood","A large piece of wood, its edges smoothed by the water",
		"whitecaps","The water foams as it meets the sand",
	});

	set_listen("Waves lap softly against the sand.");
	set_smell("You take a deep breath of salty air.");

	dest_dir =
	({
		 BEACH + "b02.c","south",
		 BEACH + "b04.c","northeast",
		 BEACH + "b10.c","northwest",
		 BEACH + "b11.c","southwest",
	});

}
