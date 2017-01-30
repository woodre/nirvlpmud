/* ahfood.c: backroom */
#define ROOT_DIR "/players/wizardchild/darkwood/"
inherit "players/wizardchild/darkwood/dwroom";
reset(arg) {
  if(arg)
    return ;
  short_desc = "The ants' storage room";
  long_desc  = "The entrance to this part of the anthill was narrow, but you managed to enter.\n"
              +"You are standing in what appears to be a storage room for the ants' food supply.\n"
              +"On the ground around you, there are multiple piles of what appears to be dead\n"
              +"insects of various sorts. You are probably not welcome here.\n";
  dest_dir   =
  ({
    ROOT_DIR+"rooms/ahroom3", "west"
  });
  objects    =
  ({
    ROOT_DIR+"mons/antguard",
    ROOT_DIR+"mons/antguard",
    ROOT_DIR+"obj/antfood",
    ROOT_DIR+"mons/antguard",
    ROOT_DIR+"obj/antfood",
    ROOT_DIR+"obj/antfood",
    ROOT_DIR+"obj/ant",
    ROOT_DIR+"obj/antfood",
    ROOT_DIR+"mons/antguard",
    ROOT_DIR+"obj/antfood",
    ROOT_DIR+"mons/antguard",
    ROOT_DIR+"mons/antguard"
  });
  check_dirs =
  ({
    "west"
  });
  load_room();
}
init() {
  ::init();
  add_action("check_take", "get");
  add_action("check_take", "take");
}
checkok() {
  if(present("ant", this_object()))
    write("The ants block your way.\n");
  return (present("ant", this_object()));
}
check_take(str) {
  object ob = present("food", this_object());
  if(ob && ob->id(str) && present("ant", this_object())) {
    write("You reach for the food, but are stopped short by an ant.\n");
    return 1;
  }
  return 0;
}
