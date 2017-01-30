/* trail2.c: continuation of the trail */
#define ROOT_DIR "/players/wizardchild/darkwood/"
inherit "players/wizardchild/darkwood/dwroom";
reset(arg) {
  if(arg)
    return ;
  short_desc = "A narrow wooded trail";
  long_desc  = "Here, it appears, the trail splits into two seperate trails. One appears to go\n"
              +"into the forest, while the other one continues on.\n"
              +"Around you, the creatures of this forest continue to set you off edge, and you\n"
              +"wonder how much longer you can stand this dark forest.\n";
  dest_dir   =
  ({
    ROOT_DIR+"rooms/trail1", "northwest",
    ROOT_DIR+"rooms/trail3", "west",
    ROOT_DIR+"rooms/trailend", "east"
  });
  objects    =
  ({
    ROOT_DIR+"mons/shadow",
    ROOT_DIR+"mons/snake",
    ROOT_DIR+"mons/shadow"
  });
  load_room();
}
