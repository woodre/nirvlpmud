/*  The Park Valley  */

#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Hidden valley";
long_desc =
	"  The valley is a sweltering area.  The heat is very oppresive \n"+
	"and the trees and ferns do little to protect one from it.  The \n"+
	"large boulders that have to be walked around make traveling slow \n"+
	"and dangerous as one can't see what lies very far ahead. \n";

items = ({
 	"ferns","Shrubby, nonflowering plants with large stems and huge \n"+
		"fronds that reproduce by spores instead of seeds",
	"boulders","Huge stones",
	"trees","Tall, green trees",
});

dest_dir = ({
	"players/eurale/Valley/v25.c","east",
	"players/eurale/Valley/v10.c","northeast",
	"players/eurale/Valley/v9.c","north",
	"players/eurale/Valley/v8.c","northwest",
	"players/eurale/Valley/v23.c","west",
});

}
realm() { return "NT"; }
