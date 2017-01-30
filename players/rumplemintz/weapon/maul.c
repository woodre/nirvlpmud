inherit "obj/weapon.c";

void reset(int arg) {
  ::reset(arg);
  if(arg)
    return;
  set_name("a maul");
  set_class(13);
  set_weight(5);
  set_value(150);
  set_alias("maul");
}
