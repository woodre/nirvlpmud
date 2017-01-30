/*Outside room 1*/

#define F1 "/players/laera/balamb/forests/forest1/"
#define BEACH "/players/laera/balamb/beach/"
#define PLAINS "/players/laera/balamb/plains/"

inherit "/players/laera/cforest/hroom.c";
#include "/players/laera/closed/ansi.h"
#include "/players/laera/closed/ldef.h"

reset(arg) {

	if(!present("blue dragon"))
	move_object(clone_object("/players/laera/balamb/forests/npc/bdragon.c"),this_object());

   if(arg) return;
   set_light(1);

short_desc = CYN + "Balamb - Eastern Forest" + OFF;
long_desc =
	"   A tall, silent forest rises up out of the plains.  The trees grow\n" +
	"close together, discouraging entrance.  Sunlight creeps its way \n" +
	"through the trees, feeding the plant life that grows on the forest\n" +
	"floor.  The peaceful calm of the plains seems to physically end at\n" +
	"the edge of the forest as an evil stillness emanates from inside.\n";

   items = ({
     "up", 			"The sky can be glimpsed through the tops of the trees",
     "sky", 		"A clear blue sky is glimpsed through the tops of the trees",
     "down", 		"Sturdy new grass struggles among seedlings and hardy flowers to grow\n" +
     		 		"sparsely in the hard packed earth",
     "ground",		"Sturdy new grass struggles among seedlings and hardy flowers to grow\n" +
     		  		"sparsely in the hard packed earth",
     "floor",		"Sturdy new grass struggles among seedlings and hardy flowers to grow\n" +
     		  		"sparsely in the hard packed earth",
     "forest edge",	"Sturdy new grass struggles among seedlings and hardy flowers to grow\n" +
     		  		"sparsely in the hard packed earth",
     "edge",		"Sturdy new grass struggles among seedlings and hardy flowers to grow\n" +
     		  		"sparsely in the hard packed earth",
     "sunlight",	"Strong sunlight works its way through the trees",
     "sun",			"The trees block the view of the sun",
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
     "maple", 		"The maples look ragged and several have holes in them that look.\n"+
     				"like mouths frozen in silent screams",
     "maples", 		"The maples look ragged and several have holes in them that look.\n"+
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
});

set_listen("You listen carefully but hear nothing but an eerie stillness.");

set_smell("The smells of the nearby ocean are overwhelmed by the dank, musty odor\n" +
		  "of the forest.");

   dest_dir = ({
        F1 + "f160.c", "northeast",
        F1 + "f118.c", "northwest",
        F1 + "f116.c", "east",
});

}

