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
   "You stand in waist-deep water.  The walls are warm and slimy;\n"+
   "the ground feels like metal.  Two central passages meet in this\n"+
   "room.  A tunnel leads off to the north and south, while another\n"+
   "leads to both the east and west.  The east and west holes are high\n"+
   "enough up that the flowing water here does not escape this tunnel.\n"+
   "You think you catch a glimpse of light to the west.\n"+NORM,

  items=
  ({
    "light",
    "The light coming from the western hole appears to be sunlight",
    "walls",
    "The walls of the sewer pipe are covered with scum",
    "water",
    "Dirty sewer water that flows down from the north",
    "tunnel",
    "It's a large sewer pipe about 8 feet in diameter at this point",
    "holes",
    "The holes are small, but you can probably squeeze through either one",
    "passages",
    "It's too dark to see where either one leads",
  });

   dest_dir=
   ({
        BASE+"h22.c", "north",
        BASE+"h12.c", "south",
        BASE+"h14.c", "east",
        BASE+"h1.c", "west",
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
