/* pit1.c: inside the pit */
#define ROOT_DIR "/players/wizardchild/darkwood/"
inherit "players/wizardchild/darkwood/dwroom";
reset(arg) {
  object ob;
  if(arg)
    return ;
  short_desc = "Inside the pit";
  long_desc  = "You can now tell that the area around you was once a mine of some\n"
              +"sort. Since that time, however, some \"things\" have taken residence\n"
              +"here. It looks like they haven't eaten in quite a while, making you a\n"
              +"appetizing visitor.\n";
  dest_dir   =
  ({
    ROOT_DIR+"rooms/pitentry", "up",
    ROOT_DIR+"rooms/pit2", "south"
  });
  objects    =
  ({
    ROOT_DIR+"mons/pitthing",
    ROOT_DIR+"mons/pitthing",
    ROOT_DIR+"mons/pitthing2",
    ROOT_DIR+"mons/pitthing2",
    ROOT_DIR+"mons/shadow",
    ROOT_DIR+"mons/pitthing2",
    ROOT_DIR+"mons/pitthing2",
    ROOT_DIR+"mons/pitthing2"
  });
  check_dirs =
  ({
    "up",
    "south"
  });
if(random(100) < 11) {
ob = clone_object(ROOT_DIR+"mons/bslayer");
ob->set_aggressive(1);
move_object(ob,this_object());
}
  load_room();
}
checkok() {
  if(present("pit thing",this_object()) || present("slayer",this_object()))
    write("The thing prevents you from leaving.\n");
  return (present("pit thing", this_object()));
}
