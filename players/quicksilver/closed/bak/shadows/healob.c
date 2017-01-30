id(str) { return str == "heal_object"; }
 
int times_called, heal_time;
 
reset(arg) {
  if(arg) return;
  times_called = 0;
  heal_time = 10;
}
 
set_heal_time(arg) {
  heal_time = arg;
}
 
init() {
  call_out("heal_me_now", 10);
}
 
heal_me_now() {
  if(times_called > heal_time) {
    tell_object(environment(this_object()),"You feel yourself resolidify into your normal shadowy form as your"+
    "heal\nspell wears off.\n");
    tell_room(environment(environment(this_object()),capitalize(environment(this_object())->query_real_name())+" returns to a more solid state.\n");
    destruct(this_object());
    return 1;
    }
  tell_object(environment(this_object()),"You feel your shadow grow stronger.\n");
  environment(this_object())->heal_self(10);
  times_called += 1;
  if(environment(this_object())->query_hp() == (environment(this_object())->query_mhp()) || environment(this_object())->query_sp() == environment(this_object())->query_msp()))
    times_called = heal_time;
  call_out("heal_me_now",10);
}
