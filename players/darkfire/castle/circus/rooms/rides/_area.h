#define ROWS ({"1","2","3","4","5","6","7","8"})
#define COLS ({"a","b","c","d","e","f","g","h"})

#define RIDES_NAME UTIL->alternate("Amusement Park", CH_BRY, 3) + " " + ABANDONED
#define COASTER_NAME UTIL->alternate(UTIL->alternate("BOLTARS REVENGE",({"->"}),1), CH_GW, 2) + NORM

#define COASTER_01 "You are walking on wobbly, widely-spaced wooden slats. Between them, you can see the ground far below."
#define COASTER_02 "Rickety " + blk("iron") + " rails provide tentative handholds alongside the tracks."
#define COASTER_03 "The coaster rises into a steep arch before dipping again into a stomach-dropping pit."
#define COASTER_04 "The coaster twists and turns in sickeningly tight curves."
#define COASTER_05 "Chunks of dried vomit are still visible between the wooden slats."
#define COASTER_06 "You can see the stains of old " + red("dried blood") + " on the sharply splintered wooden slats."
#define COASTER_07 "Narrow, rickety steps run alongside the tracks here, probably for maintenance workers."
#define COASTER_08 "The entire structure shakes underneath your feet."
#define COASTER_09 "It is extremely difficult to keep your footing on the slick, " + grn("mossy") + " boards."
#define COASTER_10 "The old " + blk("iron track") + " curves smoothly underneath your feet, held by thick bolts."
#define COASTER_11 "The " + blk("iron bolts") + " are working themselves free of the water-damaged boards."

#define DESCS_COASTER ({COASTER_01, COASTER_02, COASTER_03, COASTER_04, COASTER_05, COASTER_06, COASTER_07, COASTER_08, COASTER_09, COASTER_10, COASTER_11})

#define CAROUSEL_NAME UTIL->alternate(UTIL->alternate("THE WHIRLING DERVISH CAROUSEL",({"~"}), 3), CH_BRYG, 2) + NORM

#define CAROUSEL_01 "The carousel shudders underneath you, threatening to begin spinning again."
#define CAROUSEL_02 "Broken glass crunches under your feet, and the bases of broken light bulbs are still in their sockets overhead."
#define CAROUSEL_03 "A pair of huge wooden horses pulls a colorful chariot. One is missing a head, the other its tail. The seat of the chariot looks incredibly uncomfortable."
#define CAROUSEL_04 "A huge " + gry("black") + " and " + hiw("white") + " ostrich looms high overhead, its splintered beak stabbing toward you. One huge eye glares, but the other is missing."
#define CAROUSEL_05 "The ratty and worn leather saddle beckons from the back of a roaring lion with a " + yel("golden mane") + " that is missing most of its hair."
#define CAROUSEL_06 "Gleaming rat's eyes with " + red("red irises") + " rise up from a writhing pair of " + gry("black bodies") + " attached to vertical poles."
#define CAROUSEL_07 "A dismembered opalescent eye skitters out from underfoot."
#define CAROUSEL_08 "Crumpled paper wrappers and wax cups litter the floor."
#define CAROUSEL_09 "You can see the control booth at the center of the carousel, rusty levers looking like the controls of a torture device."
#define CAROUSEL_10 "You see a wooden horse's head, splintered and faded, lying on the ground."

#define DESCS_CAROUSEL ({CAROUSEL_01, CAROUSEL_02, CAROUSEL_03, CAROUSEL_04, CAROUSEL_05, CAROUSEL_06, CAROUSEL_07, CAROUSEL_08, CAROUSEL_09, CAROUSEL_10})

#define MINE_NAME UTIL->alternate(UTIL->alternate("THE DOUBLE JACK MINE",({"."}),1), CH_WB, 2) + NORM

