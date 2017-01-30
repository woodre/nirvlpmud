#include "/players/cosmo/closed/ansi.h"
#define BASE "/players/cosmo/apt/rooms/NEWBIE/"
#define RATS "/players/cosmo/apt/mon/rats.c"
inherit "players/cosmo/dc/dcroom";

int rat_room_count;  /* Number of created rats in this room */

reset(arg) {
   if(arg) return;
   rat_room_count=0;
   set_light(0);
   set_sound("You can't hear a thing in this pit.");
   set_smell("You inhale the smell of decaying flesh and feel nauseated.");
   short_desc=BOLD+BLK+"A pit in the darkness"+NORM;
   long_desc=BOLD+BLK+
   "You fall down through the tunnel and land in a pit!  Looking up,\n"+
   "it appears that you fell about 20 feet.  There's no way you'll be\n"+
   "able to climb back up.  Lucky for you, it looks like you're not the\n"+
   "first one to land in here.  As evidenced by the two paths that\n"+
   "incline up to the west and northwest, it seems that some other\n"+
   "unlucky saps were able to dig their way out of this pit.\n"+NORM,

   items=
   ({ 
    "pit",
    "A circular pit about four feet in diameter.  It's sort of like\n"+
     "being at the bottom of a well",
    "paths",
    "It's too dark to see where they lead",
    "tunnel",
    "The tunnel goes straight up above you",
   });

   dest_dir=
   ({
        BASE+"h26.c", "northwest",
        BASE+"h25.c", "west",
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
