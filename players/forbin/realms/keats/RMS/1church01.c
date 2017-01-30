#include "/players/forbin/realms/keats/keatsdefine.h"
inherit "/players/forbin/closed/std/room.c";

reset(arg) 
{
  if(arg) return;
  short_desc = HIW+"Holy Church of the Spoken Sacrament"+NORM;
  long_desc = 
    "The main artery of the city runs fairly straight here, dropping off\n"+
    "in a rather steep decline to the south, while continuing north to\n"+
    "an open space within the city.  The avenue is split in two by a\n"+
    "wide median of grass and trees and is bordered on each side by\n"+
    "cobbled sidewalks crowded with passersby.  Both sides of the\n"+
    "thoroughfare are lined with buildings, and people hurriedly go in\n"+
    "and out of them.\n";
/*    
  add_item(({"artery","avenue","avenue of word","avenue of the word","thoroughfare"}),"");
  add_item("decline","");
  add_item(({"median","grass","tree","trees"}),"");
  add_item(({"space","open space"}),"");
  add_item(({"sidewalk","sidewalks","cobbled sidewalk","cobbled sidewalks"}),"");
  add_item(({"building","buildings"}),"");
  add_item(({"people","passerby","passersby"}),"");
*/  
  add_exit(RMS+"1square.c", "leave");
  set_light(1);
}

short() 
{ 
  return HIW+"Holy Church of the Spoken Sacrament"+NORM;
}