inherit "/players/jareel/room";
#include "/players/jareel/define.h"

reset(arg) {
if(!present("mondar"))  {
MOCO("/players/jareel/monsters/chaos/caves/mondar.c"),this_object()); }
if(!present("joe"))  {
MOCO("/players/jareel/monsters/town/bar_shop_owner.c"),this_object()); }
if(!present("menu"))  {
MOCO("/players/jareel/general_stuff/bar_shop_menu.c"),this_object()); }
    if(arg) return;
short_desc=("The "+BOLD+RED+"Bloody"+NORM+" Axe");

long_desc=
"  On the north wall a large hearth fire is ablaze in a large stone\n"+
"fireplace.  The walls of the bar are smudged a dark crimson red. The\n"+ 
"chairs seem to have been pieced together as if they have been broken\n"+ 
"over and over again.  An eccentric menu hangs over the bar.  To the\n"+
"west a door leads to the road outside\n";

set_light( 1);

items=({
  "sign","It is a chalkboard sign with a list of drinks",
  "door","The door seems to have been ripped off the hinges a few times",
  "walls","The walls seemed to be blotched with a red color",
  "blood","Encrusted in small and large blotches on the walls",
  "wall","The walls seemed to be blotched with a red color",
  "hearth fire","The fire flickers providing warmth in the room",
  "fire","The fire flickers providing warmth in the room",
  "blaze","The fire flickers providing warmth in the room",
  "stone","The stone fireplace is a dull gray",
  "fireplace","The stone fireplace is a dull gray",
  "bar","The bar looks like it has seen many a bar fight",
  "blotches","The blotches on the wall seem to be dried blood",
  "red","The blotches on the wall seem to be dried blood",
  "chairs","The chairs have been patched together over and over again",

});
dest_dir=({
    "/players/jareel/areas/town1/road2","west",
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
