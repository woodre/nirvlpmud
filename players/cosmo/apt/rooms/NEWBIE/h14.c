#include "/players/cosmo/closed/ansi.h"
#define BASE "/players/cosmo/apt/rooms/NEWBIE/"
#define RATS "/players/cosmo/apt/mon/rats.c"
inherit "players/cosmo/dc/dcroom";

int rat_room_count;  /* Number of created rats in this room */

reset(arg) {
   if(arg) return;
   rat_room_count=0;
   set_light(0);
   set_sound("Through the hole, you faintly make out the sound of running water.");
   set_smell("The air is surprisingly fresh here.");
   short_desc=BOLD+BLK+"A pathway in the darkness"+NORM;
   long_desc=BOLD+BLK+
   "The ground is warm and damp in this room.  There is a hole high up\n"+
   "on the western wall.  Passages also lead out of this room to the\n"+
   "north and east.  The room itself is surprisingly cavernous; you\n"+
   "can actually stand upright here and stretch a little bit.  You hear\n"+
   "something to the west, but can't quite make out the sound.\n"+NORM,

  items=
  ({
    "ground",
    "The ground is damp from an occasional splash of water coming through the hole",
    "wall",
    "The walls are well-packed tunneled dirt",
    "hole",
    "The hole is small, but you can probably squeeze through it",
    "passages",
    "It's too dark to see where either one leads",
  });

   dest_dir=
   ({
        BASE+"h16.c", "north",
        BASE+"h15.c", "east",
        BASE+"h13.c", "west",
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
