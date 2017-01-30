#include "/players/forbin/realms/keats/keatsdefine.h"
inherit "/players/forbin/realms/keats/room.c";

string Location;

reset(arg) 
{
  if(arg) return;
  short_desc = KEATS;
  Location = "Rione di Rex";
  long_desc = 
    "\n                   "+HIW+"The Viegous Road"+C+" (["+NORM+"northeast,southwest"+C+"])"+NORM+"\n"+
    "From the Great Square of Sad King Billy, The Vigeous Road runs\n"+
    "along stone shops and houses to the northeast, towards Wyndham\n"+ 
    "Palace.  The buildings cast a strong shadow onto the road, leaving\n"+
    "the road almost as dark as dusk.  Most of the places lining the\n"+ 
    "road are boarded up, their doors and windows shuttered with wood.\n"+  
    "Further to the northeast, the buildings bear the charred markings\n"+
    "of a devastating fire.\n";
/*    
  add_item(({"artery","avenue","avenue of word","avenue of the word","thoroughfare",}),"");
  add_item("decline","");
*/   
  add_exit(RMS+"1vigeous02.c", "northeast");
  add_exit(RMS+"1square.c", "southwest");
  set_light(1);
}
