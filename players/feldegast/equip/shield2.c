inherit "obj/armor";

reset(arg) {
  set_name("shield");
  set_alias("steel shield");
  set_short("A steel shield");
  set_long(
    "A curved shield made out of iron plate with a nearly faded crest\n"+
    "crest on the front and a few words inscribed on the inside.\n"
  );
  set_ac(1);
  set_type("shield");  /* armor,helmet,boots,ring,amulet,shield,misc  */
  set_weight(1);
  set_value(100);
}
init() {
  ::init();
  add_action("cmd_read","read");
}
cmd_read(str) {
  if(str=="shield") {
    write("The inscription reads: No surrender, no retreat.\n");
    return 1;
  }
  notify_fail("Read what?\n");
}
