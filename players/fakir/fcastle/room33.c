inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Courtyard Stable";
long_desc =
"   The courtyard stable has long rows of stalls which could\n"+
"accomodate many horses or beasts of burden.  Fresh straw and\n"+
"feed grains are pilled high against the walls, and block out\n"+
"some of the light from a window.\n";

items = ({
"stable",   "The stable of the castle courtyard",
"stalls",   "Split rail wooden stalls built sturdy and strong",
"straw",    "Dried straw grass from the flatlands, it is golden yellow in color",
"grains",   "Oats, rye, and some other mixed grains in brown burlap bags",
"walls",    "Wooden walls built against the outer castle wall, which is smooth stone",
"window",   "A four pain window of cloudy peasent glass",

});
if(!present("trolloc",this_object()))
 move_object(clone_object("/players/fakir/woods/TEMP/trolloc4.c"),this_object());

dest_dir = ({
   "/players/fakir/fcastle/room32.c", "courtyard",
   "/players/fakir/fcastle/room44.c", "stalls",
});
}


