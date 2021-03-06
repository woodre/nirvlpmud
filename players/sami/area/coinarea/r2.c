inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   set_light(0);
   set_short("Holo Cavern");
long_desc =
  " The cave seems as if it goes on forever. There is a steady echo of\n"+
  " water dripping off of the jagged roof. The floor is an unsafe place to\n"+
  " walk due to its uneven and sharp nature. It is almost as if the cave is \n"+
  " a living entity; breathing and listening.\n",

   items =
    ({
    "roof",
    "A 10' roof, jagged and worn by the constant erosion caused by the water.",
	"rocks",
	"Piles of different shaped rocks lay scattered about.",
	 "water",
	 "A endless supply of water, slowly dripping down the cave walls.",
	 "walls",
	 "An almost metallic substance covers the walls, reflecting what small light there is.",
	 " floor",
	 "The floor dips in many places, jagged rocks protruding from places"+
	 " that would appear impossible.",
});

add_exit("/players/sami/area/coinarea/r1","west");
add_exit("/players/sami/area/coinarea/r3","east");
}
