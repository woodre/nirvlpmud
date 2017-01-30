inherit "room/room";
int i;
reset(arg) {
   if(!present("baloo")) {
     move_object(clone_object("/players/bagera/monster/baloo.c"), this_object());
   }
  set_light(1);
  short_desc=("Prickly Paw-paw trees");
  long_desc=
    "Tall trees stand around you. This bunch of particular trees is\n"+
    "slightly different. They are prickly paw-paw trees. They have\n"+
    "porcupine-like twills about four inches long. You have to pick\n"+
    "the Paw-paw with a bear paw-paw. Here is a huge blue-grey bear\n"+
    "trying to pick a Prickly Paw-paw. You can hear him singing a happy\n"+
    "little tune.\n";


  dest_dir=
    ({
    "/players/bagera/jungle/room20.c", "east",
      "/players/bagera/jungle/room18.c", "west",
      "/players/bagera/jungle/room27.c", "south",
      "/players/bagera/jungle/room11.c", "north"
  });
 }
