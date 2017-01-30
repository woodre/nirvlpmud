inherit "room/room";

reset(arg){
    if(arg) return;
set_light(1);
set_short(BOLD+GRN+"Shamot village"+NORM);
set_long(
"  The trees glisten in the morning light.  The town gives off.\n"+
"an aura of peace.  Elven children run around the town carefree\n"+
"unaware of the dangers that are just across the bridge.  The \n"+
"fountain to the north sends a fine mist through the area.\n");

items = ({
	"trees",
	"Each tree shines with the midday sun",
	"tree",
	"The morning dew on the leaves make it almost blinding to look at the tree.",
	"leaves",
	"The blinding reflection makes it difficult to discern the tree type",
	"leaf",
	"It is impossible to only look at one leaf when you are so far below the tree",
	"sun",
	"Are you trying to blind yourself, don't look into the sun",
	"fountain",
	"The fountain is a beautifully crafted replica of Sylvanus, the Shamot's god",
	"children",
        "The elven children run around playfully",
        "child",
        "One child laughs at a joke",
        "mist",
        "The wind causes a refreshing mist to fall over you"
	});

dest_dir = ({
	"/players/catacomb/MF/rooms/village1.c","east",
	"/players/catacomb/MF/rooms/village3.c","northwest"
	});
}
