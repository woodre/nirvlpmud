id(str) { return str == "reporter"; }

drop() { return 1;}

long() { write("Usage: file <string>\n"); }

init() {
  if(this_player()->query_real_name() != "snow") destruct(this_object());
add_action("filer","file");
add_action("work_report","wreport");
add_action("roomdest","roomdest");
add_action("no_life","nolife");
}

filer(str) {
  if(!str) return 0;
  write_file("/players/snow/log/CHANGE_REPORT",ctime(time())+" "+str+"\n");
  write_file("/log/WR/snow_change_report",ctime(time())+" "+str+"\n");
write("report done.\n");
return 1;}

work_report(str) {
  if(!str) return 0;
  write_file("/players/snow/log/workreport",ctime(time())+" "+str+"\n");
  write_file("/log/WR/snow_workreport",ctime(time())+" "+str+"\n");
  write("Work report filed.\n");
  return 1; }

roomdest() {
  destruct(environment(this_player())); return 1; }

no_life(string str) {
  object bob;
  bob = find_living(str);
  if(!bob) { write("Object not found.\n"); return 1; }
}
