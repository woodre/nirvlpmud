int do_cmd(string str) {
  string com;
  if(!str) {
    write("Usage: quick com1,com2,etc.\n");
    return 1;
  }
  write("Your motions move in a blur.\n");
  while(sscanf(str,"%s,%s",com,str)==2)
    command(com,this_player());
  command(str,this_player());
  write("Done.\n");
  return 1;
}
