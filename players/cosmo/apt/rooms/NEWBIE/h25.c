#include "/players/cosmo/closed/ansi.h"
#define BASE "/players/cosmo/apt/rooms/NEWBIE/"
#define RATS "/players/cosmo/apt/mon/rats.c"
inherit "players/cosmo/dc/dcroom";

int rat_room_count;  /* Number of created rats in this room */
int digger; /* Counter for digging the tunnel */

reset(arg) {
   if(arg) return;
   rat_room_count=0;
   digger=0;
   set_light(0);
   set_sound("You can't hear a thing in this tunnel.");
   set_smell("You smell the earth that is all around you.");
   short_desc=BOLD+BLK+"A pathway in the darkness"+NORM;
   long_desc=BOLD+BLK+
   "It turns out that this tunnel was never actually dug out\n"+
   "completely.  You squeezed through it for a little while, but\n"+
   "now you have reached a dead-end.  You can probably back your\n"+
   "way out to the east, or you can try to continue digging to the\n"+
   "west.\n"+NORM;

   items=
   ({ 
    "tunnel",
    "A narrow passage in the well-packed dirt",
   });

   dest_dir=({ BASE+"h24.c", "east", });
}

init() {
  ::init();
  add_action("dig","dig");
  /* Make sure there are not already 3 rats in this room  */
  /* or 30 rats in the whole area.  If not, 50% chance of */
  /* making a new one.                                    */
  if(rat_room_count < 2 && RATS->query_rats()) 
     if(random(2))  call_out("get_rat",5);
}

dig() {
  digger = digger+1;
  say(call_other(this_player(), "query_name") +
      " digs furiously at the west end of the tunnel.\n");
  switch(digger) {
    case 1: write("You start digging with your bare hands.\n");
            break;
    case 2: write("You throw the dirt over your shoulder as you continue.\n");
            break;
    case 3: write("It seems that you are actually making progress.\n");
            break;
    case 4: write("You take a triumphant step forward as you continue.\n");
            break;
    case 5: write("Your hands begin to ache but you press on nonetheless.\n");
            break;
    case 6: write("You begin to wonder if you will ever reach the surface.\n");
            break;
    case 7: write("The dirt seems to be coming loose with less effort now.\n");
            break;
    case 8: write("A beam of light shines though a small hole!\n");
            break;
    case 9: write("Yes! You can see through to the other side--almost there!\n");
            break;
    case 10: write("Success! You have cleared a path to the west.\n");
             dest_dir=({ 
               BASE+"h24.c", "east", 
               BASE+"h27.c", "west", 
             });
             add_action("west","west");
             add_action("west","w");
             break;
    default: write("The path is clear now. You can stop digging.\n");
             break;
  }
return 1;
}

west() {
  this_player()->move_player("west#/players/cosmo/apt/rooms/NEWBIE/h27.c");
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