#define MINE_01 "A metal and plastic mine cart car is stuck here, wheels welded to the track by " + red("rusty") + " and frozen brakes."
#define MINE_02 "The ceiling hangs low here, with " + red("rusty") + " rebar spikes hanging down to stab you in the head."
#define MINE_03 "Fake antique lanterns and hard hats hang on the walls. They are splotched with " + hir("blood") + "... some of it is still surprisingly " + hir("bright red") + "."
#define MINE_04 "Wicked-looking animatronic gnomes stick out of dark holes in the walls and floor, swinging tiny pickaxes and hammers."
#define MINE_05 "The " + red("rusty") + " " + blk("iron tracks") + " twist and turn through the darkness."
#define MINE_06 "A rickety wooden bridge spans a depthless chasm here. Crossing it gives you vertigo, and a gust of hot air blows up at you."
#define MINE_07 "You can smell the odor of recently exploded " + blk("black powder") + "."
#define MINE_08 "The tunnel slopes steeply beneath your feet, threatening to throw you off balance."
#define MINE_09 blu("Water") + " flows through the room, only ankle deep but enough to cause quite a splash for the riders in a mine cart."
#define MINE_10 "The honeycomb shape of an old-fashioned " + red("dynamite") + " carrier hangs on the wall."

#define DESCS_MINE ({MINE_01, MINE_02, MINE_03, MINE_04, MINE_05, MINE_06, MINE_07, MINE_08, MINE_09, MINE_10})

#define FUNHOUSE_NAME UTIL->alternate(UTIL->alternate("THE FUN HOUSE",({"~","-"}),1), CH_BRYG, 1) + NORM

#define FUNHOUSE_01 "Boards on the floor move underneath your feet, wobbling to throw you off balance."
#define FUNHOUSE_02 "A crazily bent " + hiw("mirror") + " sends a faint flickering reflection onto the walls and ceiling of the room. Your reflection is strangely distorted. Is your butt really that big?"
#define FUNHOUSE_03 "Big styrofoam tubes hang from the ceiling making it awkward to walk through the room."
#define FUNHOUSE_04 "Dark strings fall across your face like spiderwebs, forcing you to brush at your face instinctively. You hope they are just strings."
#define FUNHOUSE_05 "Walls made of jute netting tangle you up as you try to move from room to move."
#define FUNHOUSE_06 "A strategically-placed " + hiw("mirror") + " makes it look like you're suspended far above a pit, making it difficult to keep your balance."
#define FUNHOUSE_07 "Crumpled paper wrappers and wax cups litter the floor."
#define FUNHOUSE_08 "Stripes of " + FLUORESCENT + " cover the walls in wild, gyrating patterns."
#define FUNHOUSE_09 "A ceiling panel has collapsed here, and lies on the floor covered with chewed-up rats nests."
#define FUNHOUSE_10 "You can hear skittering sounds coming from behind the plywood walls surrounding you."

#define DESCS_FUNHOUSE ({FUNHOUSE_01, FUNHOUSE_02, FUNHOUSE_03, FUNHOUSE_04, FUNHOUSE_05, FUNHOUSE_06, FUNHOUSE_07, FUNHOUSE_08, FUNHOUSE_09, FUNHOUSE_10})

#define PATH_NAME UTIL->alternate("cracked and broken asphalt path", C_WBK, 3) + NORM

#define PATH_01 "The asphalt path is cracked and uneven."
#define PATH_02 grn("Weeds") + " poke up through the cracks in the path, stinging you with nettles and leaving burrs on your clothing."
#define PATH_03 "Somehow a lump of gum decades old still manages to stick to your feet."
#define PATH_04 "Spiderwebs cross the path, and you wonder how the hell a spider spun a web over ten feet wide."
#define PATH_05 "Slatted wooden walls separate you from the surrounding rides."
#define PATH_06 "Crumpled paper wrappers and wax cups litter the ground."
#define PATH_07 "A ghostly hand has left dozens of drawings in " + UTIL->alternate("sidewalk chalk", CH_RAINBOW, 1) + NORM + " here."

#define DESCS_PATH ({PATH_01, PATH_02, PATH_03, PATH_04, PATH_05, PATH_06, PATH_07})
