/* marks a monster that's already been hit with the bardic true_name spell
 * as it should be limited to one cast per monster.
 */

object victim;

check_for_victim() {
  if(!victim || !environment() || environment() != victim)
    call_out("goodbye",0);
}

id(str) {
  return str=="true_name_mark" || str == "prevent_monster_heal";
}

set_victim(ob) {
  victim=ob;
}

short() {
  check_for_victim();
}

drop() {
  check_for_victim();
}

void goodbye() {
  destruct(this_object());
}
