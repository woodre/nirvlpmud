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
   "Three paths emerge from this room.  To the northeast the tunnel\n"+
   "narrows and goes slightly uphill.  The path to the southwest seems\n"+
   "to be well-dug with easy footing.  The walls here are mostly dirt,\n"+
   "except to the south where it is solid rock.  The southern trail is\n"+
   "hardly a path at all, but more of a crevice in the rock.\n"+NORM;

   items=
   ({ 
    "walls",
    "The walls are well-packed tunneled dirt",
    "paths",
    "It's too dark to see where they lead",
   });

   dest_dir=
   ({
        BASE+"h26.c", "northeast",
        BASE+"h28.c", "southwest",
        BASE+"h29.c", "south",
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
