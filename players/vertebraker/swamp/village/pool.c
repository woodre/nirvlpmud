#include "../define.h"
inherit ROOM;

reset(arg) {
   if(arg) return;
   set_short("A village pathway");
   set_long(
"     A beautiful pool created by Mother Nature is here, and you can go\n"+
"for a swim if you'd like.  Tall sequoias block the area around you.\n"+
"It is a nice spot for relaxation and recreation.  The pathway\n"+
"stretches to the south.\n");
   set_light(1);
   add_item("pool","A beautiful blue pool.\nWould you like to go for a swim?\nGo ahead");
   add_item("sequoias","Tall trees that rival skyscrapers in size.\nThey are all around you");
   add_item("area","The surrounding area is a clearing blocked\nby tall sequoias");
   add_item("pathway","The path stretches back to the south");
   if(!random(2)) add_object(NPC_DIR+"villager");
   add_exit("/players/vertebraker/swamp/village/path4","south"); }

init() {
   ::init();
   add_action("swim","swim"); }

swim() {
   write("You splash around in the calm, cool waters.\n\nYou emerge minutes later, dripping wet but relaxed.\n");
   say(TPN+" splashes around in the calm, cool waters for a little while,\n and then emerges, dripping wet, but relaxed.\n");
   return 1; }
