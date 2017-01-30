filer(str) {
  if(!str) return 0;
  write_file("/players/pestilence/closed/dark/REPORTS",ctime(time())+" "+this_player()->query_name()+" is reporting " +str+"\n");
write("bug reported.\n");
return 1;}
