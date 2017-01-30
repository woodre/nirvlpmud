#include "/players/cosmo/closed/ansi.h"
#define BASE "/players/cosmo/apt/rooms/NEWBIE/"
#define RATS "/players/cosmo/apt/mon/rats.c"
inherit "players/cosmo/dc/dcroom";

int rat_room_count;  /* Number of created rats in this room */

reset(arg) {
   if(arg) return;
   rat_room_count=0;
   set_light(0);
   set_sound("A mechanical sound comes from the east.");
   set_smell("There is a strange burning smell in the air.");
   short_desc=BOLD+BLK+"A pathway in the darkness"+NORM;
   long_desc=BOLD+BLK+
   "This underground world of rats seems to expand through a\n"+
   "series of tunnels and caves.  From this room, a path\n"+
   "branches out to the north and another appears to go both\n"+
   "east and west.  Some of the tunnels are well carved, as if\n"+
   "done by machines; others are less finished and look like they\n"+
   "were done by hand, or perhaps by claws.\n"+NORM,

   items=
   ({ 
    "path",
    "It's too dark to see where the paths lead",
    "tunnels",
    "The tunnels area treacherous for all travelers",
   });

   dest_dir=
   ({
        BASE+"h27.c", "north",
        BASE+"h30.c", "east",
        BASE+"h28.c", "west",
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
