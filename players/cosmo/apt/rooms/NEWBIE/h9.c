#include "/players/cosmo/closed/ansi.h"
#define BASE "/players/cosmo/apt/rooms/NEWBIE/"
#define RATS "/players/cosmo/apt/mon/rats.c"
inherit "players/cosmo/dc/dcroom";

int rat_room_count;  /* Number of created rats in this room */

reset(arg) {
   if(arg) return;
   rat_room_count=0;
   set_light(0);
   set_sound("The sound of running water is quite distinct to the east.");
   set_smell("The scent reminds you of being outside after a hard rain.");
   short_desc=BOLD+BLK+"A pathway in the darkness"+NORM;
   long_desc=BOLD+BLK+
   "What first appeared to be a long tunnel abruptly stops here and\n"+
   "turns the corner.  You notice for the first time the stark difference\n"+
   "between the warm and wet east walls, compared to the dry and crusty\n"+
   "west walls.  The dirt crumbles off the west walls, while forming muddy\n"+
   "clumps on the east walls.  Why didn't you notice that earlier?\n"+NORM,

   items=
   ({ 
     "tunnel",
     "It looks like it was made many years ago but it seems to be holding up",
     "walls",
     "Look at <west walls> or <east walls>",
     "west walls",
     "The dirt to the west is dry and flaky",
     "east walls",
     "There must be some sort of water source on the other side of the wall",
     "clumps",
     "The mud drips halfway down the wall until it coagulates into clumpy\n"+
     "mounds, which are surprisingly pleasing to look at",
   });

   dest_dir=
   ({
        BASE+"h8.c", "west",
        BASE+"h10.c", "south",
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
