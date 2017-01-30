#define LIB "players/cosmo/guild/sigil/room/library"
inherit "obj/treasure";

reset(arg) {
  if(arg) return;
  set_id("bone");
  set_short("A large white bone");
  set_long("This bone appears magical. Good luck trying to crack the code\n"+
           "that will free the bone's power.\n");
  set_value(0);
  set_info("disperse");
}

init() {
  ::init();
  add_action("crack","crack");
}

crack(str) {
  if(!str || str!="bone") {
    notify_fail("Crack what?\n");
    return 0;
  }
  if(environment()!=this_player()) {
    notify_fail("You must get it first.\n");
    return 0;
  }
  write("\tYou use all of your strength and are somehow able to snap the bone\n"+
        "\tin half. The bone suddenly disappears into a cloud of white dust.\n");
  if(environment(environment())->is_library()) {
    write("\tYou feel somewhat different.\n");
    write("\n\tA new book suddenly appears on the bookcase!\n");
    present("SIGIL_OB", this_player())->add_spell(query_info());
    present("SIGIL_OB", this_player())->save_member();
  }
  destruct(this_object());
  return 1;
}

