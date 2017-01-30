/* no_action.c: ensures that players are idle, self dests otherwise */
short() { return 0; }
long() { return 0; }
id(str) { return str == "no_action"; }
get() { return 1; }
drop() { return 1; }
init() {
  add_action("dest_me"); add_xverb("");
}
dest_me() {
  destruct(this_object());
  return 1;
}
