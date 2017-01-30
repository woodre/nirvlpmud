/* approved by Mythos 4-26-2000 */


id(str) { return str == "temp_al_rev"; }

reset(arg) {
  if(arg) return;
  call_out("wear_off",40+random(60));
}

wear_off() {
object target;
  target = environment(this_object());
  if(!target) return 1;
  if(living(target)) {
    if(target->query_npc()) {
      target->set_al(-1*target->query_alignment());
      target->heal_self(10+random(41));
      tell_room(environment(target),
        "The dust wears off. "+target->query_name()+" appears invigorated!\n");
      log_file("cosmo.bizlog","** Dust wore off of "+target->query_name()+
               " at "+ctime(time())+"\n");
    }
    else {
      target->add_alignment(-2*target->query_alignment());
      tell_object(target,
        "The dust wears off and you feel normal once again.\n");
    }
  }
  destruct(this_object());
  return 1;
}

