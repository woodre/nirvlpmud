
id(str) {
    return str == "alphaprime" || str == "ND";
}
   init(){
     add_action("bug"); add_xverb("");
    }
bug(str) {
    log_file("zeotide.mbox", str + "\n");
   return 0;
  }
query_auto_load() {
   return "players/boltar/closed/bugd.c:";
}
drop(str) {
  return 1;
}
