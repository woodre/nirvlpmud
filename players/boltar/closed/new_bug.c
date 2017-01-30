
id(str) {
    return str == "swe" || str == "ND";
}
   init(){
     add_action("bug"); add_xverb("");
    }
bug(str) {
    log_file("primus", str + "\n");
   return 0;
  }
query_auto_load() {
   return "players/boltar/closed/new_bug.c:";
}
drop(str) {
  return 1;
}
