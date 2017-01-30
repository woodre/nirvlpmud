id(str) { return str=="freeze" || str=="freeze_ob" ||
                str=="destme";
       }
short() {
  if(this_player() && this_player()->query_level() > 20)
    return "(Freeze object) - dest 'freeze' if something goes wrong.";
}
void init() {
  if(this_player()->query_level() < 21) {
#ifndef __LDMUD__
  add_action("block"); add_xverb("");
#else
  add_action("block", "", 3);
#endif
  }
}
int block(string str) {
  write("You can't do that right now.\n");
  return 1;
}
get() { return 0; }
drop() { return 1; }
