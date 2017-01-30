inherit "/obj/armor.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("amulet");
  set_alias("lucky amulet");
  set_short("A lucky amulet");
  set_long(
    "This is a piece of silver jewelry fashioned into the shape\n"+
    "of a four-leaf clover.\n"
  );
  set_ac(1);
  set_type("amulet");
  set_weight(1);
  set_value(100);
}

do_special(owner) {
  if(!random(12)) {
    tell_object(owner, "You rub your amulet between your fingers for luck.\n");
    return 0; /* There's no such thing! */
  }
}
