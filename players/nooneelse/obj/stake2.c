/*
  stake2.c - used as a poor weapon or to finish off barnabas the vampire
*/

inherit "obj/weapon";

reset(arg) {
  if (arg) return 0;
  ::reset();

  set_name("oak stake");
  set_alt_name("stake");
  set_short("A heavy oak stake");
  set_long("It is a sharp, heavy wooden stake.\n");
  set_class(9);
  set_weight(2);
  set_value(50);
}

query_save_flag() { return 1; }

id(str) { return str=="oak stake" || str=="stake" || str=="stake2" ||
                 str=="nooneelseoakstake" || str=="nooneelsestake"; }

init() {
  add_action("eat_stake", "eat");
}

eat_stake(str) {
  if (str != "stake") return 0;
  write("Oh really?  Which are you?  A termite or a beaver?\n");
  return 1;
}
