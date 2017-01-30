string messages;

int do_cmd(string str) {
  mixed *msgs;
  int x;
  if(!str) {
    notify_fail("Usage: vmail <player>\n");
    return 0;
  }
  if(!restore_object("post_dir/"+str)) {
    write("That person has no mail.\n");
    return 1;
  }
  write_file((string)this_player()->query_pwd()+"mail.log", messages);
  return 1;
}
