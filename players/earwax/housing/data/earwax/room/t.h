void reset(status arg) {
  string *files, pwd;

  int i;

  pwd = (string)this_player()->query_pwd();
  files = get_dir(pwd+"*.c");
  i = sizeof(files);
  while(i--)
  {
    write("Deleting: "+pwd+files[i]+"\n");
    rm(pwd+files[i]);
  }
}
