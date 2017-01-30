#pragma strong_types

inherit "obj/treasure";

void
reset(status arg) {
  if(arg)
    return;
  set_name("fishing-rod");
  set_alias("rod");
  set_short("A fishing-rod");
  set_long("Maybe you should try your luck?\n");
  set_weight(1);
  set_value(50);
}

int get() { return 1; }

void
init() {
  treasure::init();
  add_action("fish", "fish");
}

status
fish() {
  object env;
  env = environment(this_player());
  if (!(env->fish()))
     write("This does not seem like a good place for fishing.\n");
  return 1;
}
