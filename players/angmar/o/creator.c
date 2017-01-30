#pragma strong_types

inherit "obj/treasure";

object master;

void
reset(status arg) {
  if (arg)
    return;
  set_name("creator");
  set_short("A palantir creator");
  set_long(
"This magical device will create communication palantirs.\n"+
"Command: palantir\n"+
"It will cost you 5 spell-points.\n");
}

int get() { return 0; }

void
init() {
  treasure::init();
  add_action("palantir","palantir");
}

void set_master(object ob) { master=ob; }

status palantir() {
  if (!master) {
    destruct(this_object());
    return 0;
  }
  if (this_player()->query_sp() < 5) {
    write("Too low on power.\n");
    return 1;
  }
  master->phone();
  this_player()->add_sp(-5);
  return 1;
}
