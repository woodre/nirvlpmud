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
   "Several passages intersect at this point and it's becoming difficult\n"+
   "to maintain your sense of direction in these caves.  You begin to\n"+
   "wonder just how far underground you are now, and how difficult it\n"+
   "would be to get back out.  You are standing in mud but notice a metal\n"+
   "floor through a hole to the east.\n"+NORM,

   items=
   ({ 
     "mud",
     "The mud is very thick, almost clay-like",
     "floor",
     "It's hard to make out the eastern floor from this far away",
     "hole",
     "It's a tight squeeze, but you can probably make it",
     "passages",
     "The passages lead east, north, and northwest",
   });

   dest_dir=
   ({
        BASE+"h11.c", "east",
        BASE+"h8.c", "northwest",
        BASE+"h9.c", "north",
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
