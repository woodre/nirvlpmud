#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "/players/laera/cforest/hroom.c";
#include "/players/laera/ansi.h"
reset(arg) {
if(!present("chicobo"))
move_object(clone_object("/players/laera/cforest/NPC/chubchic.c"),this_object());
   if(arg) return;
   set_light(1);
   
   short_desc = "Domed Forest";
   long_desc = GRN+
"   Tall, leafy, trees grow abundantly in this oddly shaped forest.\n"+
"The soft sounds of birds chirping playfully can be heard throughout \n"+
"the area.  Tender grass grows underfoot and wildflowers can be seen\n"+
"here and there, growing happily.\n"+OFF;
   
   items = ({
     "up", "The sky can be glimpsed through the tops of the trees",
     "sky", "A clear blue sky is glimpsed through the tops of the trees",
     "down", "Thick grass grows on the forest floor",
     "ground", "Thick grass grows on the forest floor",
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
     "grass","Tender green grass blankets the floor of the forest",
     "wildflowers", "Purple violets, fresh crocuses and bright daisies grow between the\n"+
     "trees",
     "flowers", "Purple violets, fresh crocuses and bright daisies grow between the\n"+
     "trees",
     "violets", "Small and delicate, these little flowers seem content in this forest",
     "daisies", "Bright white with yellow centers, these flowers invite you to explore\n"+
     "the forest",
     "crocuses", "Red, blue and pink crocuses peek through the grass, dew still\n"+
     "glistening on their petals",
     "birds", "Here and there, little yellow birds flit through the forest",
});
   
set_listen("You hear the soft sound of birds chirping.");
set_smell("The fragrance of wildflowers is in the air.");
   dest_dir = ({
"/players/laera/cforest/cf19.c","southeast",
"/players/laera/cforest/cf24.c","northwest",
});

}
