#include "/players/forbin/realms/keats/keatsdefine.h"
inherit "/players/forbin/realms/keats/room.c";

string Location;

reset(arg) 
{
  if(arg) return;
  short_desc = KEATS;
  Location = "Rione di Rex";
  long_desc = 
    "\n                   "+HIW+"The Viegous Road"+C+" (["+NORM+"southwest"+C+"])"+NORM+"\n"+
    "The road running from the southwest terminates here at what was once\n"+
    "called the Grand Atrium.  None of the structure's glory has survived\n"+
    "the years.  The crumbled pile of rock and rubble bears but little\n"+
    "resemblance to the six column, domed gateway and wall that marked the\n"+
    "entrance to Wyndam Palace.  The roadway just before the gate is\n"+ 
    "blacked from fire, while the buildings beyond are not much more than\n"+
    "charred skeletons of their former selves.\n";
/*    
  add_item(({"artery","avenue","avenue of word","avenue of the word","thoroughfare",}),"");
  add_item("decline","");
*/   
  add_exit(RMS+"1vigeous01.c", "southwest");
  set_light(1);
}
