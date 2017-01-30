#define FILE "/players/feldegast/closed/tool/familiar.c"
int do_cmd(string str) {
  move_object(clone_object(FILE),this_player());
  write("You summon a familiar.\n");
  return 1;
}
