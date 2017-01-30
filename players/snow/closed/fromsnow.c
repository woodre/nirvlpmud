id(str) { return str == "reporter"; }

drop() { return 1;}

long() { write("Usage: file <string>\n"); }

init() {
  if(this_player()->query_real_name() != "fakir") destruct(this_object());
add_action("work_report","file");
}

work_report(str) {
  if(!str) return 0;
  write_file("/log/WR/fakir_workreport",ctime(time())+" "+str+"\n");
  write("Work report filed.\n");
  return 1; }
