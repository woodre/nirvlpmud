#define TP environment(this_object())
int heal_time, times_called;
 
id(str) { return str == "heal_object"; }

drop() { destruct(this_object()); return 0; }
 
set_healtime(arg) { heal_time = arg; }
 

reset(arg) {
  if(arg) return;
  heal_time = 5;
  times_called = 0;
}
 
init() {
  add_action("no_heal_me","stop_heal");
  call_out("heal_shadow", 15);
}

no_heal_me() {
  write("You return to a more solid state.\n");
  say(capitalize(TP->query_name())+" returns to a more solid state.\n");
  destruct(this_object());
  return 1;
}

 
bad_guy() {
  tell_object(this_player(),"You cannot attack while healing.\n");
  return 1;
}
heal_shadow() {
  if(TP->query_sp() == TP->query_msp() && TP->query_hp() == TP->query_mhp()) {
    tell_object(TP,"You feel your body return to its original form.\n");
    tell_room(environment(TP),"You see "+capitalize(TP->query_real_name())+" return to a more solid state.\n");
    destruct(this_object());
    return 1;
    }
  if(times_called >= heal_time) {
    tell_object(TP,"You feel your body return to its original form.\n");
    tell_room(envrionment(this_player()),"You see "+capitalize(this_player()->query_name())+" return to a more solid state.\n");
    destruct(this_object());
    return 1;
    }
  tell_object(TP,"You feel your shadow grow stronger by the moment.\n");
  TP->heal_self(10);
  times_called++;
  call_out("heal_shadow", 15);
}
  

