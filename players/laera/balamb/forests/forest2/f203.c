/*Outside room 3*/

#define F1 "/players/laera/balamb/forests/forest2/"
#define BEACH "/players/laera/balamb/beach/"
#define PLAINS "/players/laera/balamb/plains/"

inherit "/players/laera/cforest/hroom.c";
#include "/players/laera/closed/ansi.h"
#include "/players/laera/closed/ldef.h"

reset(arg) {
   if(arg) return;
   set_light(1);

short_desc = CYN + "Balamb - Western Forest" + OFF;
long_desc =
	"   Gnarled trees stand guard along the edge of the forest where it \n" +
	"meets the plains.  The roots of the trees grow up out of the ground\n" +
	"to twist and tangle around each other, nearly covering the barren \n" +
	"soil beneath.  Darkness hovers almost tangibly between the trees, \n" +
	"hiding what may lay in wait deeper in the forest.\n";

   items = ({
     "up", 			"The sky can be glimpsed through the tops of the trees",
     "sky", 		"A clear blue sky is glimpsed through the tops of the trees",
     "down", 		"The soil of the forest floor is dark and oily",
     "ground",		"The soil of the forest floor is dark and oily",
     "soil",		"The soil of the forest floor is dark and oily",
     "edge",		"The perimeter of the forest",
     "floor",		"Sturdy new grass struggles among seedlings and hardy flowers to grow\n" +
     		  		"sparsely in the hard packed earth",
     "sunlight",	"Strong sunlight works its way through the trees",
     "forest",		"Gnarled oaks and twisted maples grow closely together, entwining their\n" +
     				"branches together near their tops to block most of the sunlight",
     "trees", 		"Gnarled oaks and twisted maples grow closely together, entwining their\n" +
     				"branches together near their tops to block most of the sunlight",
     "tree", 		"Gnarled oaks and twisted maples grow closely together, entwining their\n" +
     				"branches together near their tops to block most of the sunlight",
     "roots",		"The roots of the trees are tangled and twisted together, and \n " +
     				"seemingly alive",
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
         F1 + "f204.c", "southeast",
         F1 + "f223.c", "south",
         F1 + "f222.c", "southwest",
         F1 + "f202.c", "west",
});

}

