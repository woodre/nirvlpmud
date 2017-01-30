#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Cottage";
long_desc =
	"  You have entered a cosy cottage.  The owner, a wicked lady, \n"+
	"her two daughters and Cinderella live here.  The living room \n"+
	"in which you stand has scrubbed hardwood floors, a comfortable \n"+
	"couch and a large chair along with a small table and lamp.  There\n"+
	"are doorways leading off this room to other areas of the cottage.\n"+
	"There is also a narrow staircase leading to someplace upstairs.\n";

items = ({
	"floors","Clean, hand-scrubbed, oak floors",
	"couch","A long stuffed couch for relaxing",
	"chair","A stuffed chair which matches the couch",
	"table","A small end table holding the lamp",
	"lamp","A hurricane style oil lamp",
	"staircase","A wrought iron, spiral staircase",
});

dest_dir = ({
	"players/eurale/Dis/rooms/ml11.c","out",
	"players/eurale/Dis/rooms/ml15.c","south",
	"players/eurale/Dis/rooms/ml13.c","east",
	"players/eurale/Dis/rooms/ml14.c","southeast",
	"players/eurale/Dis/rooms/ml16.c","up",
});

}
