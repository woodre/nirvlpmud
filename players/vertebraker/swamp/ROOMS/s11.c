#include "../define.h"
inherit SWAMP
reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_long(
"     Smoke rises clearly to the northwest, but a small grove of\n"+
"vegetation blocks immediate entrance to that side of the swamp. Small\n"+
"plants seem to rise slowly and vibrate in tune with the constant\n"+
"churning and bubbling of the swamp.\n");
   add_item("smoke","You can see smoke clearly in the northwest");
   add_item("vegetation","The grove of vegetation blocks entrance to the northwest");
   add_item("grove","The grove of vegetation blocks entrance to the northwest");
   add_item("plants","The plants appear to dance in a rhythm....");
   add_listen("churning","*pop* *plsh* *klsh*");
   add_exit(ROOMS+"s3","north");
   add_exit(ROOMS+"s12","northeast");
   add_exit(ROOMS+"s8","west");
   add_exit(ROOMS+"s38","southeast");
}
