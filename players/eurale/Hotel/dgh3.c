#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Drygulch Hotel lobby";
long_desc =
	"  You stand in the rear of the hotel lobby.  There are rooms \n"+
	"to the east and west and the entrance to the hotel lies south.\n"+
	"There is a staircase leading down to the rear of the building.\n";

items = ({
	"staircase","The staircase is dark, narrow and steep.  Is that \n"+
		"breathing you hear nearby?",
});

dest_dir = ({
	"/players/eurale/Hotel/dghb1.c","down",
	"/players/eurale/Hotel/dgh2.c","south",
	"/players/eurale/Hotel/dgh5.c","east",
	"/players/eurale/Hotel/dgh7.c","west",
});

}
