/* path3.c: path w/ cabin */
#define ROOT_DIR "/players/wizardchild/darkwood/"
inherit "players/wizardchild/darkwood/dwroom";
reset(arg) {
  if(arg)
    return ;
  short_desc = "A dark pathway";
  long_desc  = "You have apparently struck it lucky. Standing here next to the path is\n"
              +"a small wooden shack, with what appears to be a fire going inside.\n"
              +"Though you cannot be sure, you think you hear something moving inside.\n"
              +"Ahead, the path turns to the north, with a small trail leading into the\n"
              +"darkness of the woods.\n";
  dest_dir   =
  ({
    ROOT_DIR+"rooms/path2", "east",
    ROOT_DIR+"rooms/path4", "north",
    ROOT_DIR+"rooms/trail1", "south"
  });
  objects    =
  ({
    ROOT_DIR+"obj/wsign",
    ROOT_DIR+"mons/rat",
    ROOT_DIR+"obj/shack"
  });
  load_room();
}
