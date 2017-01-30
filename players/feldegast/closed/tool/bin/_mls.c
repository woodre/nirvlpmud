int do_cmd(string str)
{
  string *dir;
  string path;
  string list;
  int i;
  if(!str) path=(string)this_player()->query_pwd();
  else path=str;
  dir=get_dir(path);
  for(i=0; i < sizeof(dir); i++)
  {
    list+=dir[i];
    list+="\t";
  }
  format(list,70);
  write("directory: "+path+"\n");
  write(list);
  write("\n");
  return 1;
}
