#include "ansi.h"

inherit "room/room";

string *exits;
      
reset(arg) {

if(!present("cynthia")) {
move_object(clone_object("/players/katya/area/bolivar/town/m/cynthia.c"),this_object());
}

  if(arg) return;

  set_light(1);

  long_desc=
"   The store has a lot of clothing racks scatter around.  Along\n"+
"the west and east walls are racks of clothing, as well as a few\n"+
"racks in the middle of the store.  The register is located on the\n"+
"south wall.  On the north wall is filled with windows.  A large\n"+
"green frog has been painted upon it.  About a foot from the windows\n"+
"is a smaller shelf th at has a few miscellaneous accessories on it.\n";

   items=({
	"racks",
	   "Large black racks with clothing hanging on them",
	"windows",
           "Large tinted windows that take up all the north wall",
	"frog",
	   "A large green frog that has been painted upon the window",
	"walls",
	   "The walls are painted white with pictures of frogs and other small animals on it",
	"accessories",
	   "Some small accessories lay upon the shelf",
	"register",
	   "The register is an old fashion machine that is almost always broken",
	"shelf",
	   "The small shelf is black with a small picture of a frog on it",
	"clothing",
	   "The clothing is hang neatly upon the racks",

   });

   dest_dir=({
	"/players/katya/area/bolivar/town/r/road16","out",

   });
}

   short() {

      return "Frogs & Friends";

 }