/* trailend.c: end of the trail */
#define ROOT_DIR "/players/wizardchild/darkwood/"
inherit "players/wizardchild/darkwood/dwroom";
reset(arg) {
  if(arg)
    return ;
  short_desc = "The end of the trail";
  long_desc  = "The trail has narrowed itself to nonexistence.\n"
              +"Within five feet of where you are standing, the trail ends, right at the base of\n"
              +"a tree. Unfortunately for you, there is no clue as to why that is.\n"
              +"You will have to walk back all that way.\n";
  dest_dir   =
  ({
    ROOT_DIR+"rooms/trail2", "west"
  });
  objects    =
  ({
    ROOT_DIR+"mons/snake",
    ROOT_DIR+"obj/tree"
  });
  load_room();
}
