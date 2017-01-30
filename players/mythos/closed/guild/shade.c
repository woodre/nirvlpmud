object targ;

shadow_healer_on(object a) {
  if(!a) return 1; 
  targ = a;
  shadow(targ,1);
  return 1;
}

shadow_healer_off() {
  shadow(targ,0);
  return 1;
}

add_exp(arg) {
  if(this_player()->query_level() > 20 && query_ip_number(this_player())) {
    tell_object(this_player(),"Please call add_xp(#) to change experince\n");
  }
return 1; }

add_xp(int a) {
  shadow_healer_off();
  targ->add_exp(a);
  shadow_healer_on(targ);
}
