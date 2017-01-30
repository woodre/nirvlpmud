/* Orginal code from Bern's Clerics, 
   Modified to become The Knight's Templar by Boltar.
*/
string name;
object target, owner;
int told;
set_target(i) {
target = i;
name = target->short();
}
short() {
  if (!target) {
    destruct(this_object());
    return 0;
  }
  return "==>"+name+ " has been sigilized with "+
    capitalize(owner->query_name())+"'s mark";
}
set_owner(i) { owner = i; }
get() { return 0; }
drop() { return 0; }
reset(arg) {
  if (arg) return;
  told = 0;
  set_heart_beat(1);
}
heart_beat() {
  if (!target) destruct(this_object());
  if (!present(target->query_name(), environment(this_object())))
    move_object(this_object(), environment(target));
  if (target->query_attack() && target->query_attack() != owner && !told) {
    tell_object(owner, "==>"+(target->query_attack())->query_name()+" is attacking "+
                target->short()+"\n");
    told = 1;
    return 1;
  }
}
