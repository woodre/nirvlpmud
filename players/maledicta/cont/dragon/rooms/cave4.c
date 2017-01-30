#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
#include "/players/maledicta/ansi.h"

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = ""+BOLD+"The "+HIB+"Dragons"+NORM+BOLD+" Cave"+NORM+"";
long_desc =
"   This is a short, but wide, tunnel. Its walls are very\n"+
"smooth and warm to the touch. Ahead you see some sort of\n"+
"orangish light eminating from a partially open door.\n";

items = ({
  "walls",
  "The walls here are very smooth to the touch, but also\n"+
  "strangely warm",
  "light",
  "A soft light that carries heat with it",
  "door",
  "A large iron door that is partially open",
  
});

dest_dir = ({
  "/players/maledicta/cont/dragon/rooms/cave2.c","west",
  "/players/maledicta/cont/dragon/rooms/cave7.c","east",
});

}
