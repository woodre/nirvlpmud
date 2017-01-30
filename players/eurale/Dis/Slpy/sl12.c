#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Shade Lane";
long_desc =
	"  This is the quaint old town of Sleepy Hollow.  A quiet,\n"+
	"drowsy, even dreamy influence seems to hang over the land.\n"+
	"Some say the place was bewitched in the early days.  The whole\n"+
	"neighborhood abounds with haunted spots, strange sights and \n"+
	"twilight superstitions.  Off to the north is the school and to\n"+
	"the northeast is 'Ye Olde Schnapps Shoppe' where the Sleepy\n"+
	"Hollow Boys and their leader are known to hang out.\n";
items = ({
	"shoppe","The local tavern",
	"school","A small, one room building",
});

dest_dir = ({
	"players/eurale/Dis/Slpy/sl10.c","north",
	"players/eurale/Dis/Slpy/sl13.c","south",
});

}
