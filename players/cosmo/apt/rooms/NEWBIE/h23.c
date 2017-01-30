#include "/players/cosmo/closed/ansi.h"
#define BASE "/players/cosmo/apt/rooms/NEWBIE/"
#define RATS "/players/cosmo/apt/mon/rats.c"
inherit "players/cosmo/dc/dcroom";

int rat_room_count;  /* Number of created rats in this room */

reset(arg) {
   if(arg) return;
   rat_room_count=0;
   set_light(0);
   set_sound("A rumbling sound from the east. Could it be water?");
   set_smell("Surprisingly refreshing.");
   short_desc=BOLD+BLK+"A pathway in the darkness"+NORM;
   long_desc=BOLD+BLK+
   "This cave-like room contains a single passage to the west.  To the\n"+
   "east there is a hole high up in the wall that you could probably\n"+
   "pass though. A muffled rumble is coming from that direction.  You\n"+
   "also notice a small tunnel dug into the ground.  Some faint light\n"+
   "flickers in from the east, but you see only darkness in the other\n"+
   "directions.\n"+NORM,

   items=
   ({ 
    "light",
    "The light has a bluish tint, almost like reflected water on metal",
    "wall",
    "The walls are well-packed tunneled dirt",
    "hole",
    "The hole is small, but you can probably squeeze through it",
    "passage",
    "It's too dark to see where it leads",
    "tunnel",
    "The tunnel looks large enough for you to crawl <down> into",
   });

   dest_dir=
   ({
        BASE+"h20.c", "east",
        BASE+"h26.c", "west",
    });
}

init() {
  ::init();
  add_action("down","down");
  add_action("down","d");
  /* Make sure there are not already 3 rats in this room  */
  /* or 30 rats in the whole area.  If not, 50% chance of */
  /* making a new one.                                    */
  if(rat_room_count < 2 && RATS->query_rats()) 
     if(random(2))  call_out("get_rat",5);
}

down() {
  this_player()->move_player("down#/players/cosmo/apt/rooms/NEWBIE/h24.c");
  return 1;
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
