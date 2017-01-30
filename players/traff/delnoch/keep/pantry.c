/*  PANTRY.c - Part of Delnoch Keep.
    Changes as of 5-29-96:
    Color added, paths changed to fit new directory structure
*/
#include "/players/traff/closed/ansi.h"
inherit "room/room";

reset(arg){

  if(!present("trainer"))  {
  move_object(clone_object("/players/traff/delnoch/mon/trainer.c"),this_object());  }

  if(!arg){
  set_light(0);
  long_desc=(HIR+
"This is a storage area for food brought in from the surrounding\n"+
"farms.  There are a number of sacks piled around and some\n"+
"shelves used for storage.\n"+NORM);

  items=({
"floor","The floor is packed dirt",
"shelves","The shelves are stocked with canned fruits and vegetables",
"sacks","Burlap bags containing various items such as potatos and carrots",
 });

  dest_dir=({
    "/players/traff/delnoch/keep/scullery.c","south",
    "/players/traff/delnoch/keep/courtyd2.c","west",
      });
    }
  }

init()  {
 ::init();
  add_action("search","search");
}

short() {return HIB+"Pantry"+NORM;}

search(str)  {

  if(!str) {
    write("Search what?\n");
    return 1; }

  write("You search the "+str+" but find nothing of interest.\n");
  return 1; }
