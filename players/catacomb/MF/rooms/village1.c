inherit "room/room";

reset(arg){
    if(arg) return;
set_light(1);
set_short(BOLD+GRN+"Shamot village"+NORM);
set_long(
"  The entrance to the elven village, Shamot, is here.  Bright\n"+
"green trees shine in the morning sunshine.  The grass glistens\n"+
"from the morning dew.  The joyful screeches of children can be\n"+
"heard throughout the village.  The elves go about their daily\n"+
"routines in the village.  A large central plaza can be seen to\n"+
"the northwest.  A small creek is to the south.  Small houses can\n"+
"be seen to the west and northeast.\n");

items = ({
	"trees",
	"The sun shines off the leaves of the tall trees",
	"tree",
	"The sun shines off the leaves of the tall trees",
	"leaves",
	"The sun shines off the leaves of the tall trees",
	"leaf",
	"The sun shines off the leaves of the tall trees",
	"sun",
	"Are you trying to blind yourself, don't look into the sun",
	"grass",
	"The grass glistens in the sun",
	"village",
	"The village is in it's normal hustle and bustle mode",
	"plaza",
	"In the center of the town is a large open plaza",
	"creek",
	"The creek babbles past to the south",
	"houses",
	"Small dwellings for the elves",
	"house",
	"Small dwellings for the elves"
	});

dest_dir = ({
	"/players/catacomb/MF/rooms/Creek1.c","creek",
	"/players/catacomb/MF/rooms/village2.c","west",
	"/players/catacomb/MF/rooms/village4.c","northeast",
	"/players/catacomb/MF/rooms/village2.c","west"
	});
}
