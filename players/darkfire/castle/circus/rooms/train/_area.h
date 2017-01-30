#define ROWS ({"1","2","3","4","5","6","7","8","9","10","11"})
#define COLS ({"a","b","c","d","e","f","g","h","i","j"})

#define LIQUID UTIL->alternate("liquid", CH_RY, 1) + NORM

#define NAME_TRAIN UTIL->alternate("Circus Train", CH_BRY, 1) + " " + ABANDONED

#define TRAIN_01 "The box car is made of heavy steel, but something has made it rust badly, almost all the way through in spots."
#define TRAIN_02 "Strangely colored " + LIQUID + " pools in the corners."
#define TRAIN_03 "There are deep scratches in the thick metal flooring as if heavy items were dragged around the train car."
#define TRAIN_04 "There are a few tattered pieces of " + hiw("cloth") + " here. The material is thick, like a hazmat suit."
#define TRAIN_05 "Pieces of broken " + hiw("glass") + " cover the floor of the train. What kind of circus train was this?"
#define TRAIN_06 "You spot some old " + red("dried blood") + " staining the rusty metal even darker."
#define TRAIN_07 "Some crates, now crushed, bear the markings of the fun park, but you suspect this was not really a circus train."
#define TRAIN_08 "You spot a pile of " + hiw("bones") + " in a deeply shadowed corner of the train car. They don't look human, though they're big enough."
#define TRAIN_09 "Someone has tagged the car with " + GRAFFITI + "."
#define TRAIN_10 "Some cages are piled in the corner of the train car, probably for circus animals. The steel bars are badly bent."
#define TRAIN_11 "Rusty " + gry("50 gallon drums") + " are stacked here, leaking nasty-looking " + LIQUID + "."

#define DESCS_TRAIN ({TRAIN_01, TRAIN_02, TRAIN_03, TRAIN_04, TRAIN_05, TRAIN_06, TRAIN_07, TRAIN_08, TRAIN_09, TRAIN_10, TRAIN_11})

#define PATH1_01 "The path is bordered on both sides by dense undergrowth."
#define PATH1_02 "Strangely colored " + UTIL->alternate("liquid", CH_RY, 1) + NORM + " seeps from the ground."
#define PATH1_03 "Huge oak, elm, and birch trees along with a few lodgepole pines loom over you, blocking most of the sunlight."
#define PATH1_04 "Blackberry bushes grow alongside the path, their sharp thorns clutching at your clothes. Perhaps you could pick some."
#define PATH1_05 "Fallen leaves, wet from condensation, cover the trail making your footing slick."
#define PATH1_06 "You spot some old " + red("dried blood") + " staining the ground. It ruins the peaceful atmosphere somewhat."
#define PATH1_07 "There's a rustling in the underbrush as some small animal scurries away into the woods."

#define DESCS_PATH1 ({PATH1_01, PATH1_02, PATH1_03, PATH1_04, PATH1_05, PATH1_06, PATH1_07})


#define PATH2_01 "The path consists of " + hiw("crushed chat") + " and smooth " + gry("river rock") + "."
#define PATH2_02 "Strangely colored " + UTIL->alternate("liquid", CH_RY, 1) + NORM + " seeps from the ground."
#define PATH2_03 "The mixed " + hiw("white") + " and " + gry("gray") + " gravel crunches underfoot as you walk."
#define PATH2_04 "The bedding of the train tracks rises up to the east, making it a scramble to get into the boxcars."
#define PATH2_05 "One small " + hiw("white stone") + " catches your eye. What the hell, it's a " + hiw("tooth") + "!"
#define PATH2_06 "You spot some " + gry("dark liquid") + " staining the gravel. Oil? Blood? Something unidentifiable."
#define PATH2_07 "Thick, thorny underbrush makes it impossible to squeeze under or around the boxcars."

#define DESCS_PATH2 ({PATH2_01, PATH2_02, PATH2_03, PATH2_04, PATH2_05, PATH2_06, PATH2_07})

#define DESC_STICKERS "Although they're mostly peeled off, what remains of the stickers is a bright orange color with black lettering. Perhaps they were biohazard stickers?"
#define DESC_LIQUID "This small puddle of gooey liquid is an unnatural bright orange color with streaks of " + hig("green") + "."

#define ITEMS (["stickers":DESC_STICKERS, "liquid":DESC_LIQUID])