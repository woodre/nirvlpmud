/* pit2.c: second part of pit */
#define ROOT_DIR "/players/wizardchild/darkwood/"
inherit "players/wizardchild/darkwood/dwroom";
reset(arg) {
  object ob;
  if(arg)
    return ;
  short_desc = "Inside the pit";
  long_desc  = "You have braved your way to the end of the pit. Unfortunately, you are now\n"
              +"virtually surrounded by creatures that you cannot see.\n"
              +"The creatures block what little light comes in here.\n";
  dest_dir   =
  ({
    ROOT_DIR+"rooms/pit1", "north"
  });
  objects    =
  ({
    ROOT_DIR+"mons/shadow",
    ROOT_DIR+"mons/snake",
    ROOT_DIR+"mons/snake",
    ROOT_DIR+"mons/pitthing2",
    ROOT_DIR+"mons/pitthing2",
    ROOT_DIR+"mons/pitthing"
  });
  check_dirs =
  ({
    "north"
  });
  if(random(100) < 11) {
  ob = clone_object(ROOT_DIR+"mons/bslayer");
  ob->set_aggressive(1);
  move_object(ob,this_object());
  }
  load_room();
}
checkok() {
  object ob;
  status nogo;
  ob = first_inventory(this_object());
  while(ob) {
    /* no kids shall escape alive */
    if(ob != this_player() && ((ob->query_ip() || ob->is_kid()) && !ob->query_ghost())) {
      nogo = 1;
      break;
    }
/* thanx bal */ ob = next_inventory(ob);
  }
  if(nogo)
    write("Something blocks the light, and you cannot find your way out.\n");
  return nogo;
}
