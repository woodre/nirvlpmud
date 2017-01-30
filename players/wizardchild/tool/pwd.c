/* stupid replacement for the standard */
pwd() {
  write("pwd: "+this_player()->get_path()+"\n");
  return 1;
}
