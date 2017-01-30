#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
#include "/players/maledicta/ansi.h"


reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "The Caves of the "+HIR+"Red "+NORM+RED+"Dragon Clan"+NORM;
long_desc =
"  This is a long glowing red tunnel.  The walls here seem to\n"+
"have small cracks throughout, allowing the heat and light\n"+
"from the flowing lava beyond to leak through. The tunnel\n"+
"continues to the east and west.\n";

items = ({
"walls",
"Black stone walls that have numerous cracks in them",
"cracks",
"Small cracks that have formed all over the surrounding walls. A\n"+
"terrible heat and light leak from within",
"light",
"Light that is created from the lava that flows from behind the\n"+
"walls",
"lava",
"A super-heated rock that flows from behind the walls",
});

dest_dir = ({
  "/players/maledicta/cont/rdragon/rooms/r5.c","east",
  "/players/maledicta/cont/rdragon/rooms/r8.c","west",
});

}

/* Thanks Feldegast for providing an easy template for messages */

int peeps;

void init() {
  ::init();
  peeps++;
  if(find_call_out("flames") == -1)
   call_out("flames", random(10) + 3);
  }

void exit() {
  peeps--;
  if(peeps <= 0)
    while(remove_call_out("flames") != -1) ;
  }

void flames() {
  object ob,next;
  string msg;

  switch(random(4)) {
    case 0: msg= HIR+"Lava"+NORM+" light flows throughout the room.\n"; break;
    case 1: msg= "Molten rock leaks from a nearby crack and oozes onto the floor.\n"; break;
    case 2: msg= "There is a light hiss as steam slips from a crack.\n"; break;
    case 3: msg= "The light flickers slightly as molten rock flows.\n"; break;
    }
  tell_room(this_object(),msg);
  call_out("flames", random(10) + 3); 
  }

