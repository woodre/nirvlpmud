 object attacker;
object target;
shadow_target(str) {
shadow(str,1);
target = str;
 attacker = this_player()->query_attack();
}
hit_player(arg) {
int real_damage;
real_damage = target->hit_player(arg);
if (real_damage > 0)
 tell_object(target, "The Frost Armor deflects some of the damage away.\n");
  return (real_damage)/4;
}
