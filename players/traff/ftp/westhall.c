/*  WESTHALL.C - A room in Delnoch Keep. 
    Changes as of 5-29-96:
    Color added, paths changed to fit new directory structure
*/
#include "/players/traff/closed/ansi.h"
inherit "room/room";
reset(arg) {
/*  The 4 monsters below still need to be created.
  if(!present("templar"))  {
    move_object(clone_object("/players/traff/delnoch/mon/templar.c"),this_object());  }
  if(!present("general"))  {
    move_object(clone_object("/players/traff/delnoch/mon/general.c"),this_object());  }
  if(!present("captain"))  {
    move_object(clone_object("/players/traff/delnoch/mon/captain.c"),this_object());  }
  if(!present("aide"))  {
    move_object(clone_object("/players/traff/delnoch/mon/aide.c"),this_object());  }
*/
  if(!arg) {
  set_light(1);
  long_desc=(HIC+
"This is the west hall.  It is smaller than the east hall, and used\n"+
"for smaller gatherings.  There are a number of tables and chairs\n"+
"scattered around the room.  There is the usual fireplace here and\n"+
"of course another painting on the wall.  To the north it looks like\n"+
"there are private rooms, and to the west is the Chapel.\n"+NORM);
  items=({
"floor","Polished marble from the mountains",
"walls","The walls are made from stone also",
"fire","The fire blazes warmly",
"fireplace","A smaller fireplace, it heats the room nicely",
"tables","Suitable for 4 to 6 people the tables have inlaid wood tops",
"chairs","Sturdy but comfortable looking",
 });
  dest_dir=({
/*  Room to be created and added.
"/players/traff/delnoch/keep/library.c","north",
*/
"/players/traff/delnoch/kentry.c","east",
/*  Room to be created and added.
"/players/traff/delnoch/keep/chapel.c","west",
*/
      });
    }
  }
  init()  {
  ::init();
  add_action("search","search");
}
  
  short() {return HIC+"West Hall"+NORM;}

  search(str)  {
  if(!str)  {
    write("Search what?\n");
    return 1;  }
   
    write("You search the "+str+" but find nothing of interest.\n");
    return 1;  }
 
