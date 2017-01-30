inherit "obj/monster";

void reset(status arg) {
  ::reset(arg);
  if (arg)
    return;
  set_name("rat");
  set_level(3);
  set_al(-10);
}
