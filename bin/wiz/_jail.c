int cmd_jail(string str) {
  object obj;
  obj = environment(this_player());

  move_object(this_player(), "/room/prison");
  command("verte_jail "+str, this_player());
  move_object(this_player(), obj);
  return 1;
}
