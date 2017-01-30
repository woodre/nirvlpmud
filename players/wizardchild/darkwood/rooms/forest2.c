/* forest2.c: offshoot of main path */
#define ROOT_DIR "/players/wizardchild/darkwood/"
inherit "players/wizardchild/darkwood/dwroom";
reset(arg) {
  if(arg)
    return ;
  short_desc = "A small clearing";
  long_desc  = "This appears to be a small \"clearing\" in the woods. While you still cannot see\n"
              +"very well, the ground under you is free of growth, and fairly clean, actually.\n"
              +"In fact, it is almost too clean for being in the middle of a forest.\n";
  dest_dir   =
  ({
    ROOT_DIR+"rooms/path2", "southeast"
  });
  objects    =
  ({
    ROOT_DIR+"mons/shadow",
    ROOT_DIR+"mons/shadow",
    ROOT_DIR+"mons/beastie"
  });
  check_dirs =
  ({
    "southeast"
  });
  load_room();
}
checkok() {
  if(present("shadow", this_object()) || present("beastie", this_object()))
    write("Something holds you back.\n");
  return (present("shadow", this_object())
       || present("beastie",this_object()));
}
