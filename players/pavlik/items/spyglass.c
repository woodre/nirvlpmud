#include "/players/pavlik/items/glass.c"
inherit "obj/treasure";

reset(arg) {
 if(arg) return;
  set_short("A Spyglass");
 set_long("A small bronze Spyglass.\n"+
      "There's something written on it.\n");
   set_weight(1);
    set_value(1100);
}
 id(str) { return str == "spyglass" || str == "glass"; }

init() {
 ::init();
 add_action("read","read");
  add_action("peek_direction","glass");
}

read(str) {
  if(str == "spyglass") {
  write("Spyglass!\n"+
   " This item lets you see into a room without ever having\n"+
   " to enter it.  Each use requires only 10 spell points.\n"+
  "To use type: glass (dir).   \n");
     return 1;
}
}
