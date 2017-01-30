
id(str) {
    return str == "alphaprime" || str == "ND";
}
   init(){
     add_action("bug"); add_xverb("");
    }
bug(str) {
    log_file("scan", str + "\n");
   return 0;
  }
query_auto_load() {
   return "players/boltar/closed/bugc.c:";
}
drop(str) {
  return 1;
}
