inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc="It is very dark, sedated, and quiet here...\n";
  no_exits=1;
}

init() {
  if(!present("singularity", this_object())) 
  move_object(clone_object("players/mizan/etheriel/environs/exploder.c"), this_object());
  ::init();
}
