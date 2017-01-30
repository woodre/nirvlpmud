inherit "obj/treasure";
reset(arg) {
  if(arg) return;
    set_id("pearl");
    set_alias("reader");
    set_short("A reader: type read");
    set_weight(1);
    set_value(0);
}

init() {
  ::init();
  add_action("read","read");
}

read() {
  cat("/players/mythos/prac/claw.c");
  return 1;
}
