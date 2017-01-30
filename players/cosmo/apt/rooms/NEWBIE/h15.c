#include "/players/cosmo/closed/ansi.h"
#define BASE "/players/cosmo/apt/rooms/NEWBIE/"
#define RATS "/players/cosmo/apt/mon/rats.c"
inherit "players/cosmo/dc/dcroom";

int rat_room_count;  /* Number of created rats in this room */

reset(arg) {
   if(arg) return;
   rat_room_count=0;
   set_light(0);
   set_sound("You hear nothing.");
   set_smell("The room is odorless (except for your own stench).");
   short_desc=BOLD+BLK+"A pathway in the darkness"+NORM;
   long_desc=BOLD+BLK+
   "It appears that you have reached a dead-end.  The east-west tunnel\n"+
   "comes to an abrupt end at this point.  You see digging marks along the\n"+
   "eastern wall, but the thick, dry red clay wall shows no sign of cracking.\n"+
   "It looks like the only exit is back west.\n"+NORM,

  items=
  ({
    "marks",
    "It looks like the earth was too solid to continue digging",
    "wall",
    "The walls are solid dirt that looks and feels like baked clay",
    "water",
    "Dirty sewer water that flows down from the north",
    "tunnel",
    "It's too dark to see where it leads",
  });

   dest_dir=
   ({
        BASE+"h14.c", "west",
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
