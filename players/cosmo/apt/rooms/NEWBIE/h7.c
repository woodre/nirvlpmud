#include "/players/cosmo/closed/ansi.h"
#define BASE "/players/cosmo/apt/rooms/NEWBIE/"
#define RATS "/players/cosmo/apt/mon/rats.c"
inherit "players/cosmo/dc/dcroom";

int rat_room_count;  /* Number of created rats in this room */

reset(arg) {
   if(arg) return;
   rat_room_count=0;
   set_light(0);
   set_sound("You hear an occasional squish as the dunghill settles.");
   set_smell("Simply unbearable.  P U!");
   short_desc=BOLD+BLK+"Dunghill"+NORM;
   long_desc=BOLD+BLK+
   "You slide down the tunnel and immediately regret doing so.  You\n"+
   "land at the bottom with a squishy 'plop'.  You sink down a few inches\n"+
   "before the intense smell hits you and you realize what exactly you\n"+
   "are sitting in -- a huge pile of excrement!  That's right, you are\n"+
   "in the middle of a large rat dunghill.  Hopefully, you can climb back\n"+
   "out to the north.\n"+NORM,

   items=
   ({ 
     "excrement",
     "The droppings of rats; rat dung",
     "dunghill",
     "An enormous pile of rat droppings",
     "tunnel",
     "The tunnel leads up to the north and out of this hell-hole",
   });

   dest_dir=
   ({
        BASE+"h6.c", "north",
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
