#include "/players/cosmo/closed/ansi.h"
#define BASE "/players/cosmo/apt/rooms/NEWBIE/"
#define RATS "/players/cosmo/apt/mon/rats.c"
inherit "players/cosmo/dc/dcroom";

int rat_room_count;  /* Number of created rats in this room */

reset(arg) {
   if(arg) return;
   rat_room_count=0;
   set_light(0);
   set_sound("It sounds like running water to the east.");
   set_smell("It smells like a blend of moldy cheese and rotting flesh.");
   short_desc=BOLD+BLK+"A pathway in the darkness"+NORM;
   long_desc=BOLD+BLK+
   "It's a very tight squeeze in this room, if it can even be called a\n"+
   "room.  It's more like a branch betweeen tunnels, as paths lead north\n"+
   "east, and southeast.  There are scratch marks in the walls that seem\n"+
   "to indicate that these tunnels were man-made by hand, or perhaps\n"+
   "creature-made by claws.\n"+NORM,

   items=
   ({ 
     "marks",
     "It's hard to tell if they were made by rats or people, or both",
     "paths",
     "It is too dark to see where they leads",
     "tunnels",
     "It is too dark to see where they leads",
   });

   dest_dir=
   ({
        BASE+"h2.c", "north",
        BASE+"h10.c", "southeast",
        BASE+"h9.c", "east",
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
