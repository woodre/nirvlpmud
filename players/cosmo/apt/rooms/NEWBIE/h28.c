#include "/players/cosmo/closed/ansi.h"
#define BASE "/players/cosmo/apt/rooms/NEWBIE/"
#define RATS "/players/cosmo/apt/mon/rats.c"
inherit "players/cosmo/dc/dcroom";

int rat_room_count;  /* Number of created rats in this room */

reset(arg) {
   if(arg) return;
   rat_room_count=0;
   set_light(0);
   set_sound("It sounds like someone is scratching in the dirt.");
   set_smell("You smell rare earth elements.");
   short_desc=BOLD+BLK+"A pathway in the darkness"+NORM;
   long_desc=BOLD+BLK+
   "The east-west tunnel comes to an abrupt end here.  A narrow\n"+
   "path is dug into the earth to the northeast, but it certainly\n"+
   "doesn't look like an easy walk.  The thick air makes breathing\n"+
   "difficult this deep under the earth.  The eastern path slopes\n"+
   "upward.\n"+NORM,

   items=
   ({ 
    "tunnel",
    "The tunnel is treacherous with lots of sharp objects jutting out",
    "path",
    "It's too dark to see where it leads",
   });

   dest_dir=
   ({
        BASE+"h27.c", "northeast",
        BASE+"h29.c", "east",
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
