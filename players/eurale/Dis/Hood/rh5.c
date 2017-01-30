#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "King's Way";
long_desc =
	"  This beautiful clay highway has been packed smooth and flat\n"+
	"by the many travelers who have come this way.  The open \n"+
	"countryside that it passes through is beautiful and peaceful\n"+
	"and a joy to experience.  The rolling hills, wild flowers and\n"+
	"young fruit trees make the journey enjoyable.\n";

items = ({
	"highway","Hard-packed reddish clay",
	"countryside","Never-ending rolling hills with trees",
	"hills","Gently rolling",
	"flowers","Many varieties with differing colors and aromas",
	"trees","Apple, peach and pear trees with budding flowers",
});

dest_dir = ({
	"players/eurale/Dis/Hood/rh6.c","east",
	"players/eurale/Dis/Hood/rh4.c","south",
});

}
