/* trail1.c: entrance to the wooded trail */
#define ROOT_DIR "/players/wizardchild/darkwood/"
inherit "players/wizardchild/darkwood/dwroom";
reset(arg) {
  if(arg)
    return ;
  short_desc = "A narrow wooded trail";
  long_desc  = "The trail, as you are suddenly realizing, is much narrower than the path that\n"
              +"you were just on. It is also much less worn, and has the appearance of being\n"
              +"used only once or twice in the past year. Ahead, the path curves to the south\n"
              +"east.\n"
              +"Slowly walking along, you can't help but feel nervous about what lies behind\n"
              +"the trails edge.\n";
  dest_dir   =
  ({
    ROOT_DIR+"rooms/path3", "north",
    ROOT_DIR+"rooms/trail2", "southeast"
  });
  objects    =
  ({
    ROOT_DIR+"mons/shadow",
    ROOT_DIR+"mons/shadow",
    ROOT_DIR+"mons/snake"
  });
  load_room();
}
