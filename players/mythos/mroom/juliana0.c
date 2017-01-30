inherit "room/room";
reset(arg) {
  if(!present("messenger")) {
    move_object(clone_object("/players/mythos/mmon/bustle.c"),this_object()); }
  if(!arg) {
  set_light(1);
    short_desc = "<<Outside Juliana's Tokyo>> ";
    long_desc =
    "                      Outside Juliana's\n"+
    "You stand just outside of Juilana's Tokyo.  Enter it to\n"+
    "feel the soul come alive with the best music of the techno\n"+
    "industry!\n";
  items = ({
    "juliana","You see the entrance to the Best Rave in Tokyo",
    "east","You see the road to ginza, the most expensive place in Tokyo",
  });

  dest_dir = ({
    "/players/mythos/mroom/juliana.c","juliana",
    "/players/mythos/mroom/ginza1.c","east",
  });
} }
