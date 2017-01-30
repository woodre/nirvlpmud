#include "/players/eurale/Maze/defs.h"
inherit "obj/treasure";
reset(arg) {
  if(arg) return;

set_id("crucifix");
set_alias("silver crucifix");
set_short("small silver crucifix");
set_alias("silver crucifix");
set_long(
	"  This tiny silver crucifix is inset with brilliant red stones \n"+
	"and sparkles like burning fire.  It has tarnished a great deal \n"+
	"and looks to be very old. \n");
    set_weight(1);
    set_value(500);
set_save_flag();
}

init() {
  ::init();
  add_action("restore","restore"); }

restore(str) {
  object ob;
ob = present("dontayne",environment(TP));
if(ob && id(str)) {
write(
  "  'You have proven yourself to be a valuable friend.  You have\n"+
  "restored the balance between good and evil and brought the \n"+
  "silver crucifix home to it's rightful place.. Thank you!\n\n"+
  "You have solved the Quest of Drygulch'..... and he wanders off.\n");
TP->set_quest("lost_rood");
destruct(ob);
destruct(TO);
return 1; }
else { write("Sorry, nothing happened... \n"); return 1; }
return 1;
}
