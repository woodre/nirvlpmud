#include "../define.h"
inherit SWAMP
reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_long(
"     Some sort of 'flying' fish flops out in the dank sludge-infested\n"+
"waters as you traverse its bowels and depths.  The path rises and crops\n"+
"around in a few scattered directions.\n");
   add_smell("fish","....");
   add_item("fish","Some sort of mutant carp flops out of the water");
   add_item("sludge","Your common garden variety sludge here buddy");
   add_item("path","The beaten path wraps in several directions");
   add_item("waters","You can barely see beneath its shallow depths");
   add_exit(ROOMS+"s42","west");
   add_exit(ROOMS+"s8","north");
   add_exit(ROOMS+"s45","south");
}
