inherit "room/room";
reset(arg) {
  if(!arg) {
  set_light(1);
    short_desc = "Rice Paddy";
    long_desc =
    "You enter the rice paddy.  Here is where the people produce their\n"+
    "daily food- rice. The rice is planted in a small area where it is marsh\n"+
    "like and well tended. You can enter the forest, go to the main path, or \n"+
    "continue in the rice.\n";
  items = ({
    "south","You see the dry path above",
    "forest","The dark forest.  Enter it with care",
    "east","The rice patties continue",
    "west","The rice patties continue",
  });

  dest_dir = ({
    "/players/mythos/aroom/path2.c", "south",
    "/players/mythos/aroom/rice2.c","west",
    "/players/mythos/aroom/forest/forest.c","forest",
    "/players/mythos/aroom/ricev.c","east",
  });
} }

init() {
  ::init();
  add_action("ssouth","south");
}

ssouth() {
  if(this_player()->query_level() > 10) {
   write("Sorry u cant go there.\n");
  return 1; }
}


/* note: the ssouth() does not return anything when 
  the player's level is less than 11 */
