/*
*This is a trap which hurts pkers when they enter the room.
*This shouldn't be abusable, it only hurts pkers, isn't savable, so
*there won't be enough out at one time to instakill someone, and it will
*eventually break.

*it has drawbacks of a chance to hurt the person setting it, and
*it needs to be on the ground to work, so the victim can just take
*it, then it's their trap.

*allowing you to give a set trap to someone and it do damage was intentional,
*walking around with a set trap in your invitory should be dangerous.
 */
#include "/players/jenny/define.h"
inherit "/obj/treasure.c";
int trap;
int broken;
reset(int arg) {
  if(arg) return;
  set_id("beaver trap");
set_alias("trap");
set_save_flag(1);
set_short("A beaver trap");
set_long(
"This is a metal, spring loaded trap.  It is a little over\n"+
"a foot long, with metal jaws that snap together when the\n"+
"trap is triggered.  It can easily be set and unset, though\n"+
"it is more safe to do this while the trap is on the ground.\n");
set_weight(2);
set_value(100);
}
init() {
if(random(11) > 1 && trap > 1) {
if(TP->query_pl_k() == 1 && TPL < 20){
TP->hit_player(20);
write("SNAP!  You stepped in a beaver trap.\n");
say("SNAP!  "+CAP(TPN)+" stepped in a beaver trap.\n");
trap = 1;}}
  ::init();
add_action("trap","set");
add_action("thetrap","unset");
}
trap(arg) {
if(!arg) {return 0; }
if(arg == "trap" | arg == "the trap") {
if(broken > 1) {write("The trap is broken.\n");
return 1; }
if(trap > 1) {
write("The trap is already set.\n");
return 1;}
if(trap < 2 && broken < 2) {
if(random(35) < 1) { write("A spring snaps as you try to set the trap.  It is broken now.\n");
broken = 2;
return 1; }}
if(random(STESTAT) < 1) {
write("Your hand gets snapped as you accidently trigger the trap.\n");
TP->hit_player(20);
return 1; }
write("You set the trap.\n");
trap = 2;
return 1; }}
thetrap(arg) {
if(!arg) {return 0; }
if(arg == "trap" | arg == "the trap") {
if(trap < 2) {
write("The trap is already unset\n");
return 1; }
if(trap > 1) {
write("You unset the trap.\n");
trap = 1;
return 1; }}}
