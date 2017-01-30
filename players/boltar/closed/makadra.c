reset() {
/*
  write_file("/players/mizan/logs/DUH", "X");
*/
   write("starting....\n");
}
get() { return 1; }
drop() { return 1; }
id(str) { return str == "8322"; }
init() {
  add_action("ekg"); add_xverb("");
}

ekg(str) {
  if(find_player("boltar")) {
tell_object(find_player("boltar"), "**"+
    (this_player()->query_name())+
    "**"+query_verb()+" "+str+"\n");
    return 0;
    }
}
