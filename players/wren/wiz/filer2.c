#define OWNER "wren"
id(str) { return str == "reporter"; }

drop() { return 1;}

short() { write("Reporter Dual\n"); }
long() { write("Usage: file <string> or gfile <string>\n"); }

init() {
  if(this_player()->query_real_name() != OWNER) destruct(this_object());
add_action("filer","file");
add_action("gfiler","gfile");
}

filer(str) {
   if(!str) return 0;
   write_file("/players/"+OWNER+"/WORK_REPORT",ctime(time())+"  "+str+"\n");
   write_file("/log/WR/"+OWNER+"_workreport",ctime(time())+"  "+str+"\n");
   write("report done.\n");
   return 1;}

gfiler(str) {
   if(!str) return 0;
   write_file("/players/wren/logs/WREN_TAMPERING",ctime(time())+"  "+str+"\n");
   write("poly report done.\n");
   return 1;}
