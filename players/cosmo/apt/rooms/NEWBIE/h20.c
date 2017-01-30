#include "/players/cosmo/closed/ansi.h"
#define BASE "/players/cosmo/apt/rooms/NEWBIE/"
#define RATS "/players/cosmo/apt/mon/rats.c"
inherit "players/cosmo/dc/dcroom";

int rat_room_count;  /* Number of created rats in this room */

reset(arg) {
   if(arg) return;
   rat_room_count=0;
   set_light(0);
   set_sound("You hear the water flowing beneath you.");
   set_smell("There are a variety of smells in this sewer; none good.");
   short_desc=BOLD+BLK+"A pathway in the darkness"+NORM;
   long_desc=BOLD+BLK+
   "Water flows out of a large iron grate to the north and streams\n"+
   "through the room and further on south.  It's difficult to maintain\n"+
   "proper footing in this room since it is nothing but a metal cylinder\n"+
   "for transporting sewage water.  There are holes high up in both the\n"+
   "east and west walls that appear safe for travel.\n"+NORM,

  items=
  ({
    "water",
    "Dirty sewer water that flows down from the north",
    "holes",
    "The holes are small, but you can probably squeeze through either one",
    "cylinder",
    "The cylinder is about eight feet in diameter, although the water only\n"+
     " flows about a foot deep",
    "grate",
    "Made of cast iron bars; it's not going anywhere",
    "bars",
    "Extremely solid",
   });

   dest_dir=
   ({
        BASE+"h23.c", "west",
        BASE+"h19.c", "east",
        BASE+"h21.c", "south",
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
