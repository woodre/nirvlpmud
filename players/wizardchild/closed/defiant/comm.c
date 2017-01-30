#define MSGLINE() write("["+name+"]: ")
#define MYNAME()  lower_case(this_player()->query_name())
status open;
string name;
short() { return "A communicator badge"; }
long()  { 
  write("Type \"<yourname> to <someone>\" to initiate a conversation.\n");
  return 1;
}
get()   {
  return this_player()->query_real_name() == "wizardchild";
}
id(str) { 
  return str == "badge" || str == "communicator badge" || 
         str == "defiant_comm"; 
}
init()  {
  if(this_player()->query_real_name() != "wizardchild")
{
    destruct(this_object());
  return 1;
}
  add_action("comm", this_player()->query_real_name());
  add_action("special", "defiant");
  add_action("no_rescue", "no_rescue");
}
no_rescue() {
  write("You disable the auto-rescue.\n");
  "/players/wizardchild/closed/defiant/defiant"->set_no_rescue();
  return 1;
}
special(str) {
  return comm(str, 1);
}
comm(str,flag) {
  object ob,w;
  string who;
  if(!str) return 0;
  if(!sscanf(str, "to %s", who)) return 0;
  if(who == "defiant") {
    write("Hailing defiant.\n");
    if(!(ob = find_object("/players/wizardchild/closed/defiant/defiant"))) {
      write("Not found.\n");
      return 1;
    }
    ob->ship_comm("Wizardchild beams in.\n");
    say(this_player()->query_name()+" vanishes in a transporter beam.\n");
    move_object(this_object(), ob);
    write("Beaming successfull.\n");
    command("l", this_player());
    return 1;
  }
  if(!find_player(who)) {
    write("Player not found.\n");
    return 1;
  }
  w = find_player(who);
  if(w == this_player()) return 0;
  ob = clone_object("/players/wizardchild/closed/defiant/comm2");
  write("You hail "+capitalize(who)+".\n");
  write("Type \"**\" at any time to stop hailing.\n");
  name = who;
  tell_object(w, "You are hailed by "+this_player()->query_name()+".\n");
  ob->set_hail(MYNAME());
  move_object(ob, w);
  MSGLINE();
  input_to("msg");
  return 1;
}
set_open(x) { 
  open = x; 
  tell_object(environment(this_object()), "The channel has now been ");
  tell_object(environment(this_object()), (open?"opened":"closed")+".\n");
}
msg(str) {
  if(str == "**") {
    write("You close the channel.\n");
    tell_object(find_player(name), "The channel has been closed.\n");
    destruct(present("communicator", find_player(name)));
    return 1;
  }
  if(!open) {
    write("The channel is not yet open.\n");
    MSGLINE();
    input_to("msg");
  } else {
    write("["+MYNAME()+"]: "+str+"\n");
    tell_object(find_player(name), "["+MYNAME()+"]: "+str+"\n");
    input_to("msg");
  }
  return 1;
} 
