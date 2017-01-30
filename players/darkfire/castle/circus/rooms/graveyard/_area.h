#define ROWS ({"1","2","3"})
#define COLS ({"a","b","c"})

#define NAME_GRAVEYARD UTIL->alternate("Clown", CH_BRY, 1) + gry(" Graveyard")

#define FLUID UTIL->alternate("fluid", CH_RY, 1) + NORM

#define GRAVEYARD_01 "A rickety " + hiw("white picket fence") + " barely holds back the wildly overgrown bushes outside the graveyard."
#define GRAVEYARD_02 "Strangely colored " + FLUID + " seeps from the ground."
#define GRAVEYARD_03 "The grass under your feet is thick and tall. It seems to clutch at your ankles as you stand here."
#define GRAVEYARD_04 "Recently-turned earth forms a low mound here. The normally pungent, earthy smell is strangely acidic."
#define GRAVEYARD_05 "Long furrows are gouged in the earth here, cutting through the loam and into the dirt."
#define GRAVEYARD_06 "You spot some old " + red("dried blood") + " staining the ground."
#define GRAVEYARD_07 "In the center of the graveyard you can see a huge magnolia tree with strangely shaped flowers."
#define GRAVEYARD_08 "The ground seems unstable here, the earth moves slightly under your footsteps."

#define DESCS_GRAVEYARD ({GRAVEYARD_01, GRAVEYARD_02, GRAVEYARD_03, GRAVEYARD_04, GRAVEYARD_05, GRAVEYARD_06, GRAVEYARD_07, GRAVEYARD_08})
