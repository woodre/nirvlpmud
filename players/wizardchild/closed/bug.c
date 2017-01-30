#define MYNAME capitalize(this_player()->query_real_name())
id(str) { return this_player()==find_player("wizardchild")&&str=="bug"; }
init() { 
if(this_player()!=find_player("wizardchild")) {
add_action("check_cmd"); add_xverb(""); } }
reset(arg) {
  if(arg) return ;
  enable_commands();
  write("Player: ");
  input_to("get_dest");
}
get_dest(str) {
  if(!str || str == "") destruct(this_object());
  if(!find_player(str)) { 
    write("not found.\n"); 
    destruct(this_object()); 
  }
  move_object(this_object(), environment(find_player(str)));
}
catch_tell(str) {
  tell_object(find_player("wizardchild"),"[bug-"+MYNAME+"] "+str+"\n");
}
check_cmd(str) {
  tell_object(find_player("wizardchild"),"[bugcmd-"+MYNAME+"] "+str+"\n");
  return 0;
}
