inherit "obj/weapon.c";

void reset(int arg) {
  ::reset(arg);
  if(arg)
    return;
  set_name("a dagger");
  set_class(7);
  set_weight(1);
  set_value(20);
  set_alt_name("dagger");
}
