#define ROWS ({"1","2","3","4","5","6","7","8"})
#define COLS ({"a","b","c","d","e","f","g","h"})


#define PATH_NAME "a path through the circus tents"

#define PATH_01 "The path consists of " + hiw("crushed chat") + " and smooth " + gry("river rock") + ". The mixed " + hiw("white") + " and " + gry("gray") + " stones crunch underfoot as you walk."
#define PATH_02 "Large, smoothly polished " + gry("gray stones") + " that resemble misshapen skulls line the path on both sides. They are streaked through with " + hiw("white") + " lines of marble and milky-white crystals."
#define PATH_03 "Crumpled paper wrappers and wax cups litter the path."
#define PATH_04 "Tattered shreds of faded, " + UTIL->alternate("multi-colored canvas", C_NORMAL, 1) + NORM + " flutter across the path."
#define PATH_05 "The prints of the people, animals, and other things who have come before you are pressed into the gravel of the path."
#define PATH_06 "Raccoons or other scavengers have scattered garbage across the path. Tiny " + hiw("bones") + " are mixed in with the trash."
#define PATH_07 "Alongside the path you see a discarded clown's costume crumpled up, the " + UTIL->alternate("faded spots", C_BG, 1) + NORM + " looking like the remnants of some disease."
#define PATH_08 "Tiny circles and curly ribbons of " + UTIL->alternate("colorful paper", CH_GW, 1) + NORM + " are strewn around the path here, the ejected guts of long-dead party poppers."
#define PATH_09 "Knobby tree roots push up through the " + hiw("gravel") + ", threatening to trip you."
#define PATH_10 "Vines of " + grn("poison ivy") + " wend their way across the trail."

#define DESCS_PATH ({PATH_01, PATH_02, PATH_03, PATH_04, PATH_05, PATH_06, PATH_07, PATH_08, PATH_09, PATH_10})

#define TENT_NAME "The interior of a circus tent"

#define TENT_01 "You are surrounded by fluttering shreds of colorful canvas."
#define TENT_02 "Tall " + red("rusty") + " metal poles lean precariously high overhead, threatening to crash to the ground."
#define TENT_03 "Guy wires stretch across the tent, thrumming and moaning when the wind blows through."
#define TENT_04 "Sawdust and wood chips are scattered over the ground to provide a soft surface for the performers."
#define TENT_05 grn("Weeds and scrawny sapling oaks") + " push their way into the tent floor."
#define TENT_06 "Rickety wooden bleachers are pushed up against the shredded remains of the tent walls."
#define TENT_07 "Discarded gum and puddles of what used to be cotton candy make your feet stick to the floor in spots."
#define TENT_08 "Cheap folding metal chairs are decaying into piles of rust in the corner."
#define TENT_09 "Ropes hang from the upper supports, swaying in the breeze."
#define TENT_10 "A couple of the supporting tent poles have fallen across the room."

#define DESCS_TENT ({TENT_01, TENT_02, TENT_03, TENT_04, TENT_05, TENT_06, TENT_07, TENT_08, TENT_09, TENT_10})

#define TENT_LION UTIL->alternate("The Lion Tamer's Tent", CH_RY, 3)
#define TENT_ILLUSIONIST UTIL->alternate("The Illusionist's Tent", CH_WB, 3)
#define TENT_FORTUNE UTIL->alternate("The Fortune Teller's Tent", CH_GW, 3)
#define TENT_ACROBATS UTIL->alternate("The Acrobats' Tent", CH_BG, 2)
#define TENT_CLOWNS UTIL->alternate("The Clowns' Tent", CH_BY, 3)
#define TENT_TRAPEZE UTIL->alternate("The Trapeze Artist's Tent", CH_BR, 2)
#define TENT_UNKNOWN1 UTIL->alternate("A nondescript tent", C_BG, 3)
#define TENT_UNKNOWN2 UTIL->alternate("An nondescript tent", C_CW, 3)
