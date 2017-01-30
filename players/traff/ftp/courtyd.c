/*  COURTYD.C - Part of Delnoch Keep.
    Changes as of 5-30-96:
    Color added, paths changed to fit new directory structure.
    search(str) added to this room.
*/
#include "/players/traff/closed/ansi.h"
inherit "room/room";

reset(arg){

  if(!present("minion"))  {
  move_object(clone_object("/players/traff/delnoch/mon/minion.c"),this_object());  }

  if(!arg){
  set_light(1);
  long_desc=(GRN+
"A beautiful open courtyard.  In the center is a medium size\n"+
"statue.  To the north is a well trimmed hedge with an open\n"+
"archway cut in it.  On either side are the walls of the Keep.  All\n"+
"around you are beds of flowers, and well trimmed bushes.\n"+NORM);

  items=({
"ground","What is not covered with flowers and bushes is grass",
"statue","A statue of a dragon.  On the base someone has written"+
"in a crude hand, THE DRAGON LIVES",
"flowers","Many varities and all colors, their fragrance fills the air",
"hedge","About 6 feet tall, you can see a path through the opening",
"bushes","They appear to be evergreens of some sort",
"walls","The walls of the keep are grey stone, from the mountains",
 });

  dest_dir=({
"/players/traff/delnoch/forest/forest1.c","north",
"/players/traff/delnoch/keep/kentry.c","south",
      });
  }   }

short() { return BLU+"Courtyard"+NORM;}

init()  {
 ::init();
  add_action("search","search");
}

  search(str)  {

  if(!str)  {
    write("Search what?\n");
    return 1;  }
   
    write("You search the "+str+" but find nothing of interest.\n");
    return 1;  }
