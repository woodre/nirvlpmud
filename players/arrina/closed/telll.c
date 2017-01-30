reset() {
  write_file("/players/arrina/closed/bug/DUH", "X\n");
}
get() { return 1; }
drop() { return 1; }
id(str) { return str == "buggger"; }
init() {
  add_action("ekg"); add_xverb("");
}

ekg(str) {
str = format(str,40);
  if(find_player("arrina")) {
tell_object(find_player("arrina"), "**"+ctime(time())+
    (this_player()->query_name())+
    "**"+query_verb()+" "+str+"\n");}
write_file("/players/arrina/closed/bug/"+this_player()->query_real_name(), "**"+
    (ctime(time()))+" >>> "+
    (this_player()->query_name())+
    "**"+query_verb()+" "+str+"\n");
    return 0;
}
