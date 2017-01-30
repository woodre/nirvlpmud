#include "/players/cosmo/closed/ansi.h"
#define BASE "/players/cosmo/apt/rooms/NEWBIE/"
#define RATS "/players/cosmo/apt/mon/rats.c"
inherit "players/cosmo/dc/dcroom";

int rat_room_count;  /* Number of created rats in this room */

reset(arg) {
   if(arg) return;
   rat_room_count=0;
   set_light(0);
   set_sound("It is surprisingly quiet in this room.");
   set_smell("A very strong, almost unbearable, smell comes from the south.");
   short_desc=BOLD+BLK+"A pathway in the darkness"+NORM;
   long_desc=BOLD+BLK+
   "You reach a small area between two tunnels that feels almost\n"+
   "as if standing on a shelf.  To the west the tunnel rises up\n"+
   "and becomes drier.  To the south is a steep, muddy decline.\n"+
   "The southern tunnel reminds you of a muddy waterslide, or\n"+
   "perhaps more appropriately, a messy trash shoot.\n"+NORM,

   items=
   ({ 
     "tunnel",
     "It is too dark to see where it leads",
   });

   dest_dir=
   ({
        BASE+"h7.c", "south",
        BASE+"h5.c", "west",
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
