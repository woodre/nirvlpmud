#define tpn this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Deep Space";
long_desc =
  "  You wander among the outcroppings of rock and soil.  The colors\n"+
  "of this amazing place make you wonder what kind of chemicals might\n"+
  "reside here.  The craters that dot the entire area add contrast to\n"+
  "the green of the surroundings.\n";

items = ({
	"outcroppings","Stonish-looking hills with a green tinge",
	"craters","Colored holes hammered into the surface",
});

dest_dir = ({
	"players/eurale/Space/ds3.c","south",
	"players/eurale/Space/ds13.c","east",
	"players/eurale/Space/ds1.c","west",
});

}
