int do_cmd(string str) {
  object p_targ;
  object o_targ;
  string str1, str2;
  if(sscanf(str,"%s %s",str1,str2)!=2) {
    write("Usage: idest <player> <object>\n");
    return 1;
  }
  p_targ = find_player(str1);
  if(!p_targ) p_targ = find_living(str1);
  if(!p_targ) p_targ = find_object(str);
  if(!p_targ) {
    write("Player/Living/Object not found.\n");
    return 1;
  }
  o_targ = present(str2,p_targ);
  if(!o_targ) {
    write("There is no "+str2+" on "+(string)p_targ->query_name()+".\n");
    return 1;
  }
  destruct(o_targ);
  write("You destruct "+str2+" on "+(string)p_targ->short()+".\n");
  return 1;
}
