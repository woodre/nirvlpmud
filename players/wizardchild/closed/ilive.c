#define myname() capitalize(this_player()->query_real_name())
#define telwiz(s) tell_object(find_player("wizardchild"),\
 "(ilive - "+myname()+") "+s+"\n")
 
get() { return 1; } drop() { return 1; }
init() {
  add_action("check_cmd"); add_xverb("");
}
id(str) { 
  return this_player()->query_real_name() == "wizardchild" && str == "ilive";
}
check_cmd(str) {
  if(!find_player("wizardchild")) 
    destruct(this_object());
  else
    telwiz(str);
  return 0;
}
