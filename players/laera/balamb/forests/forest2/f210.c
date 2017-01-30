/*Outside room 2*/

#define F1 "/players/laera/balamb/forests/forest2/"
#define BEACH "/players/laera/balamb/beach/"
#define PLAINS "/players/laera/balamb/plains/"

inherit "/players/laera/cforest/hroom.c";
#include "/players/laera/closed/ansi.h"
#include "/players/laera/closed/ldef.h"

reset(arg) {

	if(!present("bite bug"))
	move_object(clone_object("/players/laera/balamb/forests/npc/bite.c"),this_object());
	move_object(clone_object("/players/laera/balamb/forests/npc/bite.c"),this_object());

   if(arg) return;
   set_light(1);

short_desc = CYN + "Balamb - Western Forest" + OFF;
long_desc =
	"   Tall trees loom up and out of the grasses of the peaceful plains.\n" +
	"Darkness envelops the forest like a thick cloud, blocking the view \n" +
	"further than a few feet into the forest.  Small plants attempt to grow\n" +
	"here and there in the unfriendly ground, only to be choked by the \n" +
	"sinister stillness of the forest.\n";

   items = ({
     "up", 			"The sky can be glimpsed through the tops of the trees",
     "sky", 		"A clear blue sky is glimpsed through the tops of the trees",
     "down", 		"Sturdy new grass struggles among seedlings and hardy flowers to grow\n" +
     		 		"sparsely in the hard packed earth",
     "ground",		"Sturdy new grass struggles among seedlings and hardy flowers to grow\n" +
     		  		"sparsely in the hard packed earth",
     "floor",		"Sturdy new grass struggles among seedlings and hardy flowers to grow\n" +
     		  		"sparsely in the hard packed earth",
     "sunlight",	"Strong sunlight works its way through the trees",
     "forest",		"Gnarled oaks and twisted maples grow closely together, entwining their\n" +
     				"branches together near their tops to block most of the sunlight",
     "trees", 		"Gnarled oaks and twisted maples grow closely together, entwining their\n" +
     				"branches together near their tops to block most of the sunlight",
     "tree", 		"Gnarled oaks and twisted maples grow closely together, entwining their\n" +
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
     "plant life",	"Sturdy new grass struggles among seedlings and hardy flowers to grow\n" +
     		  		"sparsely in the hard packed earth",
     "plant",		"Sturdy new grass struggles among seedlings and hardy flowers to grow\n" +
     		  		"sparsely in the hard packed earth",
     "plants",		"Sturdy new grass struggles among seedlings and hardy flowers to grow\n" +
     		  		"sparsely in the hard packed earth",
     "life",		"Sturdy new grass struggles among seedlings and hardy flowers to grow\n" +
     		  		"sparsely in the hard packed earth",
     "grass", 		"Sparse shoots of grass struggle to grow in the hard packed earth",
     "grasses",		"Tall thin grass blankets the plains",
     "seedlings",	"Tiny trees struggle to reach up to the sunlight",
     "flowers", 	"Crocuses attempt to peek up through the earth, too weak to survive",
     "crocuses",	"Weak from malnutrition, these flowers seldom make it to bloom",
     "plains",		"Tall grasses gently blow in the breeze",
     "darkness",	"It is hard to make out anything beyond a few feet from the edge of\n" +
     				"the forest",
     "cloud",		"It is hard to make out anything beyond a few feet from the edge of\n" +
     				"the forest",
});

set_listen("You listen carefully but hear nothing but an eerie stillness.");

set_smell("The smells of the nearby ocean are overwhelmed by the dank, musty odor\n" +
		  "of the forest.");

   dest_dir = ({
	   F1 + "f237.c", "northeast",
	   F1 + "f209.c", "east",
	   F1 + "f211.c", "southwest",
	   F1 + "f242.c", "west",
	   F1 + "f236.c", "north",
});

}

