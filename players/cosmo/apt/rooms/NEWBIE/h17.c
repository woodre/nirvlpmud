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
   "The crusty walls get more and more narrow here.  You have to walk\n"+
   "sideways just to squeeze through.  The rats, however, run rampant\n"+
   "and freely through every little crevice.  The room is very hot and\n"+
   "dry.  Dust swirls into the air from the slightest movement.  There\n"+
   "appears to be enough space to slide north or west from here - maybe.\n"+NORM,

  items=
  ({
    "dust",
    "The dust fills the room, making breathing difficult",
    "walls",
    "The walls appear solid despite the cracks in them",
    "crevice",
    "Little cracks in the walls that you have no chance of fitting through",
  });

   dest_dir=
   ({
        BASE+"h18.c", "north",
        BASE+"h16.c", "west",
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
