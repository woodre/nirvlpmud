#include <ansi.h>

inherit "room/room.c";

reset(arg)
{
  ::reset(arg);
  if(!present("new sign"))
     move_object(clone_object("/players/angel/area/mansion/obj/sign_03"), this_object());
  if(arg) return;
  set_light(0);
  short_desc = HIC+"Cavern"+NORM;
  long_desc =
" This is a dark cavern. It appears to be very deep. It is bricked\n\
like an old large water well. There is some old wood stair that\n\
spiral around the cavern and a platform controlled by a rope around\n\
a swivel bolted into a wood rafter high above. It appears the plat\n\
form is stable enough to travel up and down the cavern.\n";

items =
  ({
    "rope",
    "It appears the rope can be 'released' and 'pull'ed.",
    "bricks",
    "They are large red brick that appear to be well aged",
    "well",
    "A large water well made over 100 years ago",
    "stairs",
    "They are maid of wood bolted to the circular well.\n\
The wood is rotten!",
    "platform",
    "This is a small platform that uses a rope to lower and raise it in the well",
    "swivel",
    "A stainless steal roller to help move the platform along",
   });
  dest_dir =
  ({
    "/players/angel/area/mansion/room/billard_room_10",  "out",
  });
}

init() {
  ::init();
    add_action("release","release");
}

release(str) {
	say(capitalize(this_player()->query_name())+
    " releases the rope and the scafold drops down 50 yeards.\n");
    this_player()->move_player(
    " releases the rope and drops futher into the cavern#/players/angel/area/mansion/room/hiram_lair_03");
    say(capitalize(this_player()->query_name())+" arrives.\n");
    return 1;
}
