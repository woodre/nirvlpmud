/* room 3 */

#include "/players/linus/HH/hdefs.h"

inherit "/players/linus/HH/hell/main.c";

short() { return HIR + "The depths of hell" + NORM; }

reset(arg) {
 if(!arg);
 set_light(0);
 custom_exits = 1;
 long_desc = HIR +
"  Rock outcroppings form small islands throughout the lake of lava.\n"+
"Bursts of steam escape from the lake of lava that surrounds the rock\n"+
"outcropping, causing the lava to bubble dangerously.  Pieces of rock\n"+
"fall from the cavernous ceiling overhead.  Screams echo throughout\n"+
"the cavern.\n\n" + NORM;
 items = ({
"rock","A rock that protrudes from the lake of lava",
"rocks","Rocks that protrude from the lake of lava",
"outcroppings","Rocks that protrude from the lake of lava",
"outcropping","A rock that protrudes from the lake of lava",
"islands","Rocks that protrude from the lake of lava",
"island","A rock that protrudes from the lake of lava",
"lake","Molten lava",
"lava","Molten lava",
"steam","Bursts of steam emitted from the hot lava",
"bursts","Bursts of steam emitted from the hot lava",
"burst","A burst of steam emitted from the hot lava",
"ceiling","A cavernous ceiling that covers the lake of lava",
 });
 call_out("make_some_noise",1+random(25));
}

make_some_noise() {
 say("The lava bubbles up and over a nearby rock....\n");
  call_out("make_some_noise",50);
}

