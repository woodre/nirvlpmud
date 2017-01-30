inherit "room/room";
int i;
reset(arg) {
if(!present("rhino")) {
 for(i=0;i<8;i++) {
move_object(clone_object("/players/bagera/monster/rhino.c"), this_object());
}
  set_light(1);
  short_desc=("A meadow");
  long_desc=
    "The grass stands at least three feet tall here. A heard\n"+
    "of Rinos are grazing in the grass, chewing it to a\n"+
    "mere one inch off the ground. It looks as if a lawn\n"+
    "mower has been through here.\n";
  dest_dir=
    ({
      "/players/bagera/jungle/room25.c", "west",
      "/players/bagera/jungle/room27.c", "east",
      "/players/bagera/jungle/room34.c", "south",
      "/players/bagera/jungle/room18.c", "north"
   });
}
}
