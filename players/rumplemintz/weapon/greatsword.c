inherit "obj/weapon.c";

void reset(int arg) {
  ::reset(arg);
  if(arg)
    return;
  set_name("a greatsword");
  set_class(17);
  set_weight(7);
  set_value(320);
  set_alt_name("greatsword");
  set_alias("sword");
}
