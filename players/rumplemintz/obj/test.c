inherit "/obj/treasure";

void reset(int arg) {
  ::reset(arg);
  if (arg)
    return;
  set_name("look_block");
  set_alias("block");
  set_short("Look blocker");
  set_long("A Look blocker, get it?\n");
  set_weight(0);
  set_value(0);
}
