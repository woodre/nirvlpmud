#include "/players/cosmo/closed/ansi.h"
#define BASE "/players/cosmo/apt/rooms/NEWBIE/"
#define RATS "/players/cosmo/apt/mon/rats.c"
inherit "players/cosmo/dc/dcroom";

int rat_room_count;  /* Number of created rats in this room */

reset(arg) {
   if(arg) return;
   rat_room_count=0;
   set_light(0);
   set_sound("You hear the distant squeaking of small rodents.");
   set_smell("It smells like a blend of moldy cheese and rotting flesh.");
   short_desc=BOLD+BLK+"A pathway in the darkness"+NORM;
   long_desc=BOLD+BLK+
   "There is a bend in the passageway here, creating an elbow that\n"+
   "travels east and south.  To the south the passageway appears to\n"+
   "open up to a large room.  To the east the air seems warmer and the\n"+
   "walls appear more narrow.  A slight breeze seems to be flowing from\n"+
   "the south through this passage.\n"+NORM,

  items=
  ({
    "breeze",
    "How can you look at the wind?",
    "passageway",
    "It's too dark to see where either one leads",
  });

   dest_dir=
   ({
        BASE+"h14.c", "south",
        BASE+"h17.c", "east",
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
