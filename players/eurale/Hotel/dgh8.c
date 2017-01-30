#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Drygulch Hotel";
long_desc =
	"  You climb the wooden staircase and stand in the hallway of \n"+
	"the second floor.  The floor boards creak slightly as you walk \n"+
	"on them giving warning to any guests.  The hallway is dim but \n"+
	"you can make out doors leading to some of the hotel guest rooms \n"+
	"to the north. \n";

items = ({
	"boards","Wooden boards, worn with use",
});

dest_dir = ({
	"/players/eurale/Hotel/dgh2.c","down",
	"/players/eurale/Hotel/dgh9.c","north",
	"/players/eurale/Hotel/dgh13.c","east",
	"/players/eurale/Hotel/dgh12.c","west",
});

}
