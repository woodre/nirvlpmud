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
   "A large elevator comes to rest high above your head. The walls are\n"+
   "cut smooth into the rock, making it impossible for you to reach the\n"+
   "elevator or climb up to it.  A tunnel is cut into the western wall\n"+
   "but there is only darkness beyond its entrance.  This room appears\n"+
   "to be a renmant from the original construction of the apartment\n"+
   "building elevator, but it's obviously long since used.\n"+NORM,

   items=
   ({ 
    "elevator",
    "It would be impossible for the elevator to come down any lower, and\n"+
     "you have no chance of climbing up to reach it",
    "walls",
    "The walls are well-packed tunneled dirt",
    "room",
    "It's dark and dry, and you see no way out except to the west",
    "tunnel",
    "It's too dark to see where it leads",
   });

   dest_dir=
   ({
        BASE+"h29.c", "west",
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
