int do_cmd(string str) {
  object targ;
  object ob;
  notify_fail("Usage: filei <living>\n");
  if(!str) return 0;
  targ=find_player(str);
  if(!targ) find_living(str);
  if(!targ) return 0;
  ob=first_inventory(targ);
  write("--------------------------\n");
  while(ob) {
    write(file_name(ob)+"\n");
    ob=next_inventory(ob);
  }
  write("---------------------------\n");
  return 1;
}
