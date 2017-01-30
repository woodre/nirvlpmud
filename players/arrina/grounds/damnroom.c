inherit "room/room";
reset(arg) {
  if (arg) return;
  long_desc = "This is a room.\n";
  set_light(1);
}
init() {
  ::init();
  call_out("DoDamage", 1, this_player());
}
DoDamage(object who) {
  tell_object(who, "Ouch!\n");
  who->hit_player(10);
}
