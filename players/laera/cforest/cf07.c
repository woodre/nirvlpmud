#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "/players/laera/cforest/hroom.c";
#include "/players/laera/ansi.h"

reset(arg) {
   if(arg) return;
   set_light(1);
   
   short_desc = "Domed Forest";
   long_desc = GRN+
"   Small boulders and bushes fill some of the gaps between the trees.\n"+
"Soft dark moss grows at the base of the trees and gently covers the \n"+
"tops of the boulders.  Small red and purple berries can barely be\n"+
"seen growing on the bushes.\n"+OFF;
   
   items = ({
     "up", "The sky can be glimpsed through the tops of the trees",
     "sky", "A clear blue sky is glimpsed through the tops of the trees",
     "down", "Thick grass grows on the forest floor",
     "ground", "Thick grass grows on the forest floor",
     "grass", "Tender green grass blankets the floor of the forest",
     "trees", "Tall oaks, sturdy maples and vibrant birch trees grow here, their tops\n"+
     "all reaching toward the center of the forest",
     "oak", "The tallest of the forest, their strong branches grow high above, each\n"+
     "filled with broad leaves and acorns",
     "oaks", "The tallest of the forest, their strong branches grow high above, each\n"+
     "filled with broad leaves and acorns",
     "maple", "The rough bark of the maples makes them a sturdy addition to the forest.\n"+
     "They proudly display their leaves",
     "maples", "The rough bark of the maples makes them a sturdy addition to the forest.\n"+
     "They proudly display their leaves",
     "birch", "The birch trees stand tall, their papery white bark contrasting the\n"+
     "maples and the oaks",
     "moss", "Soft and green, moss has spread across some of the boulders and the\n"+
     "bases of the trees",
     "boulders", "Granite boulders, both large and small, lay about the forest",
     "rocks","They aren't rocks, they are boulders...",
     "bush", "This small, green bush has many leaves.  On its branches grow tiny red\n"+
     "and purple berries",
     "bushes", "These small, green bushes have many leaves.  On their branches grow tiny red\n"+
     "and purple berries",
     "berry", "Tiny red and purple berries that aren't quite ripe yet.  Come back in\n"+
     "a month or so",
     "berries", "Tiny red and purple berries that aren't quite ripe yet.  Come back in\n"+
     "a month or so",
});
   
set_listen("You hear the soft sound of birds chirping.");
set_smell("The fragrance of wildflowers is in the air.");
   dest_dir = ({
"/players/laera/cforest/cf12.c","north",
"/players/laera/cforest/cf03.c","south",
"/players/laera/cforest/cf08.c","east",
"/players/laera/cforest/cf06.c","west",
});

}
