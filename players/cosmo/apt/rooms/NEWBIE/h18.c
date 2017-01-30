#include "/players/cosmo/closed/ansi.h"
#define BASE "/players/cosmo/apt/rooms/NEWBIE/"
#define RATS "/players/cosmo/apt/mon/rats.c"
inherit "players/cosmo/dc/dcroom";

int rat_room_count;  /* Number of created rats in this room */

reset(arg) {
   if(arg) return;
   rat_room_count=0;
   set_light(0);
   set_sound("An eerie silence pervades your senses.");
   set_smell("A dirty damp odor fills the air.");
   short_desc=BOLD+BLK+"A pathway in the darkness"+NORM;
   long_desc=BOLD+BLK+
   "It's hard to even call this a room.  It's more of a slim\n"+
   "crevice in the earth.  A trickle of water flows to the south,\n"+
   "but quickly dries up in the crusty dirt.  The air is heavy,\n"+
   "making breathing difficult.  There appears to be a little more\n"+
   "space to move either to the north or south.\n"+NORM,

  items=
  ({
    "air",
    "You smell it but you can't see it",
    "crevice",
    "The narrow opeing that you are standing in",
    "water",
    "You can't find the source of the water",
    "dirt",
    "The muddy dirt absorbs all of the water",
  });

   dest_dir=
   ({
        BASE+"h19.c", "north",
        BASE+"h17.c", "south",
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
