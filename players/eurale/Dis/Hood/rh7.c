#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "King's Way";
long_desc =
	"  The hills to the north are beginning to flatten out and off\n"+
	"to the east you can just see the beginning of a tree line.\n"+
	"The flowers and shrubbery lining the road are starting to \n"+
	"thicken and there are small stands of beautiful pine trees\n"+
	"dotting the countryside.\n";

items = ({
	"flowers","Tall, multi-colored asters and cone flowers",
	"shrubbery","Thick, green bushes... suitable for hiding in",
	"trees","Spruce and Fir",
});

dest_dir = ({
	"players/eurale/Dis/Hood/rh6.c","north",
	"players/eurale/Dis/Hood/rh8.c","east",
});

}
