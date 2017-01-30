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
   "The narrow passageway continues both east and west from here.  There\n"+
   "is also a small hole leading south.  The walls are damp and musty, as\n"+
   "there is no sunlight in this room at all.  You think you catch a glimpse\n"+
   "of light to the east.  Walking is slightly difficult due to the low\n"+
   "ceilings and muddy ground.\n"+NORM,

   items=
   ({ 
     "ceilings",
     "The ceiling, about 5 feet above you, is impacted dirt",
     "walls",
     "The walls are wet and muddy",
     "light",
     "It looks like sunlight",
     "hole",
     "It looks like you could squeeze through it",
     "ground",
     "Your feet seem to stick in it as you walk",
     "passageway",
     "It is too dark to see where it leads",
   });

   dest_dir=
   ({
        BASE+"h1.c", "east",
        BASE+"h3.c", "west",
        BASE+"h8.c", "south",
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
   n = random(10);  /* 0-5 = small rat; 6-8 = normal rat; 9 = large rat */
   rat = RATS->make_rat(n);
   move_object(rat, this_object());
   msg = RATS->random_room_msg();
   tell_room(this_object(), msg);
   rat_room_count++;
   return 1;
}
