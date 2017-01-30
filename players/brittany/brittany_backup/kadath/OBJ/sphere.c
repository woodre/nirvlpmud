inherit "obj/treasure";
#include "/players/brittany/ansi"

reset(arg) {
  set_id("sphere");
set_short("A "+MAG+"Sphere"+NORM);
  set_long(
"A round celestial body depicting a map.  A diagram is\n"+
"sketched on the map.  Maybe you can 'spin' it somewhere.\n");
  set_weight(1000);
  set_value(0);
}
get() { return 0; }  
