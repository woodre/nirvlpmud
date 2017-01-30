#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "/players/laera/cforest/hroom.c";
#include "/players/laera/ansi.h"

reset(arg) {
if(!present("chicobo"))
move_object(clone_object("/players/laera/cforest/NPC/playchic.c"),this_object());
   if(arg) return;
   set_light(1);
   
   short_desc = "Domed Forest";
   long_desc = GRN+
"   In the center of the forest the trees seem to bend inward, providing\n"+
"cover above a large clearing.  Somehow though, ample sunlight shines\n"+
"through the leaves.  Tender grass carpets the clearing, growing in\n"+
"small tufts at the bottoms of the trees.\n"+OFF;
   
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
     "clearing", "The sun shines through the trees, speckling the green grass with soft"+
     "shards of light",
     "sun", "Barely visible between the treetops, the sun is bright and warm",
     "grass","Tender green grass blankets the floor of the forest",
     "tufts","Tufts of tender grass grow at the base of the trees",
     "leaves", "Oak, maple and birch leaves mingle together, almost blocking out the\n"+
     "sunlight",
     "sunlight","Warm, clean sunlight makes its way through the trees",
});
   
set_listen("You hear the soft sound of birds chirping.");
set_smell("The fragrance of wildflowers is in the air.");
   dest_dir = ({
         "/players/laera/cforest/cf17.c","north",
"/players/laera/cforest/cf07.c","south",
"/players/laera/cforest/cf13.c","east",
"/players/laera/cforest/cf11.c","west",
});

}
