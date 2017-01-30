int cmd_steer(string str) {
  write("Steering "+str+"\n");
  command(str, environment(this_player()));
  return 1;
}
