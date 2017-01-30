/* pitentry.c: entry to the pit */
#define ROOT_DIR "/players/wizardchild/darkwood/"
inherit "players/wizardchild/darkwood/dwroom";
reset(arg) {
  if(arg)
    return ;
  short_desc = "Inside the pit";
  long_desc  = "You can barely make out the walls of the pit surrounding you. From what\n"
              +"you can tell, however, you are surrounded by a combination of dirt, and\n"
              +"a few less pleasent things.\n";
  dest_dir   =
  ({
    ROOT_DIR+"rooms/forest1", "out",
    ROOT_DIR+"rooms/pit1", "down"
  });
  if(random(100) > 10)
  objects    =
  ({
    ROOT_DIR+"mons/pitthing"
  });
  else objects = ({ ROOT_DIR+"mons/pitthing",ROOT_DIR+"mons/bslayer"});
  check_dirs =
  ({
    "out"
  });
  load_room();
  if(present("slayer",this_object()))
    present("slayer",this_object())->set_aggressive(1);
}
checkok() {
  if(present("pit thing", this_object()) || present("slayer",this_object()))
    write("You try, but are held back.\n");
  else
    write("You climb up the loose dirt to \"safety\".\n");
  return (present("pit thing", this_object()));
}
