#include "/players/cosmo/closed/ansi.h"
#define BASE "/players/cosmo/apt/rooms/NEWBIE/"
#define RATS "/players/cosmo/apt/mon/rats.c"
inherit "players/cosmo/dc/dcroom";

int rat_room_count;  /* Number of created rats in this room */

reset(arg) {
   if(arg) return;
   rat_room_count=0;
   set_light(0);
   set_sound("The water rumbles all around you.");
   set_smell("The odor is simply putrid.");
   short_desc=BOLD+BLK+"A pathway in the darkness"+NORM;
   long_desc=BOLD+BLK+
   "Maybe this pipe continues endlessly.  It must lead somewhere, right?\n"+
   "The water continues flowing to the south; its destination unknown. To\n"+
   "the northeast the pipe goes on, where there must be a source for this\n"+
   "endless stream.\n"+NORM,

  items=
  ({
    "water",
    "Dirty sewer water that flows down from the north",
    "pipe",
    "It's about six feet in diameter at this point",
  });

   dest_dir=
   ({
        BASE+"h21.c", "northeast",
        BASE+"h13.c", "south",
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
