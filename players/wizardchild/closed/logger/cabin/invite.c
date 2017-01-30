#define CP(s) capitalize(s)
object cabin_ob;
string cabin;
status nodest;
short() { return "An invitation to "+CP(cabin)+"'s log cabin"; }
long() {
  write("Type 'visit_cabin' or 'dont_visit' to reply.\n");
  return 1;
}
id(str) { return str == "invitation" || str == "cabin_invite"; }
get() { return 1; }
set_cabin(s) { cabin = lower_case(s); }
set_cabin_ob(o) { cabin_ob = o; }
init() {
  add_action("visit_cabin", "visit_cabin");
  add_action("dont_visit", "dont_visit");
  call_out("self_dest", 100);
}
self_dest() {
  if(nodest) nodest = 0;
  else {
    write("Your invitation disintegrates.\n");
    destruct(this_object());
  }
  return 1;
}
visit_cabin() {
  if(!find_player(cabin)) {
    write("That player is no longer logged in.\n");
    self_dest();
  }
  if(environment(find_player(cabin)) != cabin_ob) {
    write("That player is no longer at their cabin.\n");
    self_dest();
  }
  write("You visit "+CP(cabin)+"'s log cabin.\n");
  move_object(this_player(), cabin_ob);
  command("look", this_player());
  nodest = 1;
  return 1;
}
dont_visit() { self_dest(); return 1; }
