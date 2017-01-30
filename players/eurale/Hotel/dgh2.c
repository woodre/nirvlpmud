#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc ="The Drygulch Hotel lobby";
long_desc =
	"  You stand in the front part of the hotel lobby.  There \n"+
	"is a large counter to your east and behind it a door to \n"+
	"what appears to be an office.  You can see another door to \n"+
	"the west and more doors toward the rear of the building.  There \n"+
	"is a stairway leading up to the second floor as well. \n",

items = ({
	"counter","This is the counter where hotel guests sign in.\n"+
		"It is clean and has been used recently",
	"stairway","A wooden stairway with an ornate hand-rail",
});

dest_dir = ({
	"/players/eurale/Hotel/dgh3.c","north",
	"/players/eurale/Hotel/dgh1.c","south",
	"/players/eurale/Hotel/dgh4.c","east",
	"/players/eurale/Hotel/dgh6.c","west",
	"/players/eurale/Hotel/dgh8.c","up",
});

}
