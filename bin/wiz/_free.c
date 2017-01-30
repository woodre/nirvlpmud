int cmd_free(string str) {
  object obj;
  obj = environment(this_player());

  move_object(this_player(), "/room/prison");
  command("verte_clear "+str, this_player());
  move_object(this_player(), obj);
  return 1;
}
