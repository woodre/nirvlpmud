/* ahroom2.c: ant room 2 */
#define ROOT_DIR "/players/wizardchild/darkwood/"
inherit "players/wizardchild/darkwood/dwroom";
reset(arg) {
  if(arg)
    return ;
  short_desc = "The inner anthill";
  long_desc  = "You are apparently standing in a nesting site, where the queen ant has layed\n"
              +"her eggs. As you approach, more than a few other ants step between you and the\n"
              +"eggs, with intentions of defending them.\n";
  dest_dir   =
  ({
    ROOT_DIR+"rooms/ahroom1", "east"
  });
  objects    =
  ({
    ROOT_DIR+"mons/antguard",
    ROOT_DIR+"mons/antguard",
    ROOT_DIR+"mons/antguard",
    ROOT_DIR+"mons/antguard",
    ROOT_DIR+"mons/antguard",
    ROOT_DIR+"mons/ant",
    ROOT_DIR+"mons/antqueen",
    ROOT_DIR+"obj/eggs"
  });
  check_dirs =
  ({
    "east"
  });
  load_room();
}
checkok() {
  if(present("ant", this_object()))
    write("The ants block your path.\n");
  return (present("ant", this_object()));
}
