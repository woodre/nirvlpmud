inherit "room/room";       /* ec13 */

reset(arg){
 if(!arg){

  set_light(0);
  short_desc = "inculta creperum";  /* waste / desert darkness */
  long_desc=
"  You are in a very dark place.  The sky is thick and fluid, swirls\n"+
"of dark colors blending within themselves.  The ground is very dry\n"+
"and cracked, divided up into what look like large squares of brown\n"+
"rock.  Strong winds are whipping across the plane, flecks of sand\n"+
"blowing through the darkness skewing your vision.\n";
  items=({
  "sky",
"The sky seems to be made of many layers of dark gases which flow\n"+
"together as one.  The winds are blowing constantly, making the sky\n"+
"bend and twist.  There is no light coming from anywhere in the sky",
  "ground",
"The ground is hard, flat brown rock.  It is all very dry and scattered\n"+
"with sand that is constantly moving about.  Cracks decorate the ground\n"+
"in many places because of how dry it is",
  "squares",
"The ground almost appears to be divided up by the cracks into square\n"+
"shapes.  The sand makes it hard to descern them a moment later however",
  "cracks",
"Thin cracks run all throughout the ground, diving up the dry ground.\n"+
"They seem to be begging for any kind of moisture, but receive nothing",
  "sand",
"Sand is moving fluidly over the flat rocky surface of this place.  The\n"+
"winds whip the sand up through the air, mixing with the darkness",
  });
  dest_dir=({  "/players/zeus/desert/r/ec8.c", "north",
               "/players/zeus/desert/r/ec14.c", "east",
               "/players/zeus/desert/r/ec18.c", "south",
               "/players/zeus/desert/r/ec12.c", "west",  });
  }
 }

void init(){
  ::init();
  add_action("search_cmd", "search");
}

/* For the Inculta Creperum quest */
#include "/players/zeus/desert/r/search.h"

