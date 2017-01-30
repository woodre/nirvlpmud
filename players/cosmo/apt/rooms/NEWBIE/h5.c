#include "/players/cosmo/closed/ansi.h"
#define BASE "/players/cosmo/apt/rooms/NEWBIE/"
#define RATS "/players/cosmo/apt/mon/rats.c"
inherit "players/cosmo/dc/dcroom";

int rat_room_count;  /* Number of created rats in this room */

reset(arg) {
   if(arg) return;
   rat_room_count=0;
   set_light(0);
   set_sound("The incessant scratching and squeaking bores into your brain.");
   set_smell("Hot, stale air fills your nostrils.");
   short_desc=BOLD+BLK+"A pathway in the darkness"+NORM;
   long_desc=BOLD+BLK+
   "The sounds of the rats seem especially loud in this room, as\n"+
   "the sqeaking seems to echo off the walls.  This room is not\n"+
   "quite as wet as some of the others, since it is on a bit of a\n"+
   "plateau.  The tunnel continues downhill to both the east and\n"+
   "north.  It looks very slippery in both directions.\n"+NORM,

   items=
   ({ 
     "plateau",
     "A level area slightly higher in elevation",
     "walls",
     "The damp walls seem to echo every movement in this open area",
     "tunnel",
     "It is too dark to see where it leads",
   });

   dest_dir=
   ({
        BASE+"h4.c", "north",
        BASE+"h6.c", "east",
    });
}

init() {
  ::init();
  /* Make sure there are not already 3 rats in this room  */
  /* or 30 rats in the whole area.  If not, 50% chance of */
  /* making a new one.                                    */
  if(rat_room_count < 2 && RATS->query_rats()) 
     if(random(2))  call_out("get_rat",5);
}

get_rat() {
int n;
object rat;
string msg;
   n = random(10);
   rat = RATS->make_rat(n);
   move_object(rat, this_object());
   msg = RATS->random_room_msg();
   tell_room(this_object(), msg);
   rat_room_count++;
   return 1;
}
