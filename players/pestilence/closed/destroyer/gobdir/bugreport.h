filer(str) {
  if(!str) return 0;
 write_file("/players/pestilence/closed/destroyer/log/REPORTS",ctime(time())+" "+this_player()->query_name()+" is reporting "+HIW+str+NORM+"\n");
write("bug reported.\n");
return 1;}
