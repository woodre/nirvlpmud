inherit "players/illarion/room";
#include "/players/illarion/dfns.h"
int chatter_loaded;

void reset(int arg) {
  if(!chatter_loaded) {
    chatter_loaded=1;
    move_object(clone_object("/players/illarion/closed/villa/beach_chat"),
      this_object());
  }
  if(arg) return;
  
  set_light(1);
  set_short("A "+HIG+"tropical"+NORM+" beach");
  set_long(
     "The waves wash gently up and down the pure white sand, playing their "
    +"nerve-soothing tune.  Along the edge of the beach, a few palm trees "
    +"stand to either side of a path leading up a hill toward a sprawling "
    +"villa to the west.  To the east, the ocean stretches off into the "
    +"distance.  To the north and south, some picturesque rocks close off "
    +"the beach into a small cove.");
  
  add_item("waves","The waves are small and gentle, washing up and down "
                  +"slowly, almost hypnotically.");
  add_item("sand","The pure white sand is pleasantly warm, and soft "
                 +"underneath your feet.");
  add_item("trees","Slightly leaning palm trees, blowing gently in the "
                  +"breeze.");
  add_item("path","A lightly-beaten path heading up the hill, between the "
                 +"trees.");
  add_item("hill","A low, large hill rising up to the west.");
  add_item("villa","A sprawling white villa covering the hill to the west.");
  add_item("ocean","Salt water, extending out to the horizion without end.");
  add_item("rocks","Some pretty, but tall and rugged rocks, that make the "
                  +"beach private.");
                  
  add_exit("villa",VILLA+"patio");
}
