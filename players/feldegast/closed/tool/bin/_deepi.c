int do_cmd(string str) {
  object *deep;
  int i;
  object targ;
  targ=find_player(str);
  if(!targ) targ=find_living(str);
  if(!targ) targ=present(str,environment(this_player()));
  if(!targ) targ=find_object(str);
  if(!targ) {
    notify_fail("That player/living/object was not found.\n");
    return 0;
  }
  write("Inventory of "+(string)targ->short()+":\n");
  deep=deep_inventory(targ);
  for(i=0; i < sizeof(deep); i++) {
    write("("+file_name(deep[i])+") "+(string)deep[i]->short()+".\n");
  }
  return 1;
}
