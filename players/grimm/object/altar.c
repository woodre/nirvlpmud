  int altar_open, flag, got_blade;
short() { }
long() { 
  write("This is a very old looking altar.\n");
}
id(str) { return str=="altar"; }
can_put_and_get() {
  return 1;
}
get() {
  return 0;
}
init() {
  add_action("look","look");
  add_action("look","exa",1);
  add_action("look","la");
  add_action("open","open");
  add_action("get_it","get");
}
look(arg) {
  if(!arg || arg != "at altar" || arg != "altar") return;
  write(long());
  return 1;
}
open(arg) {
  if(!arg || arg != "altar") return;
  if (altar_open) {
    write("The altar has already been opened.\n");
    return 1;
  }
  altar_open = 1;
  write("As you open the altar an extremely evil glow starts to grow!\n");
  write("You look in the altar and see a very strong looking blade,  the\n"+
        "blade appears to be the unholy Blade of Vampires!  Apparently,\n"+
        "long ago the high priest in the community defeated one of the more\n"+
        "powerful vampires who had this blade.  Fearing that the blade would\n"+
        "again be possessed by evil creatures he hid it in the altar, A\n"+
        "place where he knew vampires could not touch.\n");
   return 1;
}
get_it(arg) {
  object priest;
  if(!arg || arg != "blade from altar") return;
  if(!altar_open) {
    write("How can you get something out of an altar!\n");
    return 1;
  }
  if(!present("high priest") && !flag) {
    priest = clone_object("players/grimm/monster/priest");
    move_object(priest,environment(this_object()));
    write("As you try to take the evil blade the ghost of the priest appears!\n");
    flag = 1;
    return 1;
  }
  if(present("high priest")) {
    write("The priest won't let you take the blade!\n");
    return 1;
  }
  if(!got_blade) {
    move_object(clone_object("players/grimm/weapon/vamp_blade"),this_player());
    got_blade = 1;
  write("Ok.\n");
  return 1;
  }
  return 0;
}
