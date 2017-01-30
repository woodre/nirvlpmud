inherit "room/room";
int i;
reset(arg) {
    if(!present("cub")) {
   for(i=0;i<10;i++) {
   move_object(clone_object("/players/bagera/monster/wolfcub.c"), this_object());
   }
 }
    if(!arg) {
  set_light(0);
  short_desc=("A cave");
  long_desc=
    "You have reached the back of the cave. It is darkest here.\n"
   +"A litter of wolf cubs stand in a cluster. They bark and yelp\n"
    +"as you enter their den.\n";
  dest_dir =
   ({
   "/players/bagera/jungle/cave2.c", "north"
    });
    }


 }

