inherit "room/room";
int i;
reset(arg) {
  if(!present("ramos")) {
    move_object(clone_object("/players/bagera/monster/ramos.c"), this_object());
}
if(!present("wolf1")) {
    move_object(clone_object("/players/bagera/monster/wolf1.c"), this_object());
}
if(!present("wolf2")) {
    move_object(clone_object("/players/bagera/monster/wolf.c"), this_object());
move_object(clone_object("/players/bagera/monster/wolf.c"), this_object());
move_object(clone_object("/players/bagera/monster/wolf.c"), this_object());
move_object(clone_object("/players/bagera/monster/wolf.c"), this_object());
  }
 if(!arg) {
  set_light(1);
  short_desc=("The Council of Wolves");
  long_desc=
"Here is where the council of wolves meet to discuss the\n"+
"important pack issues. The ground is bare of any greenery\n"+
"and there are huge rocks formed in an almost perfect circle.\n"+
"On the largest rock stands the leader of the council, Ramos. \n"+
"Today they are discussing the survival of Mogley, the man-cub.\n"+
"Sheercon has returned to these parts of the jungle and has sworn\n"+
"to kill the man-cub. A meeting is in progress, a disicion must be\n"+
"made.\n";
  dest_dir=
    ({
      "/players/bagera/jungle/room10.c", "east",
      "/players/bagera/jungle/room1.c", "north",
      "/players/bagera/jungle/room17.c", "south"
    });
 }
}
