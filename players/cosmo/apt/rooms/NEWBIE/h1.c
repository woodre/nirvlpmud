#include "/players/cosmo/closed/ansi.h"
#define BASE "/players/cosmo/apt/rooms/NEWBIE/"
#define RATS "/players/cosmo/apt/mon/rats.c"
inherit "players/cosmo/dc/dcroom";

int rat_room_count;

reset(arg) {
   if(arg) return;
   rat_room_count=0;
   set_light(1);
   set_sound("You hear the distant squeaking of small rodents.");
   set_smell("It smells like a blend of moldy cheese and rotting flesh.");
   short_desc=BOLD+BLK+"Bottom of a dark hole"+NORM;
   long_desc=BOLD+BLK+
   "Damp walls surround you in what appears to be a small cave.  An\n"+
   "iron ladder meets the dirt ground here and leads upward in a small\n"+
   "tunnel dug into the earth.  Two beams of light shine down from tiny\n"+
   "holes at the top of the ladder.  An east-west passageway extends into\n"+
   "the darkness through this cave.  The air is thick with a putrid, but\n"+
   "somewhat familiar odor.\n"+NORM,

   items=
   ({ 
     "tunnel",
     "The round tunnel goes straight up into the ceiling",
     "walls",
     "The walls are wet and muddy",
     "ladder",
     "The old, creaky, iron ladder ascends straight up towards the light beams",
     "light",
     "It looks like sunlight",
     "holes",
     "The round holes are about an inch in diameter",
     "earth",
     "The ground upon which you are standing",
     "passageway",
     "It is too dark to see where it leads",
   });

   dest_dir=
   ({
        "players/cosmo/apt/rooms/hole", "up",
        BASE+"h2.c", "west",
        BASE+"h13.c", "east",
    });
}

init() {
  ::init();
  /* Make 2 rats in this room just to get things started. */
  if(rat_room_count < 1) 
     call_out("get_rat",2);
}

get_rat() {
int n;
object rat;
string msg;
   n = random(10);  /* 0-5 = small rat; 6-8 = normal rat; 9 = large rat */
   rat = RATS->make_rat(n);
   move_object(rat, this_object());
   msg = RATS->random_room_msg();
   tell_room(this_object(), msg);
   rat_room_count++;
   return 1;
}

