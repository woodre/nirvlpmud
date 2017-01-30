inherit "obj/treasure";
#include "/players/brittany/ansi"

reset(arg) {
  set_id("globe");
set_short("A "+MAG+"Globe"+NORM);
  set_long(
"A round celestial body depicting a map.  A diagram is\n"+
"sketched on it.  Maybe you can 'spin' it.\n");
  set_weight(1000);
  set_value(0);
}
get() { return 0; }  
