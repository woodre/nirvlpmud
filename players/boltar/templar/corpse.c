/* Orginal code from Bern's Clerics, 
   Modified to become The Knight's Templar by Boltar.
*/
string name;

id(str) { return str == "body" || str == "corpse of "+name; }
set_name(i) { name = i; }
short() {
  if (name) return "Corpse of "+capitalize(name);
  return "Corpse of No one";
}
reset(arg) {
  if (arg) return;
  name = 0;
  enable_commands();
}
long() {
  write("This is the dead body of "+capitalize(name)+".\n");
}
catch_tell(str) {
  if (name)
  if(find_player(lower_case(name)))
  tell_object(find_player(lower_case(name)),str+"\n");
}
realm() { return "NT"; }
init() {
  if(this_player()) {
   if(environment(this_player())==this_object())
  add_action("blah","quit");
  }
}
blah() {
   if(environment(this_player()) != this_object()) return 0;
  command("revive",this_player());
  destruct(this_object());
  return 1;
}
