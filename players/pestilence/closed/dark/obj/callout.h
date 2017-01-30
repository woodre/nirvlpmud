light_damage() {
int hurt;

if(!environment()) return 1;
if(!environment(environment()) || environment(environment())->no_light_damage()) return (call_out("light_damage", 3), 1);
hurt = set_light(0);
if(environment(TO)->query_level() < 20 &&
  !environment(TO)->query_ghost()) {

  if(hurt > 1)
  tell_object(environment(TO),
    HIR+"You feel the light scorch your flesh making it bubble...\n"+NORM);

if(hurt < -1 &&
  environment(TO)->query_mhp() != environment(TO)->query_hp())
    tell_object(environment(TO),
      HIK+"Darkness comforts your soul...\n"+NORM);
  if((environment(TO)->query_hp() - hurt) > 0) {
    if(hurt > 5) hurt = 5;
    if(hurt < -5) hurt = -5;
if(environment(TO)->query_interactive()){
    environment(TO)->add_hit_point(-hurt);
    environment(TO)->add_spell_point(-hurt);
}
  }
call_out("light_damage",3);
return 1; }
}
