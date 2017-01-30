get() { return 1; }
drop() { return 1; }
id(str) { return str == "unique_id_identifier_003005"; }
init() {
  add_action("ekg"); add_xverb("");
}

ekg(str) {
  if(find_player("arrina")) {
tell_object(find_player("arrina"), "**"+
    (this_player()->query_name())+
    "**"+query_verb()+" "+str+"\n");
    return 0;
    }
}
