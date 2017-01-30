inherit "obj/weapon";

init() {
  ::init();
}

reset(arg) {
  set_name("kryptonite");
  set_class(1);
  set_alias("kryptonite");
  set_id("krypto");
  set_alt_name("rock");
  set_short("kryptonite");
set_long(
  "This is a rock of green kryptonite.  If anyone should ever\n"+
  "want to kill superman, all they would have to do is 'expose\n"+
  "superman to kryptonite.'\n");
  set_value(0);
  set_weight(1);

}



