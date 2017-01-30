inherit "room/room";
int i;
reset(arg) {
if(!present("louie")) {
move_object(clone_object("/players/bagera/monster/louie.c"), this_object());
}
if(!present("monkey")) {
 for(i=0;i<9;i++) {
 move_object(clone_object("/players/bagera/monster/monkey.c"), this_object());
}
 }
  set_light(1);
  short_desc=("The throne room");
  long_desc=
    "A huge stone throne sits against the far wall. It is\n"+
    "occupied by a huge arangatang named King Louie. He is\n"+
    "popping banana after banana into his mouth and tossing\n"+
    "the peelings to the ground. You see his loyal subjects\n"+
    "of monkeys all around him swinging from vines that hang\n"+
    "from the ceiling.\n";
  dest_dir=
   ({
      "/players/bagera/jungle/room52.c", "east",
      "/players/bagera/jungle/room43.c", "north"
  });
 }
   

