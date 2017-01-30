/* ahroom3.c: ant room 3 */
#define ROOT_DIR "/players/wizardchild/darkwood/"
inherit "players/wizardchild/darkwood/dwroom";
reset(arg) {
  if(arg)
    return ;
  short_desc = "The inner anthill";
  long_desc  = "You are standing in what appears to be a food storage site. Many ants are\n"
              +"running back and forth through here, and more than a few are guarding a\n"
              +"passage to the east. It looks like you'll have to kill them to go any\n"
              +"further.\n";
  dest_dir   =
  ({
    ROOT_DIR+"rooms/ahroom1", "north",
    ROOT_DIR+"rooms/ahfood", "east"
  });
  objects    =
  ({
    ROOT_DIR+"mons/antguard",
    ROOT_DIR+"mons/antguard",
    ROOT_DIR+"mons/antguard",
    ROOT_DIR+"mons/ant",
    ROOT_DIR+"mons/ant",
    ROOT_DIR+"mons/antguard",
    ROOT_DIR+"obj/antfood"
  });
  check_dirs =
  ({
    "east"
  });
  load_room();
}
checkon() {
  if(present("ant", this_object()))
    write("The ant blocks your passage.\n");
  return (present("ant", this_object()));
}
