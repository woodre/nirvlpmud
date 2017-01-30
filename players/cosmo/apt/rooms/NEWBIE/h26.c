#include "/players/cosmo/closed/ansi.h"
#define BASE "/players/cosmo/apt/rooms/NEWBIE/"
#define RATS "/players/cosmo/apt/mon/rats.c"
inherit "players/cosmo/dc/dcroom";

int rat_room_count;  /* Number of created rats in this room */

reset(arg) {
   if(arg) return;
   rat_room_count=0;
   set_light(0);
   set_sound("SQUEAK SQUEAK!!");
   set_smell("P U!");
   short_desc=BOLD+BLK+"A pathway in the darkness"+NORM;
   long_desc=BOLD+BLK+
   "The air is particularly dry in this cave.  All of the paths\n"+
   "out of this room slope downward, making you feel a little\n"+
   "uneasy about leaving this room.  Darkness pervades your senses\n"+
   "as you look down the paths, particularly to the southwest.\n"+
   "There is also a small tunnel to the southeast, but unfortunately\n"+
   "the entrance is too small for you to fit in.\n"+NORM,

   items=
   ({ 
    "cave",
    "The cave is somewhat spacious, allowing you the luxury of a little stretching",
    "paths",
    "It's too dark to see where they lead",
    "tunnel",
    "Only small rodents can fit through that hole",
   });

   dest_dir=
   ({
        BASE+"h23.c", "east",
        BASE+"h27.c", "southwest",
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
