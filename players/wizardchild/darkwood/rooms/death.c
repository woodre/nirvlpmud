/* death.c: chosen death room */
#define ROOT_DIR "/players/wizardchild/darkwood/"
inherit "players/wizardchild/darkwood/dwroom";
status has_ghosts;
reset(arg) {
  if(arg)
    return ;
  short_desc = "The deathroom";
  long_desc  = "You have chosen to die.\n"
              +"Unfortunately for you, nobody here likes the quick easy method.\n";
  objects    =
  ({
    ROOT_DIR+"mons/bslayer",
    ROOT_DIR+"mons/bslayer",
    ROOT_DIR+"mons/bslayer",
    ROOT_DIR+"mons/bslayer",
    ROOT_DIR+"obj/tombstone"
  });
  load_room();
  make_agressive();
  call_out("check_dead",90);
  has_ghosts = 0;
}
make_agressive() {
  object ob;
  ob = first_inventory(this_object());
  while(ob) {
    if(!ob->is_player()) ob->set_aggressive(1); 
    ob = next_inventory(ob);
  }
}
check_dead() {
  object ob, nob;
  ob = first_inventory(this_object());
  has_ghosts = 0;
  while(ob) {
    nob = next_inventory(ob);
    if(living(ob) && ob->query_ghost())
if(ob->is_player()) ob->move_player("into a blinding light#/room/church");
    else if(!ob->is_player() && living(ob) && !ob->query_ghost()) break;
    if(living(ob) && ob->query_ghost() && ob->is_wiz_mons()) {
      has_ghosts = 1;
    }
    ob = nob;
  }
  if(!ob) {
    ob = first_inventory(this_object());
    while(ob) {
      nob = next_inventory(ob);
      if(has_ghosts) tell_object(ob,"The ghosts of the fallen slayers clutch at you, their etheriel limbs failing to restrain you.\n");
      tell_object(ob, "You feel a bright light shine down on you, forcing you to blink.\nWhen your eyes open, you are elsewhere.\n");
      ob->move_player("into a blinding light#/room/church");
      ob = nob;
    }
  }
  call_out("check_dead", 90);
}
