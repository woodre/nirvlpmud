#include "/players/eurale/closed/ansi.h"
#define Mv call_other(this_player(),"move_player"
inherit "obj/armor";
reset(arg) {
  set_name("ring");
  set_alias("shaman ring");
set_short("Shaman Ring");
  set_long(
	"This large Shaman Ring has a finely detailed dragon carved \n"+
	"into the top.  It appears to be made of black onyx and has\n"+
	"a tiny inscription scribed into it's black band that you\n"+
	"might be able to read.\n");
  set_ac(1);
  set_type("ring");
  set_weight(1);
  set_value(500);
}

init() {
  ::init();
  add_action("invoke","invoke");
  add_action("read","read"); }

read(str) {
if(!str) { write("You can't see anything.\n"); return 1; }
if(str == "inscription") {
  if(10 < random(12)) {
  write("The inscription reads... \n"+
    "To part the flames just 'invoke ring'\n");
  return 1; }
  else {
    write("You just can't seem to make it out but you could keep trying.\n");
    return 1; }
 return 1; }
}

invoke(str) {
if(!str) { write("Invoke what?\n"); return 1; }
if(str == "ring" && present("riverfire",
	environment(environment(this_object())))) {
  if(worn) { write("Remove that first!\n"); return 1; } /* verte 2.14.11 */
  write("The ring begins to glow.......\n"+
        "The flames of the river slowly part.....\n"+
        "An unseen force drags you into and beyond the flames..\n\n");
  write("\n\n\n\n\n");
  Mv,"into the flames#players/eurale/Keep/k18.c");
  destruct(this_object());
  return 1; }
else {
  /* changed to notify_fail 6.8.01 by verte */
  notify_fail("You invoke your ring and nothing occurs...\n");
  return 0; }
}
