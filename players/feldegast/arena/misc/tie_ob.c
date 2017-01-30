inherit "/obj/treasure";

reset(arg) {
  set_short();
  set_id("tie_ob");
}
init() {
  add_action("cmd_accept","accept");
}
cmd_accept() {
  object p1,p2;
  p1=environment(this_player())->query_p1();
  p2=environment(this_player())->query_p2();
  tell_room(environment(this_player()),this_player()->query_name()+" agrees to a tie.\n");
  move_object(p1,"/players/feldegast/arena/rooms/recovery");
  command("look",p1);
  move_object(p2,"/players/feldegast/arena/rooms/recovery");
  command("look",p2);
  write("You agree to call a tie.\n");
  destruct(this_object());
  return 1;
}
drop() {
  return 1;
}
