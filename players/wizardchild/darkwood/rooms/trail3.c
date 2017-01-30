/* trail3.c: trail offshoot */
#define ROOT_DIR "/players/wizardchild/darkwood/"
inherit "players/wizardchild/darkwood/dwroom";
reset(arg) {
  if(arg)
    return ;
  short_desc = "A small clearing";
  long_desc  = "You are standing in a small clearing, maybe six feet across. Above you, for the\n"
              +"first time, you can hear birds singing. Around you, there are no other monsters.\n"
              +"For the first time in this forest, you feel relaxed and comfortable.\n";
  dest_dir   =
  ({
    ROOT_DIR+"rooms/trail2", "east"
  });
  objects    =
  ({
    ROOT_DIR+"obj/rock"
  });
  load_room();
}
