#define TO this_object()

reset(arg) {
  if(arg) return;
}

init() {
  call_out("light_damage",3);
}

light_damage() {
  int hurt;
  if(!environment() || !environment(environment()) ||
     environment(TO)->query_level() > 19 ) return; 
  hurt = set_light(0);
  if(environment(TO)->query_interactive() && !environment(TO)->query_ghost()) {
    if(hurt > 1)
      tell_object(environment(TO),"You feel the light sear your skin and flesh...\n");
    if(hurt < -1 && environment(TO)->query_mhp() != environment(TO)->query_hp())
      tell_object(environment(TO),"The soothing darkness rejuvenates your soul...\n");
    if((environment(TO)->query_hp() - hurt) > 0) {
      if(hurt > 5) hurt = 5;
      if(hurt < -5) hurt = -5;
      environment(TO)->add_hit_point(-hurt);
      environment(TO)->add_spell_point(-hurt);
    }
  }
  call_out("light_damage",3);
  return;
}
