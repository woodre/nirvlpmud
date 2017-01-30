/* Inheritable follow function. */
string entermsg, leavemsg;
set_entermsg(str) { entermsg = str; }
set_leavemsg(str) { leavemsg = str; }

heart_beat() {
  follow_it();
  ::heart_beat();
  return 1; }

follow_it() {
  object ob;
  if(!environment()) return;
  if(!entermsg) entermsg = cap_name+" enters the room.\n";
  if(!leavemsg) leavemsg = cap_name+" leaves the room.\n";
  if(attacker_ob) {
    ob = attacker_ob;
    if(environment(ob) != environment()) {
    if(creator(this_object()) == creator(environment(ob))) {
    tell_room(environment(), leavemsg);
    tell_room(environment(ob), entermsg);
    move_object(this_object(), environment(ob));
    } }
  }
  return 1;
}
