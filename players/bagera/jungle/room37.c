inherit "room/room";
int i;
reset(arg) {
 if(!present("hardy")) {
    move_object(clone_object("/players/bagera/monster/hardy.c"), this_object());
  }
if(!present("elephant")) {
     for(i=0;i<5;i++) {
    move_object(clone_object("/players/bagera/monster/elephant.c"), this_object());
  }
 }
if(!arg) {
  set_light(1);
  short_desc=("Army of elephants");
  long_desc=
    "Here is a clearing in the forest. The ground is shaking\n"+
    "violently as you see an army of elephant practicing their\n"+
    "drilling and marching.\n";
  dest_dir=
    ({
      "/players/bagera/jungle/room37a.c", "southwest",
      "/players/bagera/jungle/room38.c", "east",
      "/players/bagera/jungle/room29.c", "north"
    });
  }
}
