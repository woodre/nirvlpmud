string str;
set_string(s) { str = s; }
id(str) { return str == "hickey"; }
long() {
  write(str+"\n");
  write("(Type \"rub hickey\" to get rid of it)\n");
}
init() {
  call_out("self_dest", 600);
  add_action("rub","rub");
}
get() { return 1; }
drop() { return 1; }
self_dest() {
  tell_object(environment(),"The hickey fades away.\n");
  destruct(this_object());
}
rub(str) {
  if(str != "hickey") return 0;
  write("You rub the hickey with determination.\n");
  say(this_player()->query_name()+" rubs off their hickey.\n");
  return self_dest() || 1;
}
extra_look() {
  return str;
}
