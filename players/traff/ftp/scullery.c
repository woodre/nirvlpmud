/*  SCULLERY.C - Part of Delnoch Keep.
    Changes as of 5-29-96:
    Color added, paths changed to fit new directory structure,
    search(str) changed to match other rooms.
*/
#include "/players/traff/closed/ansi.h"
inherit "room/room";

reset(arg) {

  if(!present("boy"))  {
  move_object(clone_object("/players/traff/delnoch/mon/scullboy.c"),this_object());  }

  if(!arg) {
  set_light(1);
  long_desc=(HIB+
"This is where the dishes are done, as well as some of the\n"+
"preliminary food preperation.  There is a large tub of water\n"+
"here, with a stack of dishes next to it.  In the corner is\n"+
"a large sack of potatos.\n"+NORM);

  items=({
"floor","The floor is rough flagstone from the mountains",
"tub","A large wooden tub filled with soapy water",
"dishes","They look like they have just been washed",
"potatos","They are round and white, as if freshly peeled",
"sack","A burlap bag nearly full of potatos",
 });

  dest_dir=({
    "/players/traff/delnoch/keep/pantry.c","north",
    "/players/traff/delnoch/keep/kitchen.c","south",
      });
    }
  }

init()  {
 ::init();
  add_action("search","search");
}

short() {return HIB+"Scullery"+NORM;}

search(str)  {

  if(!str) {
    write("Search what?\n");
    return 1; }

  write("You search the "+str+" but find nothing of interest.\n");
  return 1; }
