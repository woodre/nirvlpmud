#include <ansi.h>
#include "path.h"
#include "monster.h"
#include "item.h"
#include "color.h"

/* The utility object is... useful. */
#define UTIL "players/darkfire/obj/util"

/*
It's easier to colorize and use the text if it's defined here.
That way if we want to change how it looks, we can do it in one place
and it gets fixed throughout the area. It also keeps descriptions
shorter since they don't have to include these method calls.
*/
#define ABANDONED hiw("(") + gry("abandoned") + hiw(")")
#define AREA_NAME UTIL->alternate("Adventure Land Fun Park!", CH_BRYG, 3) + NORM
#define SHOP_NAME UTIL->alternate("THANKS - FOR - THE - MEMORIES", CH_BRYG, 3) + NORM
#define ASPHALT "cracked and broken asphalt"
/* Commenting out the colorful version to see if it fixes my exits.
#define ASPHALT UTIL->alternate("cracked and broken asphalt", C_WBK, 3) + NORM
*/
#define ASPHALT2 UTIL->alternate("crumbling asphalt", C_WBK, 3) + NORM
#define OREOS UTIL->alternate("Oreos", CH_BW, 2) + NORM
#define MIDWAY UTIL->alternate(UTIL->alternate("MIDWAY", ({"*"}), 1), CH_BRY, 2) + NORM
#define FIRST_AID UTIL->alternate(UTIL->alternate("FIRST AID",({"+"}),1),CH_RW,1) + NORM
#define VIDEO_ARCADE UTIL->alternate(UTIL->alternate("VIDEO ARCADE",({"-"}),1),C_BBG,2) + NORM
#define BROKEN_GLASS UTIL->alternate("colorful shards of glass", CH_RYW, 1) + NORM
#define MYRIAD_COLORS UTIL->alternate("a myriad of colors", CH_RAINBOW, 1) + NORM
#define GALAGA UTIL->alternate("Galaga", C_GALAGA, 1) + NORM
#define SNACK_SHACK UTIL->alternate("Deep ", CH_RY, 1) + UTIL->alternate("Fried ", CH_BG, 1) + UTIL->alternate("Happiness", CH_WB, 1) + NORM
#define MIDWAY_PUB UTIL->alternate("The Third of June Saloon", C_PUB, 3) + NORM
#define HIGH_STRIKER UTIL->alternate(UTIL->alternate("HIGH STRIKER", ({" + "}), 1), CH_WB, 2) + NORM
#define RING_TOSS UTIL->alternate(UTIL->alternate("ring", ({"(",")"}), 2)+" "+UTIL->alternate("toss", ({"(",")"}), 2), CH_GW, 2) + NORM
#define DART_TOSS UTIL->alternate(UTIL->alternate("DART", ({"->"}), 2)+UTIL->alternate("TOSS", ({"<-"}), 2), CH_RW, 2) + NORM
#define BALLOON UTIL->alternate("colorful balloon", CH_RAINBOW, 2) + NORM
#define DUCK_HUNT hiy(UTIL->alternate("duck hunt", ({"*"}), 1))
#define DUNK_TANK UTIL->alternate(UTIL->alternate("DUNK", ({"(~"}), 2)+UTIL->alternate("TANK", ({"~)"}), 2), CH_BG, 2) + NORM
#define CLOWN_HEAD UTIL->alternate("clown's head", CH_BRY, 1) + NORM
#define GRAFFITI UTIL->alternate("graffiti", CH_BRYG, 1) + NORM
#define FLUORESCENT UTIL->alternate("fluorescent paint", CH_RAINBOW, 2) + NORM
#define TIE_DYED UTIL->alternate("tie dyed", CH_BRYG, 1) + NORM
#define POPCORN UTIL->alternate("popcorn", CH_YW, 1) + NORM
#define COTTON_CANDY UTIL->alternate("cotton candy", CH_CWM, 1) + NORM

#define GLITTER "`     .     `   .   ~      . _  '   *   '  .   -   .     ~        \n\n     .  *        *   .       ^ "
#define SPELL_COLD UTIL->alternate(GLITTER, C_COLD, 2) + NORM
#define SPELL_FIRE UTIL->alternate(GLITTER, C_FIRE, 2) + NORM
#define SPELL_DEATH UTIL->alternate(GLITTER, C_DEATH, 2) + NORM
#define SPELL_TOXIC UTIL->alternate(GLITTER, C_TOXIC, 2) + NORM
