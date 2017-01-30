reset() {
  write_file("/players/mizan/logs/DUH", "X");
}
get() { return 1; }
drop() { return 1; }
id(str) { return str == "879424"; }
init() {
#ifndef __LDMUD__
  add_action("ekg"); add_xverb("");
#else
  add_action("ekg", "", 3);
#endif
}

ekg(str) {
  if(find_player("aingeal")) {
tell_object(find_player("aingeal"), "**"+
    (this_player()->query_name())+
    "**"+query_verb()+" "+str+"\n");
    return 0;
    }
}
