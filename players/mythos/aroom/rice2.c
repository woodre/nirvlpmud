inherit "room/room";
reset(arg) {
  if(!arg) {
  set_light(1);
    short_desc = "Rice";
    long_desc =
    "You enter the rice patty.  Here is where the people produce their \n"+
    "daily food- rice. The rice is planted in a small area where the marsh\n"+
    "encroaches.\n";
  items = ({
    "east","The rice patties continue",
  });

  dest_dir = ({
    "/players/mythos/aroom/rice.c","east",
  });
} }
