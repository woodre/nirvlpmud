#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Van Tassel Property";
long_desc =
	"  This is the property of Mynheer Van Tassel.  It is a grand\n"+
	"estate set back in the wooded setting of the twisted forest.\n"+
	"The large, stately homested has seen many parties and enter-\n"+
	"tained most of the folks from Sleepy Hollow.\n";
items = ({
	"homested","A large house with a pillared front and two stories",
});

dest_dir = ({
	"players/eurale/Dis/Slpy/sl19.c","enter",
	"players/eurale/Dis/Slpy/sl7.c","south",
});

}
