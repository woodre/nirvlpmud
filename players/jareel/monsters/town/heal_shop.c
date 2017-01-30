inherit "/players/jareel/room";
#include "/players/jareel/define.h"

reset(arg) {
if(!present("sign"))  {
MOCO("/players/jareel/general_stuff/heal_shop_sign.c"),this_object()); }
if(!present("azzared"))  {
MOCO("/players/jareel/monsters/town/heal_shop_owner.c"),this_object()); }
    if(arg) return;
    set_light(1);

short_desc=("The healing salve");

long_desc=
"   You have entered a healing shop. Lining stone walls are several\n"+
"shelves and strata, each covered with multi-colored potions and\n"+
"mystical vines.  Near the rear of the store a steel box and a wood\n"+
"sign sits on the counter.  The door to the east leads back to the\n"+
"road outside.\n";

items = ({
  "shop","The potions and mystical vines line the stone walls",
  "stone","The walls are made of a solid greyish rock, it looks very hard",
  "walls","Solid stone walls are covered with potions and berries",
  "door","The old wooden door leads out to the road",
  "potion","Some dark murky fluids swirl in the bottles",
  "potions","Some dark murky fluids swirl in the bottles",
  "fluid","The fluid in the bottle seems to have a life of its own",
  "berries","The berries on the vines seem to be suspended for freshness",
  "shelves","Made of and wood, they shelves are covered with potions",
  "back wall","The counter covers the span of the wall, the shop is kept very tidy",
  "strata","Criss-crossing wood that has vines growing on them",
  "vines","Long ropes of vegitation weave around the room",
  "vine","Long ropes of vegitation weave around the room",
  "mystical vines","Long ropes of vegitation weave around the room",
  "wood","The strata appears to be made of wood",
  "box","A small box that sits on the back counter",
  "strong box","A small box that sits on the back counter",
  "counter","The counter is as long as the back wall and has a box and sign on it",
  "door","The door swings into the shop",
  "road","The road outside twists and turns through town",
});

dest_dir = ({
"/players/jareel/areas/town1/road2","east",
});
}
init() {
  ::init();
  add_action("Search","search");
}

Search(str) {
if(!str) { write("Search what?\n"); return 1; }
  write("You search the "+str+" but find nothing special.\n");
  say(this_player()->query_name()+" searches around for something.\n");
  return 1;
}
