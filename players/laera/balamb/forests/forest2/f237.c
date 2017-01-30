/*Inside room 5*/

#define F1 "/players/laera/balamb/forests/forest2/"
#define BEACH "/players/laera/balamb/beach/"
#define PLAINS "/players/laera/balamb/plains/"

inherit "/players/laera/cforest/hroom.c";
#include "/players/laera/closed/ansi.h"
#include "/players/laera/closed/ldef.h"

reset(arg) {

	if(!present("caterchipillar"))
	move_object(clone_object("/players/laera/balamb/forests/npc/cater.c"),this_object());

   if(arg) return;
   set_light(1);

short_desc = CYN + "Balamb - Western Forest" + OFF;
long_desc = BLU +
	"   Branches grow together here, entwining themselves as they crowd \n" +
	"over the path as if to keep anything from moving inside the forest.\n" +
	"The stillness and the silence of the forest encourages the taste of\n" +
	"fear, which the darkness feeds upon.\n" + OFF;

   items = ({
     "up", 			"The sky can be glimpsed through the tops of the trees",
     "sky", 		"A clear blue sky is glimpsed through the tops of the trees",
     "down", 		"All that you can make out is the dark hard packed earth of the path",
     "ground",		"All that you can make out is the dark hard packed earth of the path",
     "floor",		"All that you can make out is the dark hard packed earth of the path",
     "path",		"Very dark, hard packed earth that twists through the forest",
     "sun",			"The trees block the view of the sun and the sunlight is too weak to\n" +
     				"reach the path",
     "forest",		"Gnarled oaks and twisted maples grow closely together, entwining their\n" +
     				"branches together near their tops to block most of the sunlight",
     "tree",		"Gnarled oaks and twisted maples grow closely together, entwining their\n" +
     				"branches together near their tops to block most of the sunlight",
     "trees", 		"Gnarled oaks and twisted maples grow closely together, entwining their\n" +
     				"branches together near their tops to block most of the sunlight",
     "oak", 		"The tallest of the forest, their branches seem to reach out with \n"+
     				"gnarled fingers",
     "oaks", 		"The tallest of the forest, their branches seem to reach out with \n"+
     				"gnarled fingers",
     "maple", 		"The maples look ragged and several have holes in them that look\n"+
     				"like mouths frozen in silent screams",
     "maples", 		"The maples look ragged and several have holes in them that look\n"+
     				"like mouths frozen in silent screams",
     "branches",	"The branches of the trees reach out like boney fingers",
     "branch",		"The branches of the trees reach out like boney fingers",
     "plant life",	"Thick spongy moss grows along the sides of the path, but its felt\n" +
     				"more than seen",
     "plant",		"Thick spongy moss grows along the sides of the path, but its felt\n" +
     				"more than seen",
     "plants",		"Thick spongy moss grows along the sides of the path, but its felt\n" +
     				"more than seen",
     "life",		"Thick spongy moss grows along the sides of the path, but its felt\n" +
     				"more than seen",
     "moss",		"You can't make out its color, but its texture is rough and slimy",
     "darkness",	"Thick and palpable, as though it has a life of its own",
     "ears",			"You can't look at your ears without a mirror",
     "travellers",	"There is no one here but you",
     "air",			"It's air.  Come on now, feel silly",
});

set_listen("You listen carefully but hear nothing but an eerie stillness.");

set_smell("The forest smells dank and musty, but there is an underlying aroma of\n" +
		   "blood that nearly overwhelms you.");

   dest_dir = ({
        F1 + "f208.c", "east",
        F1 + "f209.c", "south",
        F1 + "f210.c", "southwest",
        F1 + "f236.c", "west",
        F1 + "f206.c", "northwest",
        F1 + "f207.c", "north",
});

}

