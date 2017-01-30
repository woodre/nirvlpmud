#include "/players/linus/def.h"
inherit "/obj/treasure";
id(str) { return str=="blah" || str=="title maker"; }
reset(arg) {
  if(arg) return;
 set_short("Title tool");
 set_long("The cool title maker tool of linus\n");
}
init() {
  ::init();
  add_action("Title","set"); }
Title() {
this_player()->set_title("started out with "+RED+"nothing"+NORM+" and still has most of it left!");
this_player()->set_pretitle(" ");
destruct(TO);
return 1;
}


