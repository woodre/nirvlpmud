#include "/players/cosmo/closed/ansi.h"
#define BASE "/players/cosmo/apt/rooms/NEWBIE/"
#define RATS "/players/cosmo/apt/mon/rats.c"
inherit "players/cosmo/dc/dcroom";

int rat_room_count;  /* Number of created rats in this room */

reset(arg) {
   if(arg) return;
   rat_room_count=0;
   set_light(0);
   set_sound("The water is louder to the south.");
   set_smell("It smells a bit like yesterday's lunch.");
   short_desc=BOLD+BLK+"A pathway in the darkness"+NORM;
   long_desc=BOLD+BLK+
   "The water continues flowing to the south here.  Northern travel is\n"+
   "very strenuous.  It's obvious to you now that you are walking through\n"+
   "a central pipe in the city's sewer system.  The water is quite polluted,\n"+
   "but lucky for you it's only about knee-deep.  You notice some scratch\n"+
   "marks in the metal pipe.\n"+NORM,

  items=
  ({
    "water",
    "Dirty sewer water that flows down from the north",
    "marks",
    "It's hard to distinguish between the human scratches and rat scratches",
    "pipe",
    "A large sewage pipe that's about 8 feet in diameter",
  });

   dest_dir=
   ({
        BASE+"h13.c", "north",
        BASE+"h11.c", "south",
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
