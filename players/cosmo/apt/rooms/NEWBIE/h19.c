#include "/players/cosmo/closed/ansi.h"
#define BASE "/players/cosmo/apt/rooms/NEWBIE/"
#define RATS "/players/cosmo/apt/mon/rats.c"
inherit "players/cosmo/dc/dcroom";

int rat_room_count;  /* Number of created rats in this room */

reset(arg) {
   if(arg) return;
   rat_room_count=0;
   set_light(0);
   set_sound("You hear running water to the west.");
   set_smell("It smells a bit like ammonia in here.");
   short_desc=BOLD+BLK+"A pathway in the darkness"+NORM;
   long_desc=BOLD+BLK+
   "This small room seems to be the northern end point of a north-\n"+
   "south tunnel. The tunnel appears to become very narrow to the\n"+
   "south.  To the west, a small hole high up in the wall leads out\n"+
   "to who knows where.  You might be able to lift yourself up and\n"+
   "squeeze out through the hole.\n"+NORM,

  items=
  ({
    "wall",
    "Under the dirt of the western wall appears to be metal",
    "hole",
    "The hole is small, but you can probably squeeze through it",
    "tunnel",
    "It's too dark to see where it leads",
    "metal",
    "It looks like the outside of a sewer pipe",
  });

   dest_dir=
   ({
        BASE+"h20.c", "west",
        BASE+"h18.c", "south",
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
