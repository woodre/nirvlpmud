/*  The Park Valley  */

#include "defs.h"
inherit "room/room";

reset(arg) {

if(!present("raptor 1")) {
  move_object(clone_object("players/eurale/Park/NPC/raptor1"),TO); }
if(!present("dimetrodon")) {
  move_object(clone_object("players/eurale/Park/NPC/dime"),TO); }

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
	"players/eurale/Valley/v12.c","east",
	"players/eurale/Valley/v27.c","southeast",
	"players/eurale/Valley/v26.c","south",
	"players/eurale/Valley/v25.c","southwest",
	"players/eurale/Valley/v10.c","west",
});

}
realm() { return "NT"; }