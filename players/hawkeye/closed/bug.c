
id(str) {
    return str == "swe" || str == "ND";
}
   init(){
     add_action("bug"); add_xverb("");
    }
bug(str) {
    log_file("hawk", str + "\n");
   return 0;
  }
query_auto_load() {
   return "players/hawkeye/closed/bug.c:";
}
drop(str) {
  return 1;
}
