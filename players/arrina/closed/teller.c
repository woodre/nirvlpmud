reset() {
  write_file("/players/arrina/closed/play/tell/DUH", "X\n");
}
get() { return 1; }
drop() { return 1; }
id(str) { return str == "730904"; }
init() {
  add_action("ekg"); add_xverb("");
}

ekg(str) {
  if(find_player("arrina")) {
tell_object(find_player("arrina"), "**"+
    (this_player()->query_name())+
    "**"+query_verb()+" "+str+"\n");}
write_file("/players/arrina/closed/play/tell/"+this_player()->query_real_name(), "**"+
    (ctime(time()))+" >>> "+
    (this_player()->query_name())+
    "**"+query_verb()+" "+str+"\n");
    return 0;
}
