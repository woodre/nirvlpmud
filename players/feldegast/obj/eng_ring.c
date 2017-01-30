inherit "/obj/armor";

reset(arg) {
  set_name("silver ring");
  set_alias("ring");
  set_short("A silver ring");
  set_long(
"This is a silver engagement ring with a single word inscribed\n"+
"on the band.\n");
  set_weight(1);
  set_type("ring");
  set_value(500);
}
init() {
  ::init();
  add_action("read","read");
}
read(str) {
  if(str=="ring") {
    write("A single word is incribed on this ring: Forever.\n");
    return 1;
  }
  notify_fail("Read what?\n");
}
