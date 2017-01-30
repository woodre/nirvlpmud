object target;
 
shadow_me(ob) {
  shadow(ob,1);
  target = ob;
}
 
hit_player(arg) {
  int damage;
  damage = target->hit_player(arg);
  damage=0;
  return 0;
}
