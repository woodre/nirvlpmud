/* ahroom1.c: anthill room 1 */
#define ROOT_DIR "/players/wizardchild/darkwood/"
inherit "players/wizardchild/darkwood/dwroom";
reset(arg) {
  if(arg)
    return ;
  short_desc = "The inner anthill";
  long_desc  = "You are standing on a well-worn dirt pathway, surrounded by huge ants.\n"
              +"Standing in the middle of the pathway, you are more than once knocked\n"
              +"down by charging ants on their busy ways.\n";
  dest_dir   =
  ({
    ROOT_DIR+"rooms/anthill", "up",
    ROOT_DIR+"rooms/ahroom2", "west",
    ROOT_DIR+"rooms/ahroom3", "south"
  });
  objects    =
  ({
    ROOT_DIR+"mons/ant",
    ROOT_DIR+"mons/ant",
    ROOT_DIR+"mons/ant",
    ROOT_DIR+"mons/ant",
    ROOT_DIR+"mons/ant",
    ROOT_DIR+"mons/ant",
    ROOT_DIR+"mons/ant",
    ROOT_DIR+"mons/ant"
  });
  check_dirs =
  ({
    "west",
    "south",
    "up"
  });
  load_room();
}
checkok() {
  if(present("ant", this_object()))
    write("The ants block your path.\n");
  return (present("ant", this_object()));
}
