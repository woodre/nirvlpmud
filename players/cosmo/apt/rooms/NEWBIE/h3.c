#include "/players/cosmo/closed/ansi.h"
#define BASE "/players/cosmo/apt/rooms/NEWBIE/"
#define RATS "/players/cosmo/apt/mon/rats.c"
inherit "players/cosmo/dc/dcroom";

int rat_room_count;  /* Number of created rats in this room */

reset(arg) {
   if(arg) return;
   rat_room_count=0;
   set_light(0);
   set_sound("It sounds like water dripping to the west.");
   set_smell("It smells like as if someone vomited nearby.");
   short_desc=BOLD+BLK+"A pathway in the darkness"+NORM;
   long_desc=BOLD+BLK+
   "Movement is especially difficult in this area.  The tunnel has\n"+
   "narrowed so much that you have to crawl to travel further west.\n"+
   "To the east the tunnel widens, but you fear that you might actually\n"+
   "get stuck by travelling west.  The ground has become very wet and\n"+
   "sticky, and it's becoming more difficult to breathe.\n"+NORM,

   items=
   ({ 
     "tunnel",
     "It looks like it was made many years ago but it seems to be holding up",
     "ground",
     "The ground is pure mud from the water dripping off the walls",
     "walls",
     "Water creeps through the walls in a few spots",
     "water",
     "The water is proof that the tunnel was dug beneath sea-level",
     "passageway",
     "It is too dark to see where it leads",
   });

   dest_dir=
   ({
        BASE+"h4.c", "west",
        BASE+"h2.c", "east",
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
