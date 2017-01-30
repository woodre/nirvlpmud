#include "/players/jenny/define.h"
inherit "/obj/treasure.c";
int trap;
reset(int arg) {
trap = 1;
  if(arg) return;
  set_id("trap");
set_alias("chicken egg");
set_short("a trap");
set_long(
"Test\n"+
"test\n"+
"test\n");
set_weight(1);
set_value(0);
}
init() {
TP->hit_player(20);
write("SNAP!\n");
  ::init();
add_action("trap","set");
}
trap(arg) {
if(!arg) {return 0; }
if(arg == "trap" | arg == "the trap") {
if(trap = 2) {
write("The trap is already set.\n");
return 1;}
if(trap = 1) {
write("You set the trap.\n");
trap = 2;
return 1; }}}
