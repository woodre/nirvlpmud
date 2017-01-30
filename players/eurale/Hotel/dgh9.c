#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Drygulch Hotel";
long_desc =
	"  You walk down the hallway to the rear of the hotel.  There \n"+
	"is a little light coming from the rooms you've passed and you \n"+
	"can just make out voices coming from somewhere.  The sound of \n"+
	"your footsteps echoes slightly as you walk. \n";

items = ({
});

dest_dir = ({
	"/players/eurale/Hotel/dgh8.c","south",
	"/players/eurale/Hotel/dgh11.c","east",
	"/players/eurale/Hotel/dgh10.c","west",
});

}
