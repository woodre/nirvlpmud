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
"   This odd forest is home to the chocobo.  Its dome shape offers \n"+
"protection from the elements as well as a comfortable environment to \n"+
"raise those cute little chicks, chicobos.  Green grass grows underfoot\n"+
"and wildflowers dot the area.  A sign has been carefully posted on \n"+
"a nearby tree.\n"+OFF;
   
   items = ({
     "up", "The sky can be glimpsed through the tops of the trees",
     "sky", "A clear blue sky is glimpsed through the tops of the trees",
     "down", "Thick grass grows on the forest floor",
     "ground", "Thick grass grows on the forest floor",
     "tree", "A young healthy maple tree, its top stretching to the center of the\n"+
     "forest.  A sign is nailed to its trunk",
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
     "grass", "Tender green grass blankets the floor of the forest",
     "wildflowers", "Purple violets, fresh crocuses and bright daisies grow between the\n"+
     "trees",
     "flowers", "Purple violets, fresh crocuses and bright daisies grow between the\n"+
     "trees",
     "violets", "Small and delicate, these little flowers seem content in this forest",
     "daisies", "Bright white with yellow centers, these flowers invite you to explore\n"+
     "the forest",
     "crocuses", "Red, blue and pink crocuses peek through the grass, dew still\n"+
     "glistening on their petals",
      "sign", "An old wooden sign with lettering on it that can be 'read'",
});
   
set_listen("You hear the soft sound of birds chirping");
set_smell("The fragrance of wildflowers is in the air");
   dest_dir = ({
         "/players/laera/cforest/cf02.c","northwest",
         "/players/laera/cforest/cf04.c","northeast",
         "/players/laera/cforest/cf03.c","north",
         "/players/laera/jump.c","out",
});

}

init()
{
     ::init();
     add_action("read_sign","read");
}

read_sign(str)
{
     if(str=="sign")
     {
     write("Please do not feed the chicobos.\n");
     return 1;
     }
notify_fail("Read what?\n");
}
