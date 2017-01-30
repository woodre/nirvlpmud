inherit "obj/weapon.c";

void reset(int arg) {
  ::reset(arg);
  if(arg)
    return;
  set_name("a longsword");
  set_class(10);
  set_weight(3);
  set_value(175);
  set_alt_name("longsword");
  set_alias("sword");
}
