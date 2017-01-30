int cmd_cloneall(string str)
{
  int x, y; string *fs;
  str = (string)this_player()->get_path();
  fs = get_dir(str);
  y = sizeof(fs);
  for(x=0;x<y;x++) {
    if(fs[x] && sscanf(fs[x],"%s.c",fs[x])) command("clone "+str+fs[x], this_player());
  }
  return 1;
}
