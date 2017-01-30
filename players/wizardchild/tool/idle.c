short() { return "An auto idler"; }
long()  {
  write("Just type \"idle\" to use.\n");
}
id(str) { return str == "auto" || str == "idler" || str == "auto idler"; }
get() { return this_player()->query_level() > 20; }
init() {
  call_out("idle_cmd", 120);
}
idle_cmd() {
  if(!living(environment(this_object()))) destruct(this_object());
  command("smile", environment(this_object()));
  call_out("idle_cmd", 120);
}
