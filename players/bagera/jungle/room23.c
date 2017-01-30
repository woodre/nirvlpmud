inherit "room/room";
reset(arg) {
if(!present("caw")) {
move_object(clone_object("/players/bagera/monster/caw.c"), this_object());
  }
  if(!arg) {
  set_light(1);
 short_desc=("The jungle");
 long_desc=
 "Huge trees loom over head. The branches overlap one\n"+
 "another giving the appearance of no beggining and no end.\n"+
 "Thick vines hang down and drape across your path. A huge\n"+
 "snake slithers down from one of the massive branches and \n"+
 "hangs in front of your face. His eyes swirl with colors and\n"+
 "you are starting to fall into its hypnotic trance.\n";
  dest_dir=
 ({
    "/players/bagera/jungle/room31.c", "south",
    "/players/bagera/jungle/room15.c", "north",
    "/players/bagera/jungle/room24.c", "east",
    "/players/bagera/jungle/room22.c", "west"
   });
  }
}
