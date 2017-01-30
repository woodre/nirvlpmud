inherit "obj/treasure";
string direct;
string who;
reset(arg) {
if(arg) return;
  set_id("wall of thorns");
  set_alias("thorns");
  set_weight(100);
  set_long("This is a large growth of thorns and vines prevening passage.\n");
  over();
}

over() {
  call_out("gone", random(60)+20);
  return 1;
}
gone() {
  tell_room(environment(this_object()),
  "The wall of thorns starts to die and wither away.\n");
  destruct(this_object());
  return 1;
}

init() {
::init();
  add_action("stop", direct);
}
stop() {
  if(this_player()->query_real_name() != who) {
  write("A large wall of thorns prevent that exit.\n");
  return 1;
 }
}
set_direct(d) { direct = d; }
query_direct() { return direct; }
set_who(n) { who = n; }
query_who() { return who; }


