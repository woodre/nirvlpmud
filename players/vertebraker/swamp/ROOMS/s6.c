#include "../define.h"
inherit SWAMP
reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_long(
"    Smoke rises clearly to the southeast, but a small grove of vege-\n"+
"tation blocks immediate entrance to that side of the swamp. Small\n"+
"plants seem to rise slowly and vibrate in tune with the constant\n"+
"churning and bubbling of the swamp.\n");
   add_item("smoke","You can see smoke clearly in the southeast");
   add_item("vegetation","The grove of vegetation blocks entrance to the southeast");
   add_item("grove","The grove of vegetation blocks entrance to the southeast");
   add_item("plants","The plants appear to dance in a rhythm....");
   add_listen("churning","*pop* *plsh* *klsh*");
   add_exit(ROOMS+"s22","west");
   add_exit(ROOMS+"s23","northwest");
   add_exit(ROOMS+"s2","east");
}
