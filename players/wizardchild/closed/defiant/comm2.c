#define MYNAME() lower_case(this_player()->query_name())
#define MSGLINE() write("["+other+"]: ");
string other;
status open;
set_hail(str) { other = str; }
get() { return 1; }
short() { return "A communicator"; }
id(str) { return str == "communicator"; }
long()  {
  write("Type \"accept_hail\" to accept the hail.\n");
  return 1;
}
init()  {
  write("You must type \"accept_hail\" in 1 minute to reply.\n");
  add_action("accept_hail", "accept_hail");
  call_out("end_it", 60);
}
end_it() {
  if(open) return 0;
  tell_object(environment(this_object()), "You are no longer being hailed.\n");
  destruct(this_object());
  return 1;
}
accept_hail() {
  object ob;
  if(!(ob = present("communicator", find_player(other)))) {
    write("They are no longer hailing you.\n");
    return 1;
  }
  ob->set_open(1);
  write("You accept "+capitalize(other)+"'s hail.\n");
  write("Type \"**\" at any time to end the hail.\n");
  MSGLINE();
  input_to("msg");
  return 1;
}
msg(str) {
  if(str == "**") {
    write("You end the hail.\n");
    command("**", find_player(other));
    return 1;
  }
  write("["+MYNAME()+"]: "+str+"\n");
  tell_object(find_player(other), "["+MYNAME()+"]: "+str+"\n");
  MYNAME();
  input_to("msg");
  return 1;
}

  
