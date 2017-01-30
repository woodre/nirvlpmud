/*  The Park Valley  */

#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Hidden valley";
long_desc =
	"  The vegetation is getting much denser here.  There are lots \n"+
	"of ferns and tall trees covering the floor again.  The moss \n"+
	"that grows in abundance here provides a cushion for the valley \n"+
	"floor.  There is a huge boulder to the north that you might be \n"+
	"be able to climb.\n";

items = ({
	"ferns","Large, leafy plants",
	"trees","Tall, green trees with thich foliage",
	"moss","Dark green and velvety looking",
});

dest_dir = ({
	"players/eurale/Valley/v20.c","east",
	"players/eurale/Valley/v5.c","northeast",
	"players/eurale/Valley/v3.c","northwest",
	"players/eurale/Valley/v18.c","west",
});

}
realm() { return "NT"; }
