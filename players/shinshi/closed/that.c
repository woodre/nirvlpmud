#include "/players/mokri/define.h"

inherit "/obj/treasure.c";
reset(int arg) {
   if(arg) return;
   set_id("that");
   set_short("a that");
   set_long("blah. new_this.\n");
}

init() {
   add_action("new_this","new_this");
}

new_this() {
   destruct(present("this",TP));
   move_object(clone_object("/players/mokri/obj/this"),TP);
   return 1; }

drop() { return 1; }
