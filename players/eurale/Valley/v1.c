/*  The Park Valley  */

#define TO this_object()
#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
if(!present("rex")) {
  move_object(clone_object("players/eurale/Park/NPC/rex5"),TO); }
set_light(1);

short_desc = "Hidden valley";
long_desc =
	"  The valley is a sweltering area.  The heat is very oppressive \n"+
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
	"players/eurale/Valley/v2.c","east",
	"players/eurale/Valley/v17.c","southeast",
	"players/eurale/Valley/v16.c","south",
});

}
realm() { return "NT"; }
