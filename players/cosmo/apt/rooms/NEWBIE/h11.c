#include "/players/cosmo/closed/ansi.h"
#define BASE "/players/cosmo/apt/rooms/NEWBIE/"
#define RATS "/players/cosmo/apt/mon/rats.c"
inherit "players/cosmo/dc/dcroom";

int rat_room_count;  /* Number of created rats in this room */

reset(arg) {
   if(arg) return;
   rat_room_count=0;
   set_light(0);
   set_sound("You hear water rushing with great force to the south.");
   set_smell("The water smells surprisingly fresh.");
   short_desc=BOLD+BLK+"A pathway in the darkness"+NORM;
   long_desc=BOLD+BLK+
   "Water flows with great force through this room.  Footing is difficult\n"+
   "to maintain in the metal tube in which you stand.  To the south, the\n"+
   "water pours through a large iron grate.  Travel upstream to the north\n"+
   "appears quite treacherous.  A small hole in the upper west wall appears\n"+
   "large enough to crawl through.  It looks like a great place for rats to\n"+
   "hide.\n"+NORM,

  items=
  ({
    "grate",
    "The bars are welded in place and it's apparent that they won't budge",
    "bars",
    "Solid cast iron.  No chance whatsoever",
    "water",
    "Dirty sewer water that flows down from the north",
    "tube",
    "It's a large sewer pipe about 8 feet in diameter at this point",
    "hole",
    "The hole is small, but you can probably squeeze through it",
  });

   dest_dir=
   ({
        BASE+"h10.c", "west",
        BASE+"h12.c", "north",
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
