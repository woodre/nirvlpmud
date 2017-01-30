string last;
string msg;
short() { 
  return "A wham-o frisbee ("+(last?"from "+last:"never thrown")+")";
}
id(str) { 
  return str == "frisbee" || str == "whamo" || str == "whamo frisbee";
}
get() { return 1; }
long() {
  write("A sleek black wham-o frisbee. You instantly remember the one you had as\n");
  write("a kid. Type \"fris <player>\" to toss it to someone.\n");
  if(msg) 
    write(msg+"\n");    
  write("Type \"message <str>\" to set a new message line.\n");
  return 1;
}
init() {
  if(environment(this_object()) == this_player()) {
  add_action("toss_fris", "fris");
  add_action("new_msg", "message");
  }else destruct(this_object());
}
toss_fris(str) {
  object who;
  if(!str) {
    write("Missing something?\n");
    return 1;
  }
  who = find_player(str);
  if(!who || who->query_invis() > this_player()->query_level()) {
    write("That player is not logged in.\n");
    return 1;
  }
  if(str != "wizardchild") /* added by me */
  if(who->query_level() > 20 && this_player()->query_level() < 21) {
    write("Your respect for Wizards prevents you from throwing this at one.\n");
    return 1;
  }
  write("You curl your wrist around the frisbee and give it your best spin.\n");
  write("The frisbee spins perfectly off towards "+who->query_name()+".\n");
  say(this_player()->query_name()+" throws the fris perfectly off to "+who->query_name()+".\n");
  last = this_player()->query_name();
  move_object(this_object(), who);
  tell_object(who, "A frisbee comes flying in out of nowhere and lands gently in your hands.\n");
  tell_room(environment(who), who->query_name()+" catches an incoming frisbee.\n");
  return 1;
}
new_msg(str) {
  if(!str) {
    write("Missing something?\n");
    return 1;
  }
  msg = str;
  write("Frisbee message: "+msg+"\n");
  return 1;
}
