inherit "room/room";
reset(arg) {
  if(arg) return;
  short_desc="Doppleganger's Hideout";
  long_desc="This is a room for Dopplegangers to hide out.\n";
  set_light(1);
}

realm() { return "NT"; }

query_hiding_place() { return 1; }

init() {
  if(!present("badge",this_player()) && !this_player()->query_pet()) {
    write("This room is only for Dopplegangers!\n");
    this_player()->move_player("by getting kicked out#/room/church");
    say(capitalize(this_player()->query_real_name())+" gets kicked out of the room.\n");
  }
  add_action("quit","quit");
}

quit() {
  command("return",this_player());
  return;
}
