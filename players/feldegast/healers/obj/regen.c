inherit "obj/treasure";
reset(arg) {
  if(arg) return;
  set_id("regen_ob");
  call_out("hb",3);
}
hb() {
  if(!environment()) destruct(this_object());
  if(!environment()->is_player()) destruct(this_object());
  if(interactive(environment())) {
    environment()->add_hit_point(3);
  }
  call_out("hb",random(4));
}
get() { return 0; }
drop() { return 1; }
