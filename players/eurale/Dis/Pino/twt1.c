#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Timberwood Trail";
long_desc =
	"  A well-traveled dirt road that leads through the country.  The\n"+
	"thickets of bushes you pass by as you travel all seem to be loaded\n"+
	"with berries.  The sky is a beautiful color of blue and the clouds\n"+
	"look like giant cotton balls.\n";

items = ({
	"bushes","A raspberry bush",
	"road","A dirt road",
	"clouds","That one looks like a dog",
});

dest_dir = ({
	"players/eurale/Dis/rooms/hub.c","north",
	"players/eurale/Dis/Pino/twt2.c","south",
});

}
