/*  KENTRY.C - Entrance to Delnoch Keep.
    Changes as of 5-28-96:
    Added color, paths changed to fit new directory structure.
*/
#include "/players/traff/closed/ansi.h"
inherit "room/room";

reset(arg) {

  if(!present("butler"))  {
  move_object(clone_object("/players/traff/delnoch/mon/butler.c"),this_object());  }

  while(!present("minion 6"))  {
  move_object(clone_object("/players/traff/delnoch/mon/minion.c"),this_object());  }

  if(!arg) {
  set_light(1);
  long_desc=(
"This is the entrance hall of Delnoch Keep.  There are a few chairs\n"+
"here for the use of waiting guests.  The large windows are covered\n"+
"with thick velvet drapes.  To the east and west are the main wings\n"+
"of the keep.  To the north is an open courtyard.\n");

  items=({
"floor","The floor is polished marble from the nearby mountains",
"chairs","Finely crafted chairs, the wood is polished and the upholstery plush",
"drapes","Golden velvet trimmed in brown.  They look expensive",
"windows","Large windows, you notice heavy wooden shutters that can be barred",
"courtyard","A large open courtyard full of flowers and shrubs",
 });

  dest_dir=({
"/players/traff/delnoch/keep/courtyd.c","north",
"/players/traff/delnoch/town/dmain.c","south",
"/players/traff/delnoch/keep/easthall.c","east",
"/players/traff/delnoch/keep/westhall.c","west",
      });
  }
}

short() { return HIB+"Keep Entry"+NORM;}

init()  {
  ::init();
  add_action("search","search");
  }

search(str)  {

  if(!str) {
    write("Search what?\n");
    return 1; }

  write("You search the "+str+" but find nothing of interest.\n");
  return 1; }
