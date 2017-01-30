#include "ansi.h"

inherit "room/room";

string *exits;
      
reset(arg) {

if(!present("dan")) {
move_object(clone_object("/players/katya/area/bolivar/town/m/dan.c"),this_object());
}

  if(arg) return;

  set_light(1);

  long_desc=
"   Western Auto is an old time hardware store.  All around the store\n"+
"they have completely different types of items.  To the west of the \n"+
"store are large appliances, from refrigerators to washer and dryers.\n"+
"Toward the east of the store are tools of all types.  In the middle\n"+
"of everything they have placed small white shelves filled with toys\n"+
"on one side and office supplies on the other.  The register is located\n"+
"to the north by the door that leads into the stock room.\n";


   items=({
	"items",
	   "Different items are scattered across the store",
	"appliances",
           "Large appliances sit by the window, mostly gathering dust",
	"window",
	   "A large window that covers the whole front wall of the store",
	"refrigerators",
	   "It seems they only sell large stacked refrigerators",
	"frig",
	   "It seems they only sell large stacked refrigerators",
	"register",
	   "The register is an old fashion machine, almost as if they were stuck in the 50's",
	"shelves",
	   "White shelves sit in the middle of the room, holding toys and other items",
	"washer",
	   "The washer seems to be a very nice make",
	"dryer",
	   "The dryer seems to be in very good condition",
	"tools",
	   "The tools have been hung on peg board, so they will stay neatly in place",
	"toys",
	   "The toys vary on the shelves between cheap Barbie dolls to little yo-yos",
	"supplies",
	   "The office supplies seem to be gathering dust",
	"door",
	   "The door leading to the stock room seems to be locked tight",

   });

   dest_dir=({
	"/players/katya/area/bolivar/town/r/road12","out",

   });
}

   short() {

      return "Western Auto";

 }