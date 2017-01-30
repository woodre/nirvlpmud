inherit "obj/armor";

reset(arg) {
  set_name("crown");
  set_alias("jeweled crown");
  set_short("A jeweled crown");
  set_long(
    "This golden crown was likely the symbol of office for some\n"+
    "ancient emperor.  Rubies, emeralds, and saphires are set\n"+
    "into it in a gauche display of decadent wealth.  You may\n"+
    "'cash' it for its actual value.\n"
  );
  set_ac(1);
  set_type("helmet");
  set_weight(1);
  set_value(4500+random(1000));
}
init() {
  ::init();
  add_action("cmd_cash","cash");
}
cmd_cash(str) {
  if(str=="crown") {
    write("You auction the crown off for "+value+" coins.\n");
    this_player()->add_money(value);
    destruct(this_object());
    return 1;
  }
  notify_fail("Cash what?\n");
}
