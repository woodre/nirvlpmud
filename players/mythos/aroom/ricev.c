inherit "room/room";
reset(arg) {
  if(!arg) {
  set_light(1);
    short_desc = "Rice PaddyV";
    long_desc =
    "You enter the rice paddy.  Here is where the people produce their \n"+
     "daily food- rice.  The rice is planted in a small area where it is \n"+
     "marsh like and well tended. To the east is the shrine that is dedicated\n"+
     "to the Gods and the Emporor. To the north is the dark forest.\n";
  items = ({
    "forest","The dark forest- much danger lurks there",
    "east","The shrine is to the east",
    "west","The rice patties continue",
  });

  dest_dir = ({
    "/players/mythos/aroom/rice.c","west",
    "/players/mythos/aroom/forest/forest2.c","forest",
    "/players/mythos/aroom/shrinear.c","east",
  });
} }
