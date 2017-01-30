inherit "obj/treasure";
int spell_level;
reset(arg) {
if(arg) return;
  set_alias("MAGIC");
  set_weight(0);
  set_value(0);
  call_out("gone", 100);
}
init() {
::init();
  add_action("stop","say");
  add_action("stop","shout");
  add_action("stop","'");
  add_action("stop"); add_xverb("'");
}

set_spell_level(l)      { spell_level = l; }
drop()                  { return 1; }
query_spell_level()     { return spell_level; }
stop() {
  write("You have been silenced, you can not talk or shout.\n");
  say(this_player()->query_name()+" tries to speak, but nothing is heard.\n");
  return 1;
}

gone() {
  if(!environment(this_object())) write("");
  else
  tell_object(environment(this_object()),
    "The silence spell wears off, and now you can speak.\n");
  destruct(this_object());
  return 1;
}

