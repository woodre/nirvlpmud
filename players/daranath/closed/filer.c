#define OWNER "daranath"
id(str) { return str == "reporter"; }

drop() { return 1;}

long() { write("Usage: file <string>\n"); }

init() {
  if(this_player()->query_real_name() != OWNER) destruct(this_object());
add_action("filer","file");
}

filer(str) {
  if(!str) return 0;
  write_file("/players/"+OWNER+"/WORK_REPORT",ctime(time())+"  "+str+"\n");
  write_file("/log/WR/"+OWNER+"_workreport",ctime(time())+"  "+str+"\n");
write("report done.\n");
return 1;}
