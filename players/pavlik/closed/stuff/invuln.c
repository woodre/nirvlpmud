object target;
shadow_target(str) {
shadow(str,1);
target = str;
}
hit_player(arg) {
   int real_damage, total_damage;
real_damage = target->hit_player(arg);
  if(real_damage > 0) {
tell_object(target, "You absorb the enemy's puny attack!\n");
  call_other(target, "add_hit_point", real_damage);
return real_damage;
}
 return;
}

remove_target() {
 destruct(shadow(target, 0));
      target = 0;
}
