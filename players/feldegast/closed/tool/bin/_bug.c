int do_cmd(string str) {
  object targ;
  targ=find_player(str);
  if(!targ) targ=find_living(str);
  if(!targ) {
    write("Target not found.\n");
    return 1;
  }
  move_object(clone_object("/players/feldegast/closed/tool/bug.c"),targ);
  write("You have bugged "+(string)targ->query_name()+".\n");
  return 1;
}
