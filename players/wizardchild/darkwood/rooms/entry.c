/* entry.c: entry room to forests */
#define ROOT_DIR "/players/wizardchild/darkwood/"
inherit "players/wizardchild/darkwood/dwroom";
reset(arg) {
  if(arg)
    return ;
  short_desc = "The entry to Darkwood";
  long_desc  = "While the area around you is still fairly light, you cannot see much further\n"
              +"into the forest. The ground feels slightly muddy, and the air much denser\n"
              +"that you are used to. Looking around, you suddenly feel alone, but not without\n"
              +"company.\n"
              +"Off towards the way you came, there appears to be a meadow.\n";
  dest_dir   =
  ({
    ROOT_DIR+"rooms/path1", "west",
     "room/forest2","north"
  });
  objects    =
  ({
    ROOT_DIR+"obj/sign",
    ROOT_DIR+"obj/ltstand",
    "/players/wizardchild/toys/doctor"
  });
  load_room();
}
