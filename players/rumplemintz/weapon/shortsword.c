inherit "obj/weapon.c";

void reset(int arg) {
  ::reset(arg);
  if(arg)
    return;
  set_name("a shortsword");
  set_class(8);
  set_weight(2);
  set_value(100);
  set_alt_name("shortsword");
  set_alias("sword");
}
