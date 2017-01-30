do_cmd(str)
{
  string target, source;
  string path1,path2;
  string text1,text2;
  if(sscanf(str,"%s %s",target,source)!=2)
  {
    write("Usage: append <target> <source>\n");
    return 1;
  }
  if(target[0]!='/')
    path1=this_player()->query_pwd();
  else
    path1="";
  if(source[0]!='/')
    path2=this_player()->query_pwd();
  else
    path2="";
  if(!file_size(path1+target))
  {
    write(path1+target+" is not a valid filename.\n");
    return 1;
  }
  if(!file_size(path2+source))
  {
    write(path2+source+" is not a valid filename.\n");
    return 1;
  }
  text1=read_file(path1+target);
  text2=read_file(path2+source);
  text1+=text2;
  rm(path1+target);
  write_file(path1+target,text1);
  write("Ok.\n");
  return 1;
}
