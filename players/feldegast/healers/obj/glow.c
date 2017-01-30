inherit "obj/treasure";

extra_look() {
  return environment()->query_name()+" is surrounded by a luminescent aura of light";
}
reset(arg) {
  if(arg) return;
  set_light(1);
  set_id("guild_glow");
  call_out("fade",300+random(200));
}

init() {
  add_action("fade","dim");
}
fade() {
  tell_object(environment(this_object()),
    "The luminescent glow surrounding you fades.\n");
  destruct(this_object());
  return 1;
}

get() { return 0; }
drop() { return 1; }
