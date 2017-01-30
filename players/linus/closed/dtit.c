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
this_player()->set_title("the "+RED+"~"+NORM+BLU+" Ele"+NORM+GRN+"men"+NORM+HIW+"tal Dir"+NORM+GRN+"ect"+NORM+BLU+"ive"+NORM+RED+" ~"+NORM);
destruct(TO);
return 1;
}


