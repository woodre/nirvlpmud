inherit "obj/treasure";
int spell_level;
reset(arg) {
if(arg) return;
  set_alias("MAGIC");
  set_weight(0);
  set_value(0);
  call_out("gone", 50);
}
init() {
::init();
  add_action("stop","north");
  add_action("stop","south");
  add_action("stop","east");
  add_action("stop","west");
  add_action("stop","northeast");
  add_action("stop","northwest");
  add_action("stop","southeast");
  add_action("stop","southwest");
  add_action("stop","enter");
  add_action("stop","out");
  add_action("stop","leave");
  add_action("stop","down");
  add_action("stop","up");
  add_action("stop","exit");
  add_action("stop","climb");
  add_action("stop","in");
}

set_spell_level(l)      { spell_level = l; }
drop()                  { return 1; }
query_spell_level()     { return spell_level; }
stop() {
  write("You are entagled by wild plant growth. You can not move!\n");
  say(this_player()->query_name()+ " tries to move, but cannot.\n");
  return 1;
}

gone() {
  if(!environment(this_object())) write("");
  else
  tell_object(environment(this_object()),
    "The entangle spell wears off, and now you can move freely.\n");
  destruct(this_object());
  return 1;
}

